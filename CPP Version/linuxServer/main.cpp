#include <iostream>
#include "socketService.h"

using namespace std;


int main() {
    cout << "\033[1;32m" << "[*] Establishing Server..." << "\033[0m" << endl;
    socketService sockSrv;
    int port;
    std::cout << "\033[1;32m" << "[*] Set the target port: " << "\033[0m" << "\033[1;36m";
    cin >> port;
    cout << "\033[0m";
    sockSrv.setPort(port);
    sockSrv.bindSokcet();
    sockSrv.listenClient();
    cout << "\033[1;32m" << "[+] Server Established" << "\033[0m" << endl;
    sockSrv.acceptClient();
    return 0;
}
