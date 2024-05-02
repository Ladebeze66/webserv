/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:37:06 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/05/02 17:36:49 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConfigParser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

ConfigParser::ConfigParser(const std::string& filename) : filename(filename) {}

void ConfigParser::loadConfig() {
    std::ifstream file(filename.c_str());
    std::string line, currentSection;

    if (!file.is_open()) {
        std::cerr << "Failed to open config file: " << filename << std::endl;
        return;
    }

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#' || line[0] == ';') continue;

        if (line[0] == '[') {
            currentSection = line.substr(1, line.find(']') - 1);
            continue;
        }

        size_t delimiterPos = line.find('=');
        if (delimiterPos != std::string::npos) {
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            configSections[currentSection][key] = value;
        }
    }
    file.close();
}

std::string ConfigParser::getValue(const std::string& section, const std::string& key) {
    if (configSections.find(section) != configSections.end() && configSections[section].find(key) != configSections[section].end()) {
        return configSections[section][key];
    }
    return ""; // Return empty if not found
}

std::map<std::string, std::string> ConfigParser::getSection(const std::string& section) {
    if (configSections.find(section) != configSections.end()) {
        return configSections[section];
    }
    return std::map<std::string, std::string>();  // Retour explicite d'une map vide
}
