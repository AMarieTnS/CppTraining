#include "Skeleton.hpp"

void Skeleton::HandleRequest(SOCKET clientSocket, std::promise<std::string> &responsePromise) {
    std::vector<char> buffer(1024);
    recv(clientSocket, buffer.data(), buffer.size(), 0);

    std::string request(buffer.data());
    std::cout << "Skeleton: Received request: " << request << "\n";

    std::string response = "Processed: " + request;
    responsePromise.set_value(response);

    send(clientSocket, response.c_str(), response.length(), 0);
}

void InitializeWinsock() {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        throw std::runtime_error("Failed to initialize Winsock. Error Code: " + std::to_string(WSAGetLastError()));
    }
}

SOCKET CreateSocket() {
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        WSACleanup();
        throw std::runtime_error("Could not create socket. Error Code: " + std::to_string(WSAGetLastError()));
    }
    return s;
}

void BindSocket(SOCKET s, struct sockaddr_in &server) {
    if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR) {
        closesocket(s);
        WSACleanup();
        throw std::runtime_error("Bind failed. Error Code: " + std::to_string(WSAGetLastError()));
    }
}
