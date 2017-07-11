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
    pthread_t threadIdSend, threadIdReceive;
    while (true) {
        pthread_create(&threadIdSend, nullptr, threadSend, _clientFDP);
        pthread_create(&threadIdReceive, nullptr, threadReceive, _clientFDP);
    }
}

void *threadSend(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    char buffer[100];
    while (true) {
        std::cout << "\033[1;32m" << "[*] Respond: " << "\033[0m" << "\033[1;36m" << std::endl;
        getchar();
        fgets(buffer, 100, stdin);
        std::cout << "\033[0m";
        send(connectionFD, buffer, 100, 0);
    }
    return nullptr;
}

void *threadReceive(void *varGroup) {
    int connectionFD = *((int *) varGroup);
    char buffer[100];
    while (true) {
        int inData;
        inData = static_cast<int>(recv(connectionFD, buffer, 100, 0));
        if (inData > 0) {
            std::cout << "\033[1;32m" << "[*] Instructions: " << "\033[0m" << "\033[1;36m" << buffer << "\033[0m"
                      << std::endl;
        }
    }
    return nullptr;
}