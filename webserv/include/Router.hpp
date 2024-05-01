/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:55:00 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:44:22 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "Request.hpp"
#include "Response.hpp"
#include <map>

typedef void (*RequestHandler)(Request&, Response&);

class Router
{
	public:
		std::map<std::string, RequestHandler> routeTable;

		Router();  // Constructeur pour initialiser le routeur
		void handleRequest(Request& req, Response& res, int clientSocket);
};

#endif
