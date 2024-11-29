#include "Proxy.hpp"

Proxy::Proxy(const std::string &serverAddress, int serverPort)
    : _serverAddress(serverAddress), _serverPort(serverPort) {}

void Proxy::InitializeWinsock() const {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        throw std::runtime_error("Failed to initialize Winsock. Error Code: " + std::to_string(WSAGetLastError()));
    }
}

SOCKET Proxy::CreateSocket() const {
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        WSACleanup();
        throw std::runtime_error("Could not create socket. Error Code: " + std::to_string(WSAGetLastError()));
    }
    return s;
}

void Proxy::ConnectSocket(SOCKET s, const struct sockaddr_in &server) const {
    if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
        closesocket(s);
        WSACleanup();
        throw std::runtime_error("Connect error. Error Code: " + std::to_string(WSAGetLastError()));
    }
}

std::string Proxy::Request(const std::string &message) {
    InitializeWinsock();
    SOCKET socketDescriptor = CreateSocket();

    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(_serverAddress.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons(_serverPort);

    ConnectSocket(socketDescriptor, server);

    send(socketDescriptor, message.c_str(), message.length(), 0);

    std::vector<char> buffer(1024);
    recv(socketDescriptor, buffer.data(), buffer.size(), 0);

    closesocket(socketDescriptor);
    WSACleanup();

    return std::string(buffer.data());
}
