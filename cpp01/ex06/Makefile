# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 20:02:39 by vfedorov          #+#    #+#              #
#    Updated: 2024/05/17 20:02:41 by vfedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Harl
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -g
CPPFLAGS	+=	-std=c++98

RM			=	rm -f

SRCS		=	Harl.cpp main.cpp

HEADER		=	Harl.hpp

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