NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = ./src/main.c \
      ./src/arg_checks.c

INC = ./includes/libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INC) -o $(NAME)
	@echo "📁 \033[32m✓ build completed\033[0m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[1;33m✓ objects removed\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[31m✓ executable removed\033[0m --> $(NAME)"

re: fclean all

.PHONY: all clean fclean re
