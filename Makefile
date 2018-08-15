# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 04:49:11 by amyburgh          #+#    #+#              #
#    Updated: 2018/08/09 17:53:45 by amyburgh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#gcc $SRC - I libft/include - L ./libft -lft -I ./minilibx -L ./minilibx -lmlx -framework OpenGL -framework Appkit -o $NAME

NAME = fdf

CC = gcc
CFLAFGS = -Wall -Werror -Wextra
FRAMEWORKS = -framework OpenGL -framework Appkit
DUBUG = -fsanitize=address

SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./include

LIBFT = ./libft
MLX = ./minilibx

INC_FILES = fdf.h

SRC_FILES = main.c \
			input.c \
			validate.c \
			window.c \
			initialize.c \
			matrix.c \
			render.c \
			hooks.c \
			buttons.c \
			draw_line.c \
			draw_circle.c \
			draw_map.c \
			pallet.c \
			image.c \

SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJDIR)/, $(SRC_FILES:.c=.o))
INC = $(addprefix -I, $(INCDIR))

.PHONY: all clean fclean re
.SILENT:

all: build $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(CFLAGS) -L $(LIBFT) -lft -L $(MLX) -lmlx $(FRAMEWORKS) -Ofast -o $@ $^
	echo "executable: \033[32m[CREATED]\033[0m"

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CLFAGS) $(INC) -I $(LIBFT)/include -I $(MLX) -Ofast -o $@ -c $<

build:
	mkdir -p $(OBJDIR)

clean:
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	rm -rf $(OBJDIR)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	echo "fdf: \033[32m[REMOVED]\033[0m"

re:	fclean all
