NAME		= game
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR = obj

FILES		= main AMateria Ice Cure  \
				Character MateriaSource

SRC			= $(FILES:=.cpp)
OBJ     	= $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES)))
HEADER		= AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp \
				Character.hpp  MateriaSource.hpp IMateriaSource.hpp

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