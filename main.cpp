#include <iostream>
#include <WebServer.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    WebServer(8080).Run();
    return 0;
}
