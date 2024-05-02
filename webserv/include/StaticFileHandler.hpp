/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaticFileHandler.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:57:22 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/02 17:12:11 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATICFILEHANDLER_HPP
#define STATICFILEHANDLER_HPP

#include "HttpRequestHandler.hpp"
#include <fstream>
#include <sstream>

class StaticFileHandler : public HttpRequestHandler {
public:
    void handleRequest(const Request& req, Response& res);
};

#endif // STATICFILEHANDLER_HPP
