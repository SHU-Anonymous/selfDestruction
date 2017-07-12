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
public:
    mainClient();

    void setPort();

    void setServer();

    void connectServer();

    void serverResponder();
};


#endif //LINUXCLIENT_MAINCLIENT_H
