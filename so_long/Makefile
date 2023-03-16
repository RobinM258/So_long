# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romartin <romartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 10:29:40 by romartin          #+#    #+#              #
#    Updated: 2023/03/16 15:00:22 by romartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsolong.a
SRCS = main.c key_hook.c ft_utils_key_hook.c init_textures.c player.c init_map_size.c ft_itoa.c enemy.c parsing.c

OBJS	=  ${SRCS:.c=.o}
FLAG    = -Wall -Werror -Wextra

all : ${NAME}


$(NAME) : $(OBJS) 
		@make -C ./printf
		@cp ./printf/libftprintf.a $(NAME)
		ar rc $(NAME) $(OBJS) 

.c.o	:
		gcc  -c $^ $(FLAG)

clean :
		rm -f ${OBJS}
		make -C printf/ clean

fclean : clean
		rm -f ${NAME}
		make -C printf/ fclean

re : fclean all