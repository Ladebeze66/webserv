/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:55:36 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/02 17:35:33 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Router.hpp"

// Example specific route handlers (these need to be defined based on your application's logic)
void handleRoot(Request& req, Response& res, const std::map<std::string, std::string>& settings) {
    if (req.method == "GET" || req.method == "POST") {
        res.statusCode = 200;
        res.body = "<html><body>Welcome to the homepage!</body></html>";
    } else {
        res.statusCode = 405;
        res.body = "Method Not Allowed";
    }
}

void handleApi(Request& req, Response& res, const std::map<std::string, std::string>& settings) {
    if (req.method == "GET" || req.method == "POST") {
        res.statusCode = 200;
        res.body = "{\"message\": \"API is working\"}";
    } else {
        res.statusCode = 405;
        res.body = "Method Not Allowed";
    }
}

void handleUpload(Request& req, Response& res, const std::map<std::string, std::string>& settings) {
    if (req.method == "POST") {
        res.statusCode = 200;
        res.body = "File upload successful";
    } else {
        res.statusCode = 405;
        res.body = "Method Not Allowed";
    }
}

void Router::configureRoutes(const ConfigParser& config) {
    // Configure the root route
    auto rootSettings = config.getSection("route:/");
    routeTable["/"] = [rootSettings](Request& req, Response& res) {
        handleRoot(req, res, rootSettings);
    };

    // Configure the API route
    auto apiSettings = config.getSection("route:/api");
    routeTable["/api"] = [apiSettings](Request& req, Response& res) {
        handleApi(req, res, apiSettings);
    };

    // Configure the upload route
    auto uploadSettings = config.getSection("route:/upload");
    routeTable["/upload"] = [uploadSettings](Request& req, Response& res) {
        handleUpload(req, res, uploadSettings);
    };
}

void Router::handleRequest(Request& req, Response& res, int clientSocket) {
    auto handler = routeTable.find(req.uri);
    if (handler != routeTable.end()) {
        handler->second(req, res);
    } else {
        res.statusCode = 404;
        res.body = "404 Not Found";
    }
    res.send(clientSocket);
}
