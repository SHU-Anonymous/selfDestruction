//
// Created by 李欣 on 2017/7/10.
//

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

#define MAX_LINE 100

void *threadSend(void *varGroup);

void *threadReceive(void *varGroup);

int main(int argc, char *argv[]) {
    int *clientFDP;
    clientFDP = (int *) malloc(sizeof(int));
    *clientFDP = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    struct hostent *hostEntry;
    memset((char *) &serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(5005);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(*clientFDP, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("Connection Error");
        exit(1);
    }
    pthread_t threadIdSend, threadIdReceive;
    printf("Connection Established");
    while (1) {
        pthread_create(&threadIdSend, NULL, threadSend, clientFDP);
        pthread_create(&threadIdReceive, NULL, threadReceive, clientFDP);
    }
    return EXIT_SUCCESS;
}

void *threadSend(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    int iData;
    char temp[100];
    while (1) {
        fgets(temp, 100, stdin);
        send(connectionFD, temp, 100, 0);
    }
}

void *threadReceive(void *varGroup) {
    char temp[100];
    int connectionFD = *((int *) varGroup);
    while (1) {
        int iData = 0;
        iData = recv(connectionFD, temp, 100, 0);
        if (iData > 0) {
            printf("Instruction :\n%s", temp);
        }
    }
}