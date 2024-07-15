#include "server.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>

Server::Server(int port) : port(port), serverSocket(-1), clientSocket(-1) {
    // creating socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying the address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
}

Server::~Server() {
    if (serverSocket != -1) {
        close(serverSocket);
    }
}

void Server::start() {
    // binding socket
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // listening to the assigned socket
    listen(serverSocket, 5);

    // accepting connection request
    clientSocket = accept(serverSocket, nullptr, nullptr);

    handleClient(clientSocket);

    // closing the socket
    close(clientSocket);
}

void Server::handleClient(int clientSocket) {
    char buffer[1024] = {0};
    while (true) {
        auto checkdata = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (checkdata <= 0) {
            break;
        }
        std::cout << "Message from client: " << buffer << std::endl;
    }
}
