# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 17:53:31 by vfedorov          #+#    #+#              #
#    Updated: 2024/05/06 20:45:48 by vfedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	zombie
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-std=c++98

RM			=	rm -f

SRCS		=	Zombie.cpp newZombie.cpp randomChump.cpp main.cpp

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