/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Router.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:55:36 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:44:20 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Router.hpp"

// Déclaration d'un gestionnaire de requête
void myRequestHandler(Request& req, Response& res)
{
	// Traiter la requête, par exemple pour l'URI "/hello"
	if (req.uri == "/hello")
	{
		res.body = "Hello, World!";
		res.statusCode = 200;
	}
	else
	{
		res.body = "Resource not found";
		res.statusCode = 404;
	}
}

// Constructeur du Router, ici vous ajoutez tous les gestionnaires
Router::Router()
{
	// Associer l'URI avec le gestionnaire correspondant
	routeTable["/hello"] = myRequestHandler;
}

// Méthode pour gérer les requêtes entrantes
void Router::handleRequest(Request& req, Response& res, int clientSocket)
{
	// Rechercher si l'URI demandé existe dans la table de routage
	std::map<std::string, RequestHandler>::iterator it = routeTable.find(req.uri);
	if (it != routeTable.end())
	{
		// Appel de la fonction pointée si l'URI est trouvé
		(*it->second)(req, res);
	}
	else
	{
		// Gérer le cas où l'URI n'est pas trouvé
		res.statusCode = 404;
		res.body = "404 Not Found";
	}
	// Envoyer la réponse
	res.send(clientSocket);
}
