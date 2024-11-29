#ifndef PROXY_HPP
#define PROXY_HPP

#include <future>
#include <string>
#include <iostream>

/**
 * @class Proxy
 * @brief Class representing the client-side proxy for asynchronous communication.
 */
class Proxy
{
public:
    /* Constructors */
    Proxy() = default;
    Proxy(const Proxy &other) = delete;
    Proxy(Proxy &&other) = delete;
    Proxy &operator=(const Proxy &other) = delete;
    Proxy &operator=(Proxy &&other) = delete;
    ~Proxy() = default;

    /* Execution Functions */
    /**
     * @brief Sends an asynchronous request.
     * @param request The request to send.
     * @return A std::future containing the response.
     */
    std::future<std::string> AsyncRequest(const std::string &request);

    /**
     * @brief Sets the response to the asynchronous request.
     * @param response The response to set.
     */
    void SetResponse(const std::string &response);

private:
    std::promise<std::string> promise; ///< Promise used for asynchronous communication.
};

#endif