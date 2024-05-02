/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:36:33 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/02 17:36:11 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGPARSER_HPP
#define CONFIGPARSER_HPP

#include <string>
#include <map>

class ConfigParser {
public:
    explicit ConfigParser(const std::string& filename);
    void loadConfig();
    std::string getValue(const std::string& section, const std::string& key);
    std::map<std::string, std::string> getSection(const std::string& section);

    private:
    std::string filename;
    std::map<std::string, std::map<std::string, std::string> > configSections;
};

#endif // CONFIGPARSER_HPP
