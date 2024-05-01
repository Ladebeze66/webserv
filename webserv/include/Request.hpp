/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:52:29 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:41:46 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

class Request
{
	public:
		std::string method;
		std::string uri;
		std::string httpVersion;
		std::map<std::string, std::string> headers;
		std::string body;

		void parse(const std::string& requestText);
};

#endif
