# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 09:03:13 by salsoysa          #+#    #+#              #
#    Updated: 2024/11/13 12:54:29 by salsoysa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalpha.c ft_isalnum.c \
				ft_isdigit.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_isprint.c \
				ft_memcmp.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
				ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c \
				ft_strlen.c ft_strlcpy.c ft_strnstr.c ft_split.c

SUPP = ft_substr.c ft_strjoin.c ft_strtrim.c

SRCS = ${LIBC} ${SUPP}

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re
