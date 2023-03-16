# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romartin <romartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 09:28:04 by romartin          #+#    #+#              #
#    Updated: 2022/12/01 11:55:09 by romartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_isdigit.c ft_memset.c ft_strdup.c ft_strrchr.c \
		ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c \
		ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
		ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c \
		ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
		ft_isalpha.c ft_memcpy.c ft_split.c ft_strncmp.c ft_strmapi.c \
		ft_isascii.c ft_strchr.c ft_memmove.c ft_strnstr.c ft_striteri.c

OBJS	=  ${SRCS:.c=.o}

.c.o	:
		@gcc -Wall -Wextra -Werror -c $^

${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all
