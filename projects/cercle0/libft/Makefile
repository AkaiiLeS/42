# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 09:03:13 by salsoysa          #+#    #+#              #
#    Updated: 2025/03/05 14:56:46 by salsoysa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalpha.c ft_isalnum.c \
				ft_isdigit.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_isprint.c \
				ft_memcmp.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
				ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c \
				ft_strlen.c ft_strlcpy.c ft_strnstr.c

SUPP = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
				ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_striteri.c \
				ft_putendl_fd.c

BSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

SRCS = ${LIBC} ${SUPP}

SRCSF = ${LIBC} ${SUPP} ${BSRC}

OBJS = ${SRCS:.c=.o}

OBJSF = ${SRCSF:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all:	${NAME}

bonus: ${OBJSF}
	ar -rsc ${NAME} ${OBJSF}

clean:
	rm -f ${OBJSF}

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus
