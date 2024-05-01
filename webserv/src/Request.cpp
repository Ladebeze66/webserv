/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:31:25 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/01 16:41:28 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"


void Request::parse(const std::string& requestText)
{
	std::istringstream requestStream(requestText);
	std::string line;
	std::getline(requestStream, line);

	// Parse the request line
	std::istringstream lineStream(line);
	lineStream >> method >> uri >> httpVersion;

	// Parse headers
	while (std::getline(requestStream, line) && !line.empty())
	{
		if (line == "\r")
		{
			continue; // Skip the first empty line after request line
		}
		std::string headerName;
		std::string headerValue;
		std::size_t pos = line.find(": ");
		if (pos != std::string::npos)
		{
			headerName = line.substr(0, pos);
			headerValue = line.substr(pos + 2);
			headers[headerName] = headerValue;
		}
	}

	// Read the body if present
	if (headers.count("Content-Length") > 0)
	{
		std::istringstream convert(headers["Content-Length"]); // Utiliser std::istringstream pour la conversion
		int contentLength = 0;
		convert >> contentLength;

		std::vector<char> buffer(contentLength);
		requestStream.read(&buffer[0], contentLength);
		body.assign(buffer.begin(), buffer.end());
	}
}
