NAME		= ClapTrap
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR = obj

FILES		= main ClapTrap

SRC			= $(FILES:=.cpp)
OBJ      = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES)))
HEADER		= ClapTrap.hpp

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