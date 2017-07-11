#include <iostream>
#include "socketConsume.h"

using namespace std;

int main(int argc, char *argv[]) {
    socketConsume sockCon;
    int port;
    char *address;
    cout << "\033[1;32m" << "[*] Set the target port: " << "\033[0m" << "\033[1;36m";
    cin >> port;
    cout << "\033[0m";
    cout << "\033[1;32m" << "[*] Set the target address: " << "\033[0m" << "\033[1;36m";
    cin >> address;
    cout << "\033[0m";
    sockCon.setPort(port);
    sockCon.setServer(address);
    sockCon.connectServer();
    return EXIT_SUCCESS;
}