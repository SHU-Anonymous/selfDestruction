//
// Created by 李欣 on 2017/7/12.
//

#ifndef SOCKETCOMBINED_H
#define SOCKETCOMBINED_H

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

class socketCombined {
private:
    int _listenFD;
    struct sockaddr_in _serverAddress;
    struct sockaddr_in _clientAddress;
    socklen_t _clientLength;
    int *_connectFDP;
public:
    socketCombined();

    ~socketCombined();

    void setPort(int Port);

    void setServer(const char *Address);

    void bindSocket();

    void connectServer();

    void listenClient();

    void acceptClient();

    bool threadSend(const char *buffer);

    bool threadRecieve(char *buffer);
};


#endif //SOCKETCOMBINED_H
