# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 08:50:00 by aperin            #+#    #+#              #
#    Updated: 2022/10/12 08:51:59 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

%.o : %.c
			gcc -Wall -Wextra -Werror -c -I./includes $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs $(NAME) $(OBJS)

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
