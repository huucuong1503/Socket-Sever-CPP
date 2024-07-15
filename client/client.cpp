#include "client.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

Client::Client(const char* serverIP, int port) : serverIP(serverIP), port(port), clientSocket(-1) {
    // creating socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = inet_addr(serverIP);
    // serverAddress.sin_addr.s_addr = INADDR_ANY;

}

Client::~Client() {
    if (clientSocket != -1) {
        close(clientSocket);
    }
}

void Client::start() {
    // sending connection request
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // sending data
    const char* message = "Hello, server!";
    int myDec = 0;
    while (true) {
        std::cin >> myDec;
        if (myDec == 1) {
            sendMessage(message);
            myDec = 0;
        }
        std::cout << std::endl;
    }
}

void Client::sendMessage(const char* message) {
    send(clientSocket, message, strlen(message), 0);
}
