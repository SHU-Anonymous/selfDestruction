//
// Created by 李欣 on 2017/7/11.
//

#include "socketConsume.h"

socketConsume::socketConsume() {
    _clientFDP = (int *) malloc(sizeof(int));
    *_clientFDP = socket(PF_INET, SOCK_STREAM, 0);
    memset((char *) &_serverAddress, 0, sizeof(_serverAddress));
    _serverAddress.sin_family = PF_INET;
}

socketConsume::~socketConsume() {
    shutdown(*_clientFDP, SHUT_RDWR);
}

void socketConsume::setPort(int Port) {
    _serverAddress.sin_port = htons(Port);
}

void socketConsume::setServer(const char *Address) {
    _serverAddress.sin_addr.s_addr = inet_addr(Address);
}

void socketConsume::connectServer() {
    if (connect(*_clientFDP, (struct sockaddr *) &_serverAddress, sizeof(_serverAddress)) < 0) {
        perror("Connection Error");
        exit(2);
        // 2 stands for Connection Error
    }
    std::cout << "\033[1;32m" << "[+] Connection Established" << "\033[0m" << std::endl;
}

bool socketConsume::threadSend(const char *buffer) {
    return send(*_clientFDP, buffer, 100, 0) >= 0;
}

bool socketConsume::threadReceive(char *buffer) {
    return recv(*_clientFDP, buffer, 100, 0) >= 0;
}