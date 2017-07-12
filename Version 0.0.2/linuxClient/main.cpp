#include <iostream>
#include "executioner.h"
#include "socketConsume.h"
#include "mainClient.h"

using namespace std;

int main(int argc, char *argv[]) {
    mainClient client;
    client.serverResponder();
    return EXIT_SUCCESS;
}
