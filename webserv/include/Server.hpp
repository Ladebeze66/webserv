/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:50:29 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/02 17:06:03 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "Router.hpp"
#include <string>

class Server {
public:
    Server(const std::string& configPath);
    void run();

private:
    int port;
    std::string host;
    Router router;
    void initialize(const std::string& configPath);
};

#endif // SERVER_HPP
