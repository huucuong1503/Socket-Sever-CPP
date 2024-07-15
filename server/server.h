#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>

class Server {
public:
    Server(int port);
    ~Server();
    void start();

private:
    int serverSocket;
    int clientSocket;
    sockaddr_in serverAddress;
    int port;
    void handleClient(int clientSocket);
};

#endif // SERVER_H
