NAME = name

CC = cc
CFLAGS = -Werror -Wextra -Wall

LIBP = includes/
LIBN = libft.a
LIB = $(LIBP)$(LIBN)

INC = -I ./includes/libft/\
	  -I ./headers/\

SRC = $(addprefix src/, $(addsuffix .c, ))

OBJ = $(SRC:.c=.o)

a: all clean

all: $(LIB) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIB):
	@echo "Making lib..."
	@make -sC $(LIBP)

$(NAME): $(OBJ)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(INC) 
	@echo "Done. name is ready for use"

bonus: all

clean:
	@echo "Deleting .o files..."
	@rm -rf $(OBJ)
	@make clean -C $(LIBP)

fclean: clean
	@echo "Deleting name..."
	@rm -f $(NAME)
	@rm -f $(LIBP)$(LIBN)

re: fclean all

.PHONY: all re clean fclean
