/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticFileHandler.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:58:11 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/02 17:12:25 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StaticFileHandler.hpp"

void StaticFileHandler::handleRequest(const Request& req, Response& res) {
    std::ifstream file(req.uri.substr(1).c_str(), std::ios::binary);  // Assuming uri includes a leading '/'
    if (file) {
        std::ostringstream ss;
        ss << file.rdbuf();  // Read the content
        res.body = ss.str();
        res.statusCode = 200;
    } else {
        res.body = "File not found";
        res.statusCode = 404;
    }
}
