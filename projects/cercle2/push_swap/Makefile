# Define ANSI escape codes for different styles
# BOLD := \033[1m
# RED := \033[31m
# GREEN := \033[32m
# YELLOW := \033[33m
# BLUE := \033[34m
# RESET := \033[0m

NAME = push_swap

CC = cc
CFLAGS = -Werror -Wextra -Wall

LIBP = includes/libft/
LIBN = libft.a
LIB = $(LIBP)$(LIBN)

INC = -I ./includes/libft/\
	  -I ./includes/headers/\

all : $(LIB) $(NAME)

SRC = $(addprefix src/, $(addsuffix .c, main checks utils utils2 sort sort2 \
	  swap move rr rotate push ))

OBJ = $(SRC:.c=.o)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIB):
	@echo "Making lib..."
	@make -sC  $(LIBP)

$(NAME): $(OBJ)
	@echo "Compiling push_swap..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(INC) 
	@echo "Done. push_swap is ready for use"

a : all clean


bonus: all

clean:
	@echo "Deleting .o files..."
	@rm -rf $(OBJ)
	@make clean -sC $(LIBP)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBP)$(LIBN)
	@echo "push_swap deleted"

re: fclean all

.PHONY: all re clean fclean
