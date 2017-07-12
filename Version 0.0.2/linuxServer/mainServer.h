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
public:
    mainServer();

    void setPort();

    void establishServer();

    void clientMonitor();
};


#endif //LINUXSERVER_MAINSERVER_H
