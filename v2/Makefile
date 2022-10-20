# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 08:50:00 by aperin            #+#    #+#              #
#    Updated: 2022/10/20 18:32:20 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_utils.c

B_SRCS	= ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_utils2_bonus.c

OBJS	= $(SRCS:.c=.o)

B_OBJS	= $(B_SRCS:.c=.o)

NAME	= libftprintf.a

%.o : %.c
			gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

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
