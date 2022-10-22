# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 18:16:18 by jmatute-          #+#    #+#              #
#    Updated: 2022/10/22 21:47:39 by jmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OS
OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	LIBS =	-I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
else
	LIBS =	-I include -lglfw -ldl -I ./MLX42/include/MLX42
endif

#COLOR
YELLOW	= \033[33;1m

#SOURCES
SRC_C= main.c

#DIRECTORYS
SRC_DIR = src/
OBJ_DIR = obj/
GNL_DIR = get_next_line/
HEADER_DIR = includes/
LIBFT_DIR= libft/ 

#INCLUDES
HEADERS_I = cub3d.h 

#LIBRARYS COMPILE
MLX = MLX42/libmlx42.a
LIBFT = libft/libft.a
GNL = get_next_line/get_next_line.a

#OBJECTS
OBJS = $(SRC_C:.c=.o)

# JOIN ALL
SRC = $(addprefix $(SRC_DIR), $(SRC_C))
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))
HEADERS = $(addprefix $(HEADER_DIR), $(HEADERS_I))

#NAME OF EXECUTABlE
NAME = cub3d

# RULES OF COMPILE
CC = gcc
RM = rm -rf
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=addressç

$(NAME) :	$(OBJ) 
			@make -sC $(LIBFT_DIR)
			@make -sC $(GNL_DIR)
			@make -sC ./MLX42
			@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBS) $(LIBFT) $(GNL) -o $(NAME)
			@echo "$(YELLOW)YOUR CUB3D IS READY"

$(OBJS_DIR)%.o:	$(SRC)
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -I $(LIBFT_DIR)  -c $< -o $@

all:		$(NAME)

clean:
			@make -sC $(LIBFT_DIR) clean
			@make -sC ./MLX42 fclean
			@make -sC $(GNL_DIR) clean
			$(RM) $(OBJ) libft.a libmlx42.a get_next_line.a

fclean:		clean
			$(RM) $(NAME)
			@make -sC $(LIBFT_DIR) fclean
			@make -sC $(GNL_DIR) fclean

re:			fclean all

.PHONY: all re clean fclean