# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 15:28:59 by vfedorov          #+#    #+#              #
#    Updated: 2024/05/12 15:29:18 by vfedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	imBrain
CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -g
CPPFLAGS	+=	-std=c++98

RM			=	rm -f

SRCS		=	main.cpp

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