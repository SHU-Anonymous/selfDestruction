//
// Created by 李欣 on 2017/7/13.
//

#ifndef LINUXSERVER_MAINSERVER_H
#define LINUXSERVER_MAINSERVER_H

#include "socketCombined.h"

using namespace std;

class mainServer {
private:
    socketCombined _sockServer;
    int _maxTry;
    char _dutyFlag[100] = "[*] Reporting For Duty";
    char _standbyFlag[100] = "[+] Standby";
    char _execFlag[100] = "[-] Suicide";
public:
    mainServer();

    void setMaxTry(int maxTry);

    void setPort();

    void establishServer();

    bool handlerSend(const char *buffer);

    bool handlerReceive(char *&buffer);

    void clientMonitor();
};


#endif //LINUXSERVER_MAINSERVER_H
