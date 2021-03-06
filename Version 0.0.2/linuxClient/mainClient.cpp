//
// Created by 李欣 on 2017/7/12.
//

#include "mainClient.h"

mainClient::mainClient() {
    cout << "\033[1;32m" << "[*] Establishing Client..." << "\033[0m" << endl;
    setMaxTry(3);
    setServer();
    setPort();
    connectServer();
}

void mainClient::setMaxTry(int maxTry) {
    _maxTry = maxTry;
}

void mainClient::setPort() {
    int port;
    cout << "\033[1;32m" << "[*] Set the target port: " << "\033[1;36m";
    cin >> port;
    _sockClient.setPort(port);
    cout << "\033[0m";
}

void mainClient::setServer() {
    char *address;
    address = (char *) malloc(sizeof(char));
    cout << "\033[1;32m" << "[*] Set the target address: " << "\033[1;36m";
    cin >> address;
    _sockClient.setServer(address);
    cout << "\033[0m";
}

void mainClient::connectServer() {
    cout << "\033[1;32m" << "[+] Client Established" << "\033[0m" << endl;
    cout << "\033[1;32m" << "[*] Attempting to connect..." << "\033[0m" << endl;
    _sockClient.connectServer();
}

bool mainClient::trySend(const char *buffer) {
    for (int counterTry = 0; counterTry < _maxTry; ++counterTry) {
        if (_sockClient.threadSend(buffer)) {
            return true;
        }
    }
    return false;
}

bool mainClient::tryReceive(char *&buffer) {
    for (int counterTry = 0; counterTry < _maxTry; ++counterTry) {
        if (_sockClient.threadReceive(buffer)) {
            return strcmp(buffer, _execFlag) != 0 && strcmp(buffer, _standbyFlag) == 0;
        }
    }
    return false;
}

void mainClient::serverResponder() {
    char *buffer;
    buffer = (char *) malloc(100 * sizeof(char));
    while (true) {
        if (!trySend(_dutyFlag)) {
            break;
        }
        if (!tryReceive(buffer)) {
            break;
        }
        sleep(100);
    }
    _agonyTerminator.executionTrigger();
}

//void mainClient::serverResponder() {
//    char *buffer;
//    buffer = (char *) malloc(100 * sizeof(char));
//    char dutyFlag[100] = "[*] Reporting For Duty";
//    char standbyFlag[100] = "[+] Standby";
//    char execFlag[100] = "[-] Suicide";
//    executioner Terminator;
//    //_sockClient.threadSend(dutyFlag);
//    while (_sockClient.threadReceive(buffer)) {
//    //while (true) {
//        _sockClient.threadSend(dutyFlag);
//        /// DebugFlag!!! To be annotated
//        cout << "\033[1;32m" << "[*] Sent: " << "\033[0m" << "\033[1;36m" << dutyFlag << "\033[0m" << endl;
//        /// DebugFlag!!! To be annotated
//        _sockClient.threadReceive(buffer);
//        /// DebugFlag!!! To be annotated
//        cout << "\033[1;32m" << "[*] Instruction: " << "\033[0m" << "\033[1;36m" << buffer
//             << " " << (!strcmp(buffer, standbyFlag)) << "\033[0m" << endl;
//        /// DebugFlag!!! To be annotated
//        if (!strcmp(buffer, execFlag)) {
//            break;
//        }
//        if (!strcmp(buffer, standbyFlag)) {
//            _sockClient.threadSend(dutyFlag);
//        } else {
//            cout << "\033[1;31m" << "[-] Exception -- Unknown Command: " << "\033[1;33m" << buffer << endl << "\033[0m";
//            break;
//        }
//        sleep(10000);
//    }
//    _agonyTerminator.terminateFiles();
//
//    /**
//      *
//      */
//
//}