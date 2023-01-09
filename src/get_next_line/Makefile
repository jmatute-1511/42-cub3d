# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 20:57:50 by jmatute-          #+#    #+#              #
#    Updated: 2023/01/09 17:14:16 by jmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= get_next_line.c 

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

NAME	= get_next_line.a

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS} ../libft/libft.a
			ranlib ${NAME}

all:		${NAME} $

clean:
			${RM} ${OBJS} 
			
fclean:		clean
			${RM} ${NAME} ${OBJS_B}

re:			fclean all

.PHONY:		bonus all clean fclean re
