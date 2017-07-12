#include <iostream>
#include "socketCombined.h"
#include "mainServer.h"
#include <pthread.h>

using namespace std;

//void *threadClientMonitor(void *varGroup);

int main(int argc, char *argv[]) {
    mainServer server;
    server.clientMonitor();

    //pthread_t threadIdClientMonitor;
    //pthread_create(&threadIdClientMonitor, nullptr, threadClientMonitor, nullptr);

    return EXIT_SUCCESS;
}

//void *threadClientMonitor(void *varGroup) {
/**
  * Merge server.clientMonitor Here
  * Once get Keyboard Break or execFlag input
  * Eliminate the chosen client
  */
//return nullptr;
//}
