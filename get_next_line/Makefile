# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 20:57:50 by jmatute-          #+#    #+#              #
#    Updated: 2022/10/22 21:02:37 by jmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= get_next_line.c get_next_line_utils.c

SRCS_B	= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

NAME	= get_next_line.a

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME} ${OBJS_B}

clean:
			${RM} ${OBJS} ${OBJS_B}
			
bonus:		${OBJS_B} ${OBJS}
			ar rc ${NAME} ${OBJS_B}
			ranlib ${NAME}
			
fclean:		clean
			${RM} ${NAME} ${OBJS_B}

re:			fclean all

.PHONY:		bonus all clean fclean re
