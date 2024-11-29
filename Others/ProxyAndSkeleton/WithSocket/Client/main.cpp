#include "Includes/Proxy.hpp"

int main() {
    Proxy proxy("127.0.0.1", 8080);

    std::future<std::string> futureResponse = std::async(&Proxy::Request, &proxy, "Hello, Server!");

    std::cout << "Waiting for server response...\n";
    std::string response = futureResponse.get();

    std::cout << "Client: Server response: " << response << "\n";

    return 0;
}
