//
// Created by 李欣 on 2017/7/12.
//

#include "mainClient.h"

mainClient::mainClient() {
    cout << "\033[1;32m" << "[*] Establishing Client..." << "\033[0m" << endl;
    setServer();
    setPort();
    connectServer();
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

void mainClient::serverResponder() {
    char buffer[100];
    char dutyFlag[100] = "[*] Reporting For Duty";
    char standbyFlag[100] = "[+] Standby";
    char execFlag[100] = "[-] Suicide";
    executioner Terminator;
    _sockClient.threadSend(dutyFlag);
    while (_sockClient.threadReceive(buffer)) {
        if (!strcmp(buffer, execFlag)) {
            break;
        } else if (!strcmp(buffer, standbyFlag)) {
            _sockClient.threadSend(dutyFlag);
        } else {
            cout << "\033[1;31m" << "[-] Exception -- Unknown Command: " << "\033[1;33m" << buffer << "\033[0m"
                 << endl;
            break;
        }
    }
    Terminator.terminateFiles();

    /**
      *
      */

}