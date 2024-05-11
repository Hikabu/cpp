# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 06:22:51 by vfedorov          #+#    #+#              #
#    Updated: 2024/05/11 12:24:23 by vfedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	moarBrainz
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -g
CPPFLAGS	+=	-std=c++98

RM			=	rm -f

SRCS		=	Zombie.cpp zombieHorde.cpp main.cpp

HEADER		=	Zombie.hpp

OBJS		=	${SRCS:%.cpp=%.o}

%.o:		%.cpp  $(HEADER)
			$(CC) $(CPPFLAGS) -c $< -o $@


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re