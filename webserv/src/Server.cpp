/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:52:03 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:46:49 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(int port)
{
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1)
	{
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 10) < 0)
	{
		perror("listen failed");
		exit(EXIT_FAILURE);
	}
}

Server::~Server()
{
	close(server_fd);
}

void Server::run()
{
	std::cout << "Server is running on port " << ntohs(address.sin_port) << std::endl;
	while (true)
	{
		int addrlen = sizeof(address);
		int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
		if (new_socket < 0)
		{
			perror("accept failed");
			continue;
		}
		handleConnection(new_socket);
		close(new_socket);
	}
}

void Server::handleConnection(int clientSocket)
{
	Request request;
	Response response;
	// Here you would actually parse the incoming request and generate a response
	router.handleRequest(request, response, clientSocket);
}
