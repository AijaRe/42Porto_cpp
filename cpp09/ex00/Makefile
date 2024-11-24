# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 19:16:50 by arepsa            #+#    #+#              #
#    Updated: 2024/11/24 20:06:01 by arepsa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
RM = rm -rf

CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98 -pedantic-errors -Wno-unused -fsanitize=address

#generate dependency file
CPPFLAGS	= -MMD

NAME		= btc
FILES		= main BitcoinExchange
SRC			= $(addsuffix .cpp, $(FILES))
OBJ			= $(addsuffix .o, $(FILES))
DEPS		= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# the - prefix in the include directive prevents make from quitting 
# if an included file doesn't exist
-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
	
clean:
	@$(RM) $(OBJ) $(DEPS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re