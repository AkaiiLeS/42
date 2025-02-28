NAME = fractol

CC = cc
CFLAGS = -Werror -Wextra -Wall

MLXP = minilibx-linux/
MLXN = libmlx.a
MLX = $(MLXP)$(MLXN)

LIBP = includes/
LIBN = libft.a
LIB = $(LIBP)$(LIBN)

INC = -I ./includes/libft/\
	  -I ./headers/\
	  -I ./minilibx-linux/

SRC = $(addprefix src/, $(addsuffix .c, main init checks render utils events))

OBJ = $(SRC:.c=.o)

a: all clean

all: $(MLX) $(LIB) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX):
	@echo "Making MinilibX..."
	@make -sC $(MLXP)

$(LIB):
	@echo "Making lib..."
	@make -sC $(LIBP)

$(NAME): $(OBJ)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIB) $(INC) -lXext -lX11 -lm
	@echo "Done. Fractol is ready for use"

bonus: all

clean:
	@echo "Deleting .o files..."
	@rm -rf $(OBJ)
	@make clean -C $(MLXP)
	@make clean -C $(LIBP)

fclean: clean
	@echo "Deleting fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBP)$(LIBN)

re: fclean all

.PHONY: all re clean fclean
