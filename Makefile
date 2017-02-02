NAME = fdf
SRC = draw_line.c user_interaction.c get_input.c coord_in_struct.c \
get_size.c build_iso.c select_color.c manage_color.c initialisation.c \
display_command.c main.c

OBJET = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

MLX = -lmlx -framework OpenGL -framework Appkit

GCC = gcc
MAKE = make

.PHONY: clean fclean all re

all: $(NAME)

$(NAME): $(OBJET)
		@echo Compiling $(NAME)
		@$(GCC) $(FLAGS) -I . -c $(SRC)
		@$(GCC) $(FLAGS) -o $(NAME) $(OBJET) -I . $(MLX) -L . -lft
		@echo ======[Done]======

%.o : %.c
		@echo "$(NAME) >>> Add/Update $^"

clean:
		@echo Clean objects $(NAME)
		@rm -rf $(OBJET)

fclean: clean
		@echo Clean $(NAME)
		@rm -rf $(NAME)
		@echo ======[Clean]======

re: fclean all
