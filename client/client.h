#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>

class Client {
public:
    Client(const char* serverIP, int port);
    ~Client();
    void start();

private:
    int clientSocket;
    sockaddr_in serverAddress;
    const char* serverIP;
    int port;
    void sendMessage(const char* message);
};

#endif // CLIENT_H
