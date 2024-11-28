#ifndef PROXY_HPP
#define PROXY_HPP

#include <string>
#include <future>
#include <winsock2.h>
#include <vector>
#include <iostream>
#include <stdexcept>

/**
 * @class Proxy
 * @brief A class to handle communication with a server.
 */
class Proxy {
private:
    std::string _serverAddress; ///< Server address
    int _serverPort; ///< Server port

    /**
     * @fn void InitializeWinsock() const;
     * @brief Initialize Winsock.
     */
    void InitializeWinsock() const;

    /**
     * @fn SOCKET CreateSocket() const;
     * @brief Create a socket.
     * @return SOCKET The created socket.
     */
    SOCKET CreateSocket() const;

    /**    
     * @fn void ConnectSocket(SOCKET s, const struct sockaddr_in &server) const;
     * @brief Connect the socket to the server.
     * @param s The socket.
     * @param server The server address structure.
     */
    void ConnectSocket(SOCKET s, const struct sockaddr_in &server) const;

public:
    /**
     * @fn Proxy(const std::string &serverAddress, int serverPort);
     * @brief Construct a new Proxy object.
     * @param serverAddress The server address.
     * @param serverPort The server port.
     */
    Proxy(const std::string &serverAddress, int serverPort);

    /**
     * @fn std::string Request(const std::string &message);
     * @brief Send a request to the server and get the response.
     * @param message The message to send.
     * @return std::string The server response.
     */
    std::string Request(const std::string &message);
};

#endif