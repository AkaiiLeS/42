# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:28:43 by salsoysa          #+#    #+#              #
#    Updated: 2025/04/30 12:52:56 by salsoysa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -I .

AR = ar rcs

LIBC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalpha.c ft_isalnum.c \
	   ft_isdigit.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_isprint.c \
	   ft_memcmp.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
	   ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlen.c \
	   ft_strlcpy.c ft_strnstr.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c ft_putnbr_fd.c ft_atol.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_striteri.c ft_putendl_fd.c \
	   get_next_line.c ft_print_char.c ft_printf.c ft_print_decimal.c \
	   ft_print_hex.c ft_print_pvoid.c ft_print_string.c ft_print_uint.c \
	   ft_putnbr.c ft_puthex.c ft_putptr.c ft_putunbr.c

#LIST = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
#		   ft_lstsize_bonus.c ft_lstlast_bonus.c \
#		   ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
#		   ft_lstclear_bonus.c ft_lstiter_bonus.c \
#		   ft_lstmap_bonus.c

SRCS = ${LIBC} ${LIST}

OBJS = ${SRCS:.c=.o}

.c.o: $(SRC)
	@${CC} ${CFLAGS} -c -o $@ $<

${NAME}: ${OBJS}
	@$(AR) $@ $^

all:	${NAME}

clean:
	@rm -f *.o
	@echo "Clean Done !"

fclean: clean
	@rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
