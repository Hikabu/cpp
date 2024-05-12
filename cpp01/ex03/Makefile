# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 17:20:41 by vfedorov          #+#    #+#              #
#    Updated: 2024/05/12 17:23:42 by vfedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	unnecessaryViolence
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-std=c++98

RM			=	rm -f

SRCS		=	HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

HEADER		=	HumanA.hpp HumanB.hpp Weapon.hpp

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