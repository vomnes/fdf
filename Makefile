NAME = fdf
SRC_PF =

OBJET_PF = $(SRC_PF:.c=.o)

FLAGS = -Wall -Werror -Wextra

GCC = gcc
MAKE = make

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJET_PF) $(SRC_PF) $(LIB)
		@echo Compiling $(NAME)
		@$(GCC) $(FLAGS) -c $(SRC_PF)
		@echo ======[Done]======

%.o : %.c
		@echo "$(NAME) >>> Add/Update $^"

clean:
		@echo Clean objects $(NAME)
		@rm -rf $(OBJET_PF)

fclean: clean
		@echo Clean $(NAME)
		@rm -rf $(NAME)
		@echo ======[Clean]======

re: fclean all
