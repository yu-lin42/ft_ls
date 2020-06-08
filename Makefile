# RED = \033[31m
# GREEN = \x1b[32m
# YELLOW = \x1b[33m
# CYAN = \x1b[36m
# NC = \033[0m
START = "${RED}Starting compilation...${NC}"
MIDDLE = "${YELLOW}Creating archive...${NC}"
END = "${GREEN}Finishing...${NC}"

NAME = ft_ls

LIB_DIR = ./libft
SRC = main.c add_stuff.c parser.c check_stuff.c show_stuff.c ls_sequence.c sorting.c free_stuff.c multiple_stuff.c
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "${CYAN}Creating LIBFT${NC}"
	@make -C $(LIB_DIR)
	@echo ${START}
	@gcc $(FLAGS) $(SRC) $(LIB_DIR)/libft.a -o $(NAME)
	@echo ${MIDDLE}
	@make clean
	@echo ${END}
	@echo "Ta-Da! :D"

clean:
	@make -C $(LIB_DIR) clean

fclean:
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all
