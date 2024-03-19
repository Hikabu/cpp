# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 17:53:31 by vfedorov          #+#    #+#              #
#    Updated: 2024/03/19 12:14:51 by vfedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CPP = c++

SRC = megaphone.cpp

FLAGS =  -Wall -Wextra -Werror -std=c++98

all = $(NAME)

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(NAME)
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re