NAME = ft_ls

LIB_DIR = ./libft
HEADER = ft_ls.h
SRC = main.c add_stuff.c ls_sequence.c parser.c sorting.c check_stuff.c show_stuff.c multi_cmd.c
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@echo "Compiling LIBFT..."
	@gcc $(FLAGS) $(SRC) $(HEADER) $(LIB_DIR)/libft.a -o $(NAME)
	@echo "Compiling ft_ls..."
	@echo "Ta-Da!!! Complete!"

clean:
	@make -C $(LIB_DIR) clean

fclean:
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all