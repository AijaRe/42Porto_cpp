# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 19:16:50 by arepsa            #+#    #+#              #
#    Updated: 2024/11/08 18:31:03 by arepsa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
RM = rm -rf

CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98 -pedantic-errors -fsanitize=address

CPPFLAGS	= -MMD

NAME		= array
FILES		= main
SRC			= $(addsuffix .cpp, $(FILES))
OBJ			= $(addsuffix .o, $(FILES))
DEPS		= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

-include $(DEPS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(DEPS)

re: fclean all

.PHONY : all clean fclean re