# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clnicola <clnicola@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/21 14:52:13 by clnicola          #+#    #+#              #
#    Updated: 2025/09/04 10:38:36 by clnicola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
C_FLAGS = -Wall -Wextra -Werror
LINK_FLAG = -L$(MINILIBX_DIR) -lmlx_Linux -lX11 -lXext

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a

SOURCES = \
	fract-ol.c\
	init.c\
	rendering.c\
	maths.c\
	handlers.c\


HEADER = -I.

OBJ = $(SOURCES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(LINK_FLAG) -o $(NAME)

clean: 
	rm -rf $(OBJ)
	@echo "Temp files removed"

fclean: clean
	rm -rf $(NAME)
	@echo "Temp files and binaries removed."

re: fclean all
