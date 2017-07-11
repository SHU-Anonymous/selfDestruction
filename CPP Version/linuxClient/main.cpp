#include <iostream>
#include "socketConsume.h"

using namespace std;

int main() {
    socketConsume sockCon;
    int port = 5005;
    char *address = "127.0.0.1";
//    std::cout << "\033[1;32m" << "[*] Set the target port: " << "\033[0m" << "\033[1;36m";
//    std::cin >> port;
//    std::cout << "\033[0m";
//    std::cout << "\033[1;32m" << "[*] Set the target address: " << "\033[0m" << "\033[1;36m";
//    std::cin >> address;
//    std::cout << "\033[0m";
    sockCon.setPort(port);
    sockCon.setServer(address);
    sockCon.connectServer();
    return EXIT_SUCCESS;
}