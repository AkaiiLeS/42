# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 13:02:51 by salsoysa          #+#    #+#              #
#    Updated: 2024/11/22 13:34:03 by salsoysa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  utils/ft_putchar.c utils/ft_putnbr.c utils/ft_putunbr.c \
	  			utils/ft_puthex.c utils/ft_putptr.c print_foo/ft_print_char.c \
				print_foo/ft_print_hex.c print_foo/ft_print_decimal.c \
				print_foo/ft_print_pvoid.c print_foo/ft_print_string.c \
				print_foo/ft_print_uint.c print_foo/ft_printf.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Werror -Wall -Wextra

%.o: %.c
	$(CC) -Iincludes $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	ar rcs  $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

