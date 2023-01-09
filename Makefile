# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 18:16:18 by jmatute-          #+#    #+#              #
#    Updated: 2023/01/09 17:19:30 by jmatute-         ###   ########.fr        #
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
BLUE	:= \033[34;1m
RESET	:= \033[0m

#SOURCES
SRC_C= cub3d.c map.c colisions.c tools.c texture.c check_map.c  error_map.c \
	tools_map.c final_check.c draw_3d.c

#DIRECTORYS
SRC_DIR = src/
OBJ_DIR = $(SRC_DIR)obj/
GNL_DIR = $(SRC_DIR)get_next_line/
HEADER_DIR = $(SRC_DIR)includes/
LIBFT_DIR= $(SRC_DIR)libft/ 

#INCLUDES
HEADERS_I = cub3d.h 

#LIBRARYS COMPILE
MLX = MLX42/libmlx42.a
LIBFT = src/libft/libft.a
GNL = src/get_next_line/get_next_line.a

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
CFLAGS	= #-fsanitize=addressç

all: libs obj $(NAME)

$(NAME) :	$(OBJ) 

			@$(CC) $(CFLAGS) $(OBJ) $(GNL) $(MLX) $(LIBS) $(LIBFT)  -lm  -o $(NAME)
			@echo "$(BLUE)YOUR CUB3D🧊 IS READY"
obj:

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@echo "$(BLUE)Compiling:$(RESET) $(notdir $<)"
				@$(CC) $(CFLAGS) -I $(LIBFT_DIR)  -c $< -o $@


libs:
		@make -sC $(LIBFT_DIR)
		@make -sC $(GNL_DIR)
		@make -sC ./MLX42
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