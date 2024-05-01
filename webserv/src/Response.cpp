/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:54:29 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:42:58 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Response.hpp"

void Response::send(int clientSocket)
{
	std::ostringstream ss;
	ss << "HTTP/1.1 " << statusCode << " OK\r\n";
	for (std::map<std::string, std::string>::iterator it = headers.begin(); it != headers.end(); ++it)
	{
	ss << it->first << ": " << it->second << "\r\n";
	}
	ss << "\r\n" << body;
	std::string response = ss.str();
	::send(clientSocket, response.c_str(), response.length(), 0);
}
