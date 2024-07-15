#include "server.h"

int main() {
    Server server(8090);
    server.start();
    return 0;
}
