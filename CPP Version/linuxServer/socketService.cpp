//
// Created by 李欣 on 2017/7/11.
//

#include "socketService.h"

socketService::socketService() {
    _listenFD = socket(PF_INET, SOCK_STREAM, 0);
    if (_listenFD < 0) {
        perror("\033[1;31m[-] Socket Error\033[0m");
        exit(1);
        // 1 stands for Socket Error
    }
    memset((char *) &_serverAddress, 0, sizeof(_serverAddress));
}

socketService::~socketService() {
    close(*_connectFDP);
}

void socketService::setPort(int PORT) {
    _port = PORT;
}

void socketService::bindSokcet() {
    _serverAddress.sin_family = PF_INET;
    _serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    _serverAddress.sin_port = htons(_port);
    if (bind(_listenFD, (struct sockaddr *) &_serverAddress, sizeof(_serverAddress)) < 0) {
        perror("\033[1;31m[-] Connection Error\033[0m");
        exit(2);
        // 2 stands for Connection Error
    }
}

void socketService::listenClient() {
    if (listen(_listenFD, 1024) < 0) {
        // supports up to 1024 clients
        perror("\033[1;31m[-] Listen Error\033[0m");
        exit(3);
        // 3 stands for Listen Error
    }
}

pthread_t _threadIdMain, _threadIdSend, _threadIdReceive;

void *threadMain(void *varGroup);

void *threadSend(void *varGroup);

void *threadReceive(void *varGroup);

void socketService::acceptClient() {
    _clientLength = sizeof(_clientAddress);
    while (true) {
        _connectFDP = (int *) malloc(sizeof(int));
        *_connectFDP = accept(_listenFD, (struct sockaddr *) &_clientAddress, &_clientLength);
        std::cout << "\033[1;32m" << "[+] Connection Accepted" << "\033[0m" << std::endl;
        getchar();
        pthread_create(&_threadIdMain, NULL, threadMain, _connectFDP);
    }
}

void *threadMain(void *varGroup) {
    pthread_create(&_threadIdSend, NULL, threadSend, varGroup);
    pthread_create(&_threadIdReceive, NULL, threadReceive, varGroup);
}

void *threadSend(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    char buffer[100];
    while (true) {
        std::cout << "\033[1;32m" << "[*] Instructions: " << "\033[0m" << std::endl << "\033[1;36m";
        fgets(buffer, 100, stdin);
        send(connectionFD, buffer, 100, 0);
    }
}

void *threadReceive(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    char buffer[100];
    while (true) {
        int inData = 0;
        inData = recv(connectionFD, buffer, 100, 0);
        if (inData > 0) {
            std::cout << "\033[1;32m" << "[*] Respond: " << "\033[0m" << "\033[1;36m" << buffer << std::endl;
        }
    }
}