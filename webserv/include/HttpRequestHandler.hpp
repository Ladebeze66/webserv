/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequestHandler.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:56:47 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/02 17:11:55 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPREQUESTHANDLER_HPP
#define HTTPREQUESTHANDLER_HPP

#include "Request.hpp"
#include "Response.hpp"

class HttpRequestHandler {
public:
    virtual void handleRequest(const Request& req, Response& res) = 0;
};

#endif // HTTPREQUESTHANDLER_HPP
