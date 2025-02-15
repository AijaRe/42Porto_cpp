# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 19:16:50 by arepsa            #+#    #+#              #
#    Updated: 2025/02/15 09:46:58 by arepsa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
RM = rm -rf

CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98 -pedantic-errors -fsanitize=address

#generate dependency file
CPPFLAGS	= -MMD

NAME		= PmergeMe

SRC_DIR		= srcs
INC_DIR		= incs
FILES		= main PmergeMe
SRC			= $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(FILES)))
OBJ			= $(addprefix $(SRC_DIR)/, $(addsuffix .o, $(FILES)))
DEPS		= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# the - prefix in the include directive prevents make from quitting 
# if an included file doesn't exist
-include $(DEPS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@
	
clean:
	@$(RM) $(OBJ) $(DEPS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re