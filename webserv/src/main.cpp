/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:21:48 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/02 16:57:15 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConfigParser.hpp"
#include <iostream>

int main() {
    ConfigParser config("config.ini");
    config.loadConfig();

    std::string port = config.getValue("server:8080", "port");
    std::string root = config.getValue("route:/", "root");

    std::cout << "Server will run on port: " << port << std::endl;
    std::cout << "Content root: " << root << std::endl;

    // Continue server setup and operation...
    return 0;
}
