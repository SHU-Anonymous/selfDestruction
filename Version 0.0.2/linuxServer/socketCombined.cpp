//
// Created by 李欣 on 2017/7/12.
//

#include "socketCombined.h"

socketCombined::socketCombined() {
    _listenFD = socket(PF_INET, SOCK_STREAM, 0);
    if (_listenFD < 0) {
        perror("\033[1;31m[-] Socket Error\033[0m");
        exit(1);
        // 1 stands for Socket Error
    }
    _clientLength = sizeof(_clientAddress);
    _connectFDP = (int *) malloc(sizeof(int));
    *_connectFDP = socket(PF_INET, SOCK_STREAM, 0);
    memset((char *) &_serverAddress, 0, sizeof(_serverAddress));
    _serverAddress.sin_family = PF_INET;
}

socketCombined::~socketCombined() {
    shutdown(*_connectFDP, SHUT_RDWR);
    shutdown(_listenFD, SHUT_RDWR);
}

void socketCombined::setPort(int Port) {
    _serverAddress.sin_port = htons(Port);
}

void socketCombined::setServer(const char *Address) {
    _serverAddress.sin_addr.s_addr = inet_addr(Address);
}

void socketCombined::bindSocket() {
    if (bind(_listenFD, (struct sockaddr *) &_serverAddress, sizeof(_serverAddress)) < 0) {
        perror("\033[1;31m[-] Connection Error\033[0m");
        exit(2);
        // 2 stands for Connection Error
    }
}

void socketCombined::connectServer() {
    if (connect(*_connectFDP, (struct sockaddr *) &_serverAddress, sizeof(_serverAddress)) < 0) {
        perror("Connection Error");
        exit(2);
        // 2 stands for Connection Error
    }
    std::cout << "\033[1;32m" << "[+] Connection Established" << "\033[0m" << std::endl;
}

void socketCombined::listenClient() {
    if (listen(_listenFD, 1024) < 0) {
        // supports up to 1024 clients
        perror("\033[1;31m[-] Listen Error\033[0m");
        exit(3);
        // 3 stands for Listen Error
    }
}

void socketCombined::acceptClient() {
    while ((*_connectFDP = accept(_listenFD, (struct sockaddr *) &_clientAddress, &_clientLength)) >= 0) {
        std::cout << "\033[1;32m" << "[+] Connection Accepted From: " << inet_ntoa(_clientAddress.sin_addr) << "\033[0m"
                  << std::endl;
    }
}

bool socketCombined::threadSend(const char *buffer) {
    return send(*_connectFDP, buffer, 100, 0) >= 0;
}

bool socketCombined::threadReceive(char *buffer) {
    return recv(*_connectFDP, buffer, 100, 0) >= 0;

}
