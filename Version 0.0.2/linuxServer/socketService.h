//
// Created by 李欣 on 2017/7/11.
//

#ifndef LINUXSERVER_SOCKETSERVICE_H
#define LINUXSERVER_SOCKETSERVICE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

class socketService {
private:
    int _listenFD;
    struct sockaddr_in _serverAddress;
    struct sockaddr_in _clientAddress;
    socklen_t _clientLength;
    int *_connectFDP;
public:
    socketService();

    ~socketService();

    void setPort(int Port);

    void bindSocket();

    void listenClient();

    void acceptClient();
};

void *threadMain(void *varGroup);

void *threadSend(void *varGroup);

void *threadReceive(void *varGroup);

#endif //LINUXSERVER_SOCKETSERVICE_H
