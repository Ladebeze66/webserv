/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticFileHandler.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:58:11 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:47:58 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StaticFileHandler.hpp"

void StaticFileHandler::handleRequest(const Request& req, Response& res)
{
	// Utiliser c_str() pour convertir std::string en const char*
	std::ifstream file(req.uri.substr(1).c_str(), std::ios::binary);
	if (file)
	{
		std::ostringstream ss;
		ss << file.rdbuf();  // copier le contenu du fichier
		res.body = ss.str();
		res.statusCode = 200;
	}
	else
	{
		res.body = "File not found";
		res.statusCode = 404;
	}
}
