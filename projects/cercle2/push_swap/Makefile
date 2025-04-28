# Define ANSI escape codes for different styles
# BOLD := \033[1m
# RED := \033[31m
# GREEN := \033[32m
# YELLOW := \033[33m
# BLUE := \033[34m
# RESET := \033[0m

NAME = name

CC = cc
CFLAGS = -Werror -Wextra -Wall

LIBP = includes/libft/
LIBN = libft.a
LIB = $(LIBP)$(LIBN)

INC = -I ./includes/libft/\
	  -I ./includes/headers/\

all : $(LIB) $(NAME)

SRC = $(addprefix src/, $(addsuffix .c, main))

OBJ = $(SRC:.c=.o)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIB):
	@echo "Making lib..."
	@make -sC  $(LIBP)

$(NAME): $(OBJ)
	@echo "Compiling name..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(INC) 
	@echo "Done. name is ready for use"

a : all clean


bonus: all

clean:
	@echo "Deleting .o files..."
	@rm -rf $(OBJ)
	@make clean -sC $(LIBP)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBP)$(LIBN)
	@echo "name deleted"

re: fclean all

.PHONY: all re clean fclean
