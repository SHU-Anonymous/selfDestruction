//
// Created by 李欣 on 2017/7/12.
//

#ifndef LINUXCLIENT_MAINCLIENT_H
#define LINUXCLIENT_MAINCLIENT_H

#include "executioner.h"
#include "socketConsume.h"

using namespace std;

class mainClient {
private:
    socketConsume _sockCli;
public:
    mainClient();

    void setPort();

    void setServer();

    void connectServer();

    void serverResponder();
};


#endif //LINUXCLIENT_MAINCLIENT_H
