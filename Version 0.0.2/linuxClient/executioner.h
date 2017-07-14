//
// Created by 李欣 on 2017/7/12.
//

#ifndef LINUXCLIENT_EXECUTIONER_H
#define LINUXCLIENT_EXECUTIONER_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <unistd.h>
#include <fstream>

using namespace std;

class executioner {
private:
    char _targetLocation[1000];
public:
    executioner();

    void setTarget(char *targetLocation);

    void listFiles(char *targetLocation);

    void terminadeThread(char *targetLocation);

    void terminateFiles(char *targetLocation);

    void executionTrigger();
};


#endif //LINUXCLIENT_EXECUTIONER_H
