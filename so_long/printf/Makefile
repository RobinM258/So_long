# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romartin <romartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 10:51:38 by romartin          #+#    #+#              #
#    Updated: 2022/12/02 12:02:32 by romartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_unsigned_putnbr.c ft_hexa_min.c ft_hexa_max.c ft_pointer.c

OBJS	=  ${SRCS:.c=.o}
FLAG    = -Wall -Werror -Wextra

all : ${NAME}


$(NAME) : $(OBJS) 
		@make -C ./libft
		@cp ./libft/libft.a $(NAME)
		ar rc $(NAME) $(OBJS) 

.c.o	:
		gcc  -c $^ $(FLAG)

clean :
		rm -f ${OBJS}
		make -C libft/ clean

fclean : clean
		rm -f ${NAME}
		make -C libft/ fclean

re : fclean all