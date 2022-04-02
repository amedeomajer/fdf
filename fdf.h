/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:42:03 by amajer            #+#    #+#             */
/*   Updated: 2022/04/02 19:06:58 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


# include "libft/libft.h"

# include <mlx.h>
# include <fcntl.h>

# include <stdio.h>
# include <math.h>

# define WINDOW_WIDTH 2000
# define WINDOW_HEIGHT 1500

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;	
	int		**depth;
	void	*mlx_ptr;
	void	*mlx_window;
	int		i;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	iso_x1;
	float	iso_y1;
	float	iso_x2;
	float	iso_y2;
	float	angle;
	int		zoom;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	error(char *str);
void	count_lines(int fd, t_data *d);
void	convert_map_to_int_array(int fd, t_data *d);
void	create_matrix(t_data *d);
void	draw_map1(t_data *d);

#endif

//  For your mandatory part, you are allowed to use the following functions:
// ◦ open, read, write, close ◦ malloc, free
// ◦ perror, strerror
// ◦ exit
// ◦ All the functions defined in the math library (-lm and man 3 math) ◦ All the functions defined in the miniLibX library.
