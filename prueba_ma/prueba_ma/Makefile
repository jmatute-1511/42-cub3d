# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 13:00:39 by alsanche          #+#    #+#              #
#    Updated: 2022/12/03 15:42:57 by alsanche         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = cub3d.c error_map.c map.c check_map.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

DFLAGS = -fsanitize=address

MLBFLAGS = -lmlx -framework OpenGL -framework AppKit

WFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) ../libft/libft.a

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean 