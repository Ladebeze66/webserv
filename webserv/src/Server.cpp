#include "Server.hpp"
#include "ConfigParser.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

Server::Server(const std::string& configPath) {
    initialize(configPath);
}

void Server::initialize(const std::string& configPath) {
    ConfigParser config(configPath);
    config.loadConfig();
    port = std::atoi(config.getValue("server:8080", "port").c_str());
    host = config.getValue("server:8080", "host");
    // Initialize routes based on configuration
    router.configureRoutes(config);
}

void Server::run() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is running on port " << port << std::endl;

    while (true) {
        int addrlen = sizeof(address);
        int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("accept failed");
            continue;
        }

        Request request;
        Response response;
        router.handleRequest(request, response, new_socket);
        response.send(new_socket);
        close(new_socket);
    }
}
