/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:42:03 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 14:07:48 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

# include <mlx.h>
# include <fcntl.h>

# include <stdio.h>
# include <math.h>

# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 700

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_xy
{
	float	x;
	float	y;
}				t_xy;

typedef struct s_data
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
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	angle;
	int		zoom;
	int		start_x;
	int		start_y;
	int		i;
	int		j;
	int		k;
	int		z_scale;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	error(char *str);
void	count_lines(int fd, t_data *d);
void	convert_map_to_int_array(int fd, t_data *d);
void	create_matrix(t_data *d);
void	draw_isometric(t_data *d);
void	draw_parallel(t_data *d);
void	dda(t_xy xy1, t_xy xy2, t_data *d);
void	color_dda(t_xy xy1, t_xy xy2, t_data *d);
t_xy	projection(float x, float y, float z, t_data *d);
t_xy	*projection_call(t_data *d);
int		zoom_in(t_data *d);
int		zoom_out(t_data *d);
int		esc(t_data *d);
int		switch_to_parallel(t_data *d);
int		key_event(int key, void *param);
int		move_left(t_data *d);
int		move_right(t_data *d);
int		move_up(t_data *d);
int		move_down(t_data *d);
void	draw_iso_single_line(t_data *d);
void	initialize_y_for_multiline(t_data *d);
void	assign_values(t_xy *xy, t_data *d);

#endif