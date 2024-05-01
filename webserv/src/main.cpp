/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:21:48 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:49:59 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

int main(int argc, char **argv)
{
	int port = 8080; // Port par défaut

	if (argc > 1)
	{
		port = atoi(argv[1]); // Utilisation directe de atoi sans std::
	}

	try
	{
		Server server(port);
		std::cout << "Starting server on port " << port << std::endl;
		server.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE; // Utilisation directe sans std::
	}
	catch (...)
	{
		std::cerr << "Unknown exception caught" << std::endl;
		return EXIT_FAILURE; // Utilisation directe sans std::
	}

	return EXIT_SUCCESS; // Utilisation directe sans std::
}
