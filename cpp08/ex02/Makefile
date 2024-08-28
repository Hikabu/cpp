NAME		= theMonstr
	
CC			= c++
# FLAGS		= -Wall -Wextra -Werror -std=c++17 -g3
FLAGS		=  -Wall -Wextra -Werror -Wc++98-compat-pedantic -g3
RM			= rm -rf

OBJDIR = obj

FILES		= main

SRC			= $(FILES:=.cpp)
OBJ     	= $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES)))
HEADER		= MutantStack.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER) Makefile
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re