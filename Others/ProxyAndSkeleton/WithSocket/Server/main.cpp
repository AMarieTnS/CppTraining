#include "Includes/Skeleton.hpp"

int main() {
    try {
        InitializeWinsock();
        SOCKET serverSocket = CreateSocket();

        struct sockaddr_in server, client;
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(8080);

        BindSocket(serverSocket, server);
        listen(serverSocket, 3);

        std::cout << "Server: Waiting for connections...\n";
        int clientSize = sizeof(struct sockaddr_in);
        SOCKET clientSocket = accept(serverSocket, (struct sockaddr *)&client, &clientSize);

        if (clientSocket == INVALID_SOCKET) {
            closesocket(serverSocket);
            WSACleanup();
            throw std::runtime_error("Accept failed. Error Code: " + std::to_string(WSAGetLastError()));
        }

        std::promise<std::string> responsePromise;
        std::future<std::string> futureResponse = responsePromise.get_future();

        Skeleton skeleton;
        std::thread workerThread(&Skeleton::HandleRequest, &skeleton, clientSocket, std::ref(responsePromise));

        std::cout << "Server: Processing request...\n";
        std::string response = futureResponse.get();

        std::cout << "Server: Response sent: " << response << "\n";

        workerThread.join();

        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}
