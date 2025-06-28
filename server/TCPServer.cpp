#include "TCPServer.h"
#include <winsock2.h>
#include <iostream>
#include "Router.h"

void TCPServer::run()
{
    // 1. Khởi động Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "[Server] WSAStartup failed\n";
        return;
    }

    // 2. Tạo socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        std::cerr << "[Server] Failed to create socket: " << WSAGetLastError() << "\n";
        WSACleanup();
        return;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server_fd, (sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR) {
        std::cerr << "[Server] Bind failed with error: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return;
    }

    if (listen(server_fd, 5) == SOCKET_ERROR) {
        std::cerr << "[Server] Listen failed with error: " << WSAGetLastError() << "\n";
        closesocket(server_fd);
        WSACleanup();
        return;
    }

    std::cout << "[Server] Listening on port " << port << "...\n";

    while (true)
    {
        int clientSocket = accept(server_fd, nullptr, nullptr);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "[Server] Failed to accept connection: " << WSAGetLastError() << "\n";
            continue;
        }

        // char buffer[2048] = {0};
        // int len = recv(clientSocket, buffer, sizeof(buffer), 0);
        // if (len <= 0) {
        //     closesocket(clientSocket);
        //     continue;
        // }

        // std::string input(buffer, len);

        std::string input;
        char buf[2048];
        int len;
        while ((len = recv(clientSocket, buf, sizeof(buf), 0)) > 0) {
            input.append(buf, len);
            if (input.find('\n') != std::string::npos)
                break;
        }
        Response res;

        try
        {
            Request req = RequestParser::parse(input);
            std::cout << "\nRequest --------------------\n";
            std::cout << req << std::endl;

            if (!AuthMiddleware::authorize(req)) {
                res = Response::unauthorized();
            } else {
                auto controller = Router::getController(req);
                if (controller) {
                    res = controller->handle(req);
                } else {
                    res = Response::error();
                }
            }
        }
        catch (const std::exception &e)
        {
            res = Response::error();
        }

        std::cout << "List TOKEN: " << TokenStore::instance() << '\n';
        std::cout << "Response --------------------" << std::endl;
        std::string output = res.toCS23Format() + "\n";
        std::cout << output;
        std::cout << "END ------------------------" << std::endl;

        send(clientSocket, output.c_str(), output.size(), 0);
        closesocket(clientSocket);
    }

    closesocket(server_fd);
    WSACleanup();
}
