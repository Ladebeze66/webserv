# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:59:45 by fgras-ca          #+#    #+#              #
#    Updated: 2024/05/01 14:59:57 by fgras-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du binaire à compiler
NAME = webserv

# Compilateur C++
CXX = g++

# Flags de compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Fichiers source
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Fichiers objet correspondants
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Commande all
all: $(NAME)

# Règle pour créer le binaire
$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Règle pour créer les fichiers objet
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Commande clean pour supprimer les fichiers objet
clean:
	rm -rf $(OBJ_DIR)

# Commande fclean pour supprimer les fichiers objet et le binaire
fclean: clean
	rm -f $(NAME)

# Commande re pour recompiler tout
re: fclean all

# Empêcher make de confondre les noms de commande avec des fichiers
.PHONY: all clean fclean re
