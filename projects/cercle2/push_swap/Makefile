# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 14:58:55 by salsoysa          #+#    #+#              #
#    Updated: 2025/04/30 14:59:20 by salsoysa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


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
