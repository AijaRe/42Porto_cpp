# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 19:16:50 by arepsa            #+#    #+#              #
#    Updated: 2024/10/20 21:19:24 by arepsa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
RM = rm -rf

CXXFLAGS 	= -Wall -Werror -Wextra -Wno-unused -std=c++98 -pedantic-errors -fsanitize=address

NAME		= convert
FILES		= main ScalarConverter
SRC			= $(addsuffix .cpp, $(FILES))
OBJ			= $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re