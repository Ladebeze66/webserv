/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:50:29 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:49:07 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "Request.hpp"
#include "Response.hpp"
#include "Router.hpp"
#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <cstdio>  // Pour perror
#include <cstdlib> // Pour exit et EXIT_FAILURE

class Server
{
	public:
		Server(int port);
		~Server();
		void run();

	private:
		int server_fd;
		sockaddr_in address;
		Router router;
		void handleConnection(int clientSocket);
};

#endif
