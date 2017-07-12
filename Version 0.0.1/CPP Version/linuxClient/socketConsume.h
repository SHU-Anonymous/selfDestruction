//
// Created by 李欣 on 2017/7/11.
//

#ifndef LINUXCLIENT_SOCKETCONSUME_H
#define LINUXCLIENT_SOCKETCONSUME_H

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

class socketConsume {
private:
    int *_clientFDP;
    struct sockaddr_in _serverAddress;
public:
    socketConsume();

    ~socketConsume();

    void setPort(int Port);

    void setServer(const char *Address);

    void connectServer();

    bool threadSend(const char *buffer);

    bool threadReceive(char *buffer);
};

#endif //LINUXCLIENT_SOCKETCONSUME_H
