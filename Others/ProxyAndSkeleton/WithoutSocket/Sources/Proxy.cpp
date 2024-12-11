#include "proxy.hpp"

/**
 * @brief Sends an asynchronous request.
 * @param[in] request The request to send.
 * @return A std::future containing the response.
 * @throws std::future_error If the promise state is invalid.
 */
std::future<std::string> Proxy::AsyncRequest(const std::string &request)
{
    std::cout << "Request: " << request << std::endl;
    return promise.get_future();
}

/**
 * @brief Sets the response to the asynchronous request.
 * @param[in] response The response to set.
 * @throws std::future_error If the promise state is invalid.
 */
void Proxy::SetResponse(const std::string &response)
{
    promise.set_value(response);
}