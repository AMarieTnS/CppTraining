#include "proxy.hpp"

/**
 * @brief Sends an asynchronous request.
 * @param request The request to send.
 * @return A std::future containing the response.
 */
std::future<std::string> Proxy::AsyncRequest(const std::string &request)
{
    std::cout << "Request: " << request << std::endl;
    return promise.get_future();
}

/**
 * @brief Sets the response to the asynchronous request.
 * @param response The response to set.
 */
void Proxy::SetResponse(const std::string &response)
{
    promise.set_value(response);
}