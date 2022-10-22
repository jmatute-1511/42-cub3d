# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 18:16:18 by jmatute-          #+#    #+#              #
#    Updated: 2022/10/22 20:42:00 by jmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OS
OS = $(shell uname -s)


#SOURCES
SRC_C= main.c

#DIRECTORYS
SRC_DIR = src/
OBJ_DIR = obj/
HEADER_DIR = includes/
LIBFT_DIR	= libft/ 

#INCLUDES
HEADERS_I = cub3d.h 

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

ifeq ($(OS), Darwin)
	LIBS =	-I include -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/"
else
	LIBS	=	-I include -lglfw -ldl -I ./MLX42/include/MLX42
endif

$(NAME) :	$(OBJ) 
			@make -sC $(LIBFT_DIR)
			@make -sC ./MLX42
			@cp ./libft/libft.a .
			@cp ./MLX42/libmlx42.a .
			@$(CC) $(CFLAGS) $(OBJ) libmlx42.a $(LIBS) libft.a -o $(NAME)

$(OBJS_DIR)%.o:	$(SRC)
				@$(CC) $(CFLAGS) -I $(LIBFT_DIR)  -c $< -o $@

all:		$(NAME)

clean:
			@make -sC $(LIBFT_DIR) clean
			@make -sC ./MLX42 clean
			$(RM) $(OBJ) libft.a libmlx42.a

fclean:		clean
			$(RM) $(NAME)
			@make -sC $(LIBFT_DIR) fclean
			@make -sC ./MLX42 fclean

re:			fclean all

.PHONY: all re clean fclean