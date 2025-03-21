NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = ./src/main.c \
      ./src/arg_checks.c

INC = ./includes/libft/libft.a

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJS = $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJ))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)
	@echo "\\U0001F4C1 \033[32m✓ build completed\033[0m"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "\033[1;33m✓ objects removed\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31m✓ executable removed\033[0m --> $(NAME)"

re: fclean all

.PHONY: all clean fclean re