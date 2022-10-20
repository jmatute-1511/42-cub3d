# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmatute- <jmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 18:16:18 by jmatute-          #+#    #+#              #
#    Updated: 2022/10/20 18:28:04 by jmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SOURCES
SRC_C= main.c
USER_42 = $(USER)

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
LIBS =  MLX42/libmlx42.a -I include -lglfw -L "/Users/$(USER_42)/.brew/opt/glfw/lib/"


$(NAME) :	$(OBJ) Makefile
			@make -sC $(LIBFT_DIR)
			@cp ./libft/libft.a .
			$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME) libft.a

$(OBJS_DIR)%.o:	$(SRC)
				$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I $(HEADER_DIR)  -c $< -o $@

all:		$(NAME)

clean:
			@make -sC $(LIBFT_DIR) clean
			$(RM) $(OBJ) libft.a

fclean:		clean
			$(RM) $(NAME)
			@make -sC $(LIBFT_DIR) fclean

re:			fclean all

.PHONY: all re clean fclean