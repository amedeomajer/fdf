# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amajer <amajer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 15:48:30 by amajer            #+#    #+#              #
#    Updated: 2022/04/05 15:36:55 by amajer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#check into $(addprefix to add "./srcs" before every file in compilation)

# MANUAL ALIASES
# alias m_mlx='man /usr/share/man/man3/mlx.1'
# alias m_mlx_loop='man /usr/share/man/man3/mlx_loop.1'
# alias m_mlx_newi='man /usr/share/man/man3/mlx_new_image.1'
# alias m_mlx_neww='man /usr/share/man/man3/mlx_new_window.1'
# alias m_mlx_pxpt='man /usr/share/man/man3/mlx_pixel_put.1'

# Executable name
NAME := fdf

# Directories
SRC_DIR := ./srcs
INC_DIR := ./includes
LIBRARY := libft/libft.a
# srcs and object files
C_FILES := main.c my_mlx_pixel_put.c error.c xyz_calculator.c drawer.c dda.c projection.c zoom.c events.c move.c
O_FILES := main.o my_mlx_pixel_put.o error.o xyz_calculator.o drawer.o dda.o projection.o zoom.o events.o move.o
SRCS := $(addprefix $(SRC_DIR)/,$(C_FILES))

# conpiler and flags
GCC := gcc -Wall -Wextra -Werror
FRAMEWORK := -lmlx -framework OpenGL -framework AppKit

all:  $(NAME)	

$(NAME): $(O_FILES) $(LIBRARY)
#	mkdir objects
	$(GCC) $(O_FILES) $(LIBRARY) $(FRAMEWORK) -o $(NAME) -g

%.o: $(SRC_DIR)/%.c
	$(GCC) -c $(SRCS) $< -g

$(LIBRARY):
	make -C ./libft

clean:
	make clean -C ./libft 
	rm -f *.o

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all
