# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 19:57:33 by arepsa            #+#    #+#              #
#    Updated: 2024/04/19 20:01:41 by arepsa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= megaphone
FILES 		= megaphone
SRC 		= $(addsuffix .cpp, $(FILES))
OBJ 		= $(addsuffix .o, $(FILES))

CXX = c++
RM = rm -rf

CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98 -pedantic-errors -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re