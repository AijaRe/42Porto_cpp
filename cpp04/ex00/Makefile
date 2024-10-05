# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 21:22:20 by arepsa            #+#    #+#              #
#    Updated: 2024/10/05 15:14:27 by arepsa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
RM = rm -rf

CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98 -pedantic-errors -fsanitize=address

NAME 		= animal
FILES 		= main Animal Dog Cat WrongAnimal WrongCat
SRC 		= $(addsuffix .cpp, $(FILES))
OBJ 		= $(addsuffix .o, $(FILES))


all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re