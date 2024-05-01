/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:53:42 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:42:53 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>
#include <map>
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>

class Response
{
	public:
		int statusCode;
		std::map<std::string, std::string> headers;
		std::string body;
		void send(int clientSocket);
};

#endif
