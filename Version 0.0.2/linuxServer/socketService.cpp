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
    _serverAddress.sin_family = PF_INET;
    _serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
}

socketService::~socketService() {
    shutdown(*_connectFDP, SHUT_RDWR);
    shutdown(_listenFD, SHUT_RDWR);
}

void socketService::setPort(int Port) {
    _serverAddress.sin_port = htons(Port);
}

void socketService::bindSocket() {
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

void socketService::acceptClient() {
    _clientLength = sizeof(_clientAddress);
    while (true) {
        _connectFDP = (int *) malloc(sizeof(int));
        *_connectFDP = accept(_listenFD, (struct sockaddr *) &_clientAddress, &_clientLength);
        std::cout << "\033[1;32m" << "[+] Connection Accepted From: " << inet_ntoa(_clientAddress.sin_addr) << "\033[0m"
                  << std::endl;
        getchar();
        pthread_t _threadIdMain;
        pthread_create(&_threadIdMain, nullptr, threadMain, _connectFDP);
    }
}

void *threadMain(void *varGroup) {
    pthread_t _threadIdSend, _threadIdReceive;
    pthread_create(&_threadIdSend, nullptr, threadSend, varGroup);
    pthread_create(&_threadIdReceive, nullptr, threadReceive, varGroup);
    return nullptr;
}

void *threadSend(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    char buffer[100];
    while (true) {
        std::cout << "\033[1;32m" << "[*] Instructions: " << "\033[0m" << std::endl << "\033[1;36m";
        fgets(buffer, 100, stdin);
        std::cout << "\033[0m";
        send(connectionFD, buffer, 100, 0);
    }
    return nullptr;
}

void *threadReceive(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    char buffer[100];
    char dutyFlag[100] = "[*] Reporting For Duty";
    char standbyFlag[100] = "[+] Standby";
    char execFlag[100] = "[-] Suicide";
    while (true) {
        int inData;
        inData = static_cast<int>(recv(connectionFD, buffer, 100, 0));
        if (inData > 0) {
            std::cout << "\033[1;32m" << "[*] Respond: " << "\033[0m" << "\033[1;36m" << buffer << "\033[0m"
                      << std::endl;
            if (!strcmp(buffer, dutyFlag)) {
                send(connectionFD, execFlag, 100, 0);
            }
        }
//        if (inData > 0 && buffer == dutyFlag) {
//            send(connectionFD, standbyFlag, 100, 0);
//        }
    }
    return nullptr;
}