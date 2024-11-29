#ifndef SKELETON_HPP
#define SKELETON_HPP

#include <string>
#include <thread>
#include <future>
#include <winsock2.h>
#include <iostream>
#include <stdexcept>
#include <vector>

/**
 * @class Skeleton
 * @brief A class to handle client requests.
 */
class Skeleton {
public:
    /**
     * @brief Handle a client request.
     * @param clientSocket The client socket.
     * @param responsePromise The promise to set the response.
     */
    void HandleRequest(SOCKET clientSocket, std::promise<std::string> &responsePromise);
};

/**
 * @brief Initialize Winsock.
 */
void InitializeWinsock();

/**
 * @brief Create a socket.
 * @return SOCKET The created socket.
 */
SOCKET CreateSocket();

/**
 * @brief Bind the socket to the server address.
 * @param s The socket.
 * @param server The server address structure.
 */
void BindSocket(SOCKET s, struct sockaddr_in &server);

#endif 