# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 08:50:00 by aperin            #+#    #+#              #
#    Updated: 2022/10/17 11:20:42 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_printf.c srcs/utils.c

B_SRCS	= bonus/ft_printf_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c

OBJS	= $(SRCS:.c=.o)

B_OBJS	= $(B_SRCS:.c=.o)

NAME	= libftprintf.a

%.o : %.c
			gcc -Wall -Wextra -Werror -I includes/ -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs $(NAME) $(OBJS)

all:		${NAME}

bonus:		$(B_OBJS)
			ar -rcs $(NAME) $(B_OBJS)

clean:
			rm -f ${OBJS} $(B_OBJS)

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
