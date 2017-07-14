//
// Created by 李欣 on 2017/7/13.
//

#include "mainServer.h"

mainServer::mainServer() {
    cout << "\033[1;32m" << "[*] Establishing Server..." << "\033[0m" << endl;
    setMaxTry(3);
    setPort();
    establishServer();
}

void mainServer::setMaxTry(int maxTry) {
    _maxTry = maxTry;
}

void mainServer::setPort() {
    int port;
    cout << "\033[1;32m" << "[*] Set the target port: " << "\033[0m" << "\033[1;36m";
    cin >> port;
    cout << "\033[0m";
    _sockServer.setPort(port);
}

void mainServer::establishServer() {
    _sockServer.bindSocket();
    _sockServer.listenClient();
    cout << "\033[1;32m" << "[+] Server Established" << "\033[0m" << endl;
    _sockServer.acceptClient();
}

bool mainServer::handlerReceive(char *&buffer) {
    for (int counterTry = 0; counterTry < _maxTry; ++counterTry) {
        if (_sockServer.threadReceive(buffer)) {
            return strcmp(buffer, _dutyFlag) == 0;
        }
    }
    return false;
}

bool mainServer::handlerSend(const char *buffer) {
    for (int counterTry = 0; counterTry < _maxTry; ++counterTry) {
        if (_sockServer.threadSend(buffer)) {
            cout << buffer;
            return true;
        }
    }
    return false;
}

void mainServer::clientMonitor() {
    char *buffer;
    buffer = (char *) malloc(100 * sizeof(char));
//    while (true) {
    for (int i = 0; i < 10; ++i) {
        if (!handlerReceive(buffer)) {
            handlerSend(_execFlag);
        }
        handlerSend(_standbyFlag);
    }
    handlerSend(_execFlag);
}

//void mainServer::clientMonitor() {
//    char *buffer;
//    buffer = (char *) malloc(100 * sizeof(char));
//    _sockServer.threadSend(standbyFlag);
//    while (_sockServer.threadReceive(buffer)) {
//    while (true) {
//        _sockServer.threadReceive(buffer);
//        /// DebugFlag!!! To be annotated
//        cout << "\033[1;32m" << "[*] Respond: " << "\033[0m" << "\033[1;36m" << buffer << "\033[0m" << endl;
//        /// DebugFlag!!! To be annotated
//        if (strcmp(buffer, _dutyFlag) != 0) {
//            _sockServer.threadSend(_execFlag);
//        }
//        _sockServer.threadSend(_standbyFlag);
//        /// DebugFlag!!! To be annotated
//        cout << "\033[1;32m" << "[*] Sent: " << "\033[0m" << "\033[1;36m" << _dutyFlag << "\033[0m" << endl;
//        /// DebugFlag!!! To be annotated
//    }
//}