#include <iostream>
#include "proxy.hpp"
#include "skeleton.hpp"

/**
 * @brief Main function demonstrating the use of Proxy and Skeleton for asynchronous communication.
 * @return int Program exit status.
 */
int main()
{
    Proxy proxy;
    Skeleton skeleton;

    // Client sends an asynchronous request
    std::future<std::string> future = proxy.AsyncRequest("Hello, Server!");

    // Server processes the request
    std::string response = skeleton.ProcessRequest("Hello, Server!");

    // Server sends the response back to the client
    proxy.SetResponse(response);

    // Client receives the response
    std::string result = future.get();
    std::cout << "Client received: " << result << std::endl;

    return 0;
}