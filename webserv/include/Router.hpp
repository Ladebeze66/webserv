/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:55:00 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/02 17:30:59 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Request.hpp"
#include "Response.hpp"
#include "ConfigParser.hpp"
#include <map>

typedef void (*RequestHandler)(const Request&, Response&, const std::map<std::string, std::string>&);

class Router {
public:
    std::map<std::string, RequestHandler> routeTable;
    void configureRoutes(const ConfigParser& config);
    void handleRequest(Request& req, Response& res, int clientSocket);
    static void handleRoot(const Request& req, Response& res, const std::map<std::string, std::string>& settings);
    static void handleApi(const Request& req, Response& res, const std::map<std::string, std::string>& settings);
    static void handleUpload(const Request& req, Response& res, const std::map<std::string, std::string>& settings);
};

#endif // ROUTER_HPP
