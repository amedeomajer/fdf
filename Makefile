# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amajer <amajer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 15:48:30 by amajer            #+#    #+#              #
#    Updated: 2022/04/07 16:40:39 by amajer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME := fdf

# Directories
SRC_DIR := ./srcs
LIBRARY := libft/libft.a
# srcs and object files
C_FILES := dda.c drawer.c drawer2.c error.c events.c events2.c main.c move.c \
	my_mlx_pixel_put.c projection.c single_line_draw.c xyz_calculator.c zoom.c
O_FILES := dda.o drawer.o drawer2.o error.o events.o events2.o main.o move.o \
	my_mlx_pixel_put.o projection.o single_line_draw.o xyz_calculator.o zoom.o
SRCS := $(addprefix $(SRC_DIR)/,$(C_FILES))

# conpiler and flags
GCC := gcc -Wall -Wextra -Werror
FRAMEWORK := -lmlx -framework OpenGL -framework AppKit

all:  $(NAME)	

$(NAME): $(O_FILES) $(LIBRARY)
	$(GCC) $(O_FILES) $(LIBRARY) $(FRAMEWORK) -o $(NAME) -g

%.o: $(SRC_DIR)/%.c
	$(GCC) -c $(SRCS) $< -g

$(LIBRARY):
	make -C ./libft

clean:
	make clean -C ./libft 
	rm -f $(O_FILES)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all
