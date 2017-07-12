#include <iostream>
#include "socketCombined.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "\033[1;32m" << "[*] Establishing Server..." << "\033[0m" << endl;
    socketCombined sockServer;
    int port;
    std::cout << "\033[1;32m" << "[*] Set the target port: " << "\033[0m" << "\033[1;36m";
    cin >> port;
    cout << "\033[0m";
    sockServer.setPort(port);
    sockServer.bindSocket();
    sockServer.listenClient();
    cout << "\033[1;32m" << "[+] Server Established" << "\033[0m" << endl;
    sockServer.acceptClient();
    return EXIT_SUCCESS;
}
