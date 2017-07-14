//
// Created by 李欣 on 2017/7/12.
//

#ifndef LINUXCLIENT_MAINCLIENT_H
#define LINUXCLIENT_MAINCLIENT_H

#include "executioner.h"
#include "socketCombined.h"

using namespace std;

class mainClient {
private:
    socketCombined _sockClient;
    int _maxTry;
    char _dutyFlag[100] = "[*] Reporting For Duty";
    char _standbyFlag[100] = "[+] Standby";
    char _execFlag[100] = "[-] Suicide";
    executioner _agonyTerminator;
public:
    mainClient();

    void setMaxTry(int maxTry);

    void setPort();

    void setServer();

    void connectServer();

    bool trySend(const char *buffer);

    bool tryReceive(char *&buffer);

    void serverResponder();
};


#endif //LINUXCLIENT_MAINCLIENT_H
