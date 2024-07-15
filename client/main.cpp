#include "client.h"

int main() {
    Client client("127.0.0.1", 8090); // Using localhost IP for server
    client.start();
    return 0;
}
