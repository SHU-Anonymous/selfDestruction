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

#define MAXLINE 100

void *threadSend(void *varGroup);

void *threadReceieve(void *varGroup);

int main(int argc, char *argv[]) {
    int *clientFDP;
    clientFDP = (int *) malloc(sizeof(int));
    *clientFDP = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    struct hostent *hostEntry;
    memset((char *) &serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(5005);
    serverAddress.sin_addr.s_addr = inet_addr("192.168.110.101");
    if (connect(*clientFDP, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        printf("Connection Error\n");
        exit(1);
    }
    pthread_t threadIdSend, threadIdReceive;
    printf("Connection Succeeded\n");
    while (1) {
        pthread_create(&threadIdSend, NULL, threadSend, clientFDP);
        pthread_create(&threadIdReceive, NULL, threadIdReceive, clientFDP);
    }
    return EXIT_SUCCESS;
}

void *threadSend(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    int idata;
    char temp[100];
    while (1) {
        fgets(temp,100,)
    }
}