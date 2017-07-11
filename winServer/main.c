//#include <stdio.h>
//#include <stdlib.h>
//#include <errno.h>
//#include <string.h>
//#include <unistd.h>
//#include <windows.h>
//#include <winsock.h>
//#include <winsock2.h>
//#include <sys/types.h>
//#include <pthread.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5005


void *thread(void *varGroup);

void *threadSend(void *varGroup);

void *threadReceive(void *varGroup);

int main(int argc, char *argv[]) {

    int listenFD = socket(PF_INET, SOCK_STREAM, 0);
    // Listen File Descriptor
    if (listenFD < 0) {
        perror("Socket Error");
        exit(1);
    }

    struct hostent *hostEntry;
    struct sockaddr_in serverAddress;
    memset((char *) &serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = PF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(PORT);

    if (bind(listenFD, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("Connection Error");
        exit(1);
    }

    if (listen(listenFD, 1024) < 0) {
        perror("Listen Error");
        exit(1);
    }

    // char temp[100];
    struct sockaddr_in clientAddress;
    int clientLength, *connectFDP;
    clientLength = sizeof(clientAddress);
    while (1) {
        connectFDP = (int *) malloc(sizeof(int));
        *connectFDP = accept(listenFD, (struct sockaddr *) &clientAddress, &clientLength);
        pthread_t threadId;
        printf("Connection Accepted\n");
        pthread_create(&threadId, NULL, thread, connectFDP);
    }
    EXIT_SUCCESS;
}

void *thread(void *varGroup) {
    pthread_t threadIdSend, threadIdReceive;
    int connectionFD = *((int *) varGroup);
    int iData;
    char temp[100];
    pthread_create(&threadIdSend, NULL, threadSend, varGroup);
    pthread_create(&threadIdReceive, NULL, threadReceive, varGroup);
}

void *threadSend(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    int iData;
    char temp[100];
    while (1) {
        printf("Instruction: ");
        fgets(temp, 100, stdin);
        send(connectionFD, temp, 100, 0);
    }
}

void *threadReceive(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    char temp[100];
    while (1) {
        int iData = 0;
        iData = recv(connectionFD, temp, 100, 0);
        if (iData > 0) {
            printf("Respond: \n%s\n", temp);
        }
    }
}