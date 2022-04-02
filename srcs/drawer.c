/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:23:28 by amajer            #+#    #+#             */
/*   Updated: 2022/04/02 19:06:35 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	dda(float x1, float y1, float x2, float y2, t_data *d)
{
	float	dx;
	float	dy;
	float	steps;
	float	x_increment;
	float	y_increment;

	dx = x2 - x1;
	dy = y2 - y1;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_increment = dx / steps;
	y_increment = dy / steps;
	d->i = 1;
	while (d->i <= steps)
	{
		my_mlx_pixel_put(d, x1, y1, 0xffffff);
		x1 = x1 + x_increment;
		y1 = y1 + y_increment;
		d->i++;
	}
}

void	color_dda(float x1, float y1, float x2, float y2, t_data *d)
{
	float	dx;
	float	dy;
	float	steps;
	float	x_increment;
	float	y_increment;

	dx = x2 - x1;
	dy = y2 - y1;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_increment = dx / steps;
	y_increment = dy / steps;
	d->i = 1;
	while (d->i <= steps)
	{
		my_mlx_pixel_put(d, x1, y1, 0xff00ff);
		x1 = x1 + x_increment;
		y1 = y1 + y_increment;
		d->i++;
	}
}

void	draw_map1(t_data *d)
{
	int		i;
	int		j;

	d->x1 = 0;
	d->x2 =	d->zoom;
	d->y1 = 0;
	d->y2 = d->zoom;
	j = 0;
	while (j < d->height)
	{
		d->x1 = 0;
		d->x2 = d->zoom;
		i = 0;
		while(i < d->width)
		{
			d->iso_x1 = ((d->x1 - d->y1) * cos(d->angle) + 750);
			d->iso_y1 = ((d->x1 + d->y1) * sin(d->angle) - (d->depth[j][d->i] * 2) + 200);
			d->iso_x2 = ((d->x2 - d->y2) * cos(d->angle) + 750);
			d->iso_y2 = ((d->x2 + d->y2) * sin(d->angle) - (d->depth[j][d->i] * 2) + 200);
			if (d->depth[j][i] > 0)
				color_dda(d->iso_x1, d->iso_y1, d->iso_x2, d->iso_y1, d);  // draw on elevates x axis
			else
				dda(d->iso_x1, d->iso_y1, d->iso_x2, d->iso_y1, d);			// draw on x axis
			if (d->depth[j][i] > 0)
				color_dda(d->iso_x1, d->iso_y1, d->iso_x1, d->iso_y2, d);  // daw on elevated y axis
			else
				dda(d->iso_x1, d->iso_y1, d->iso_x1, d->iso_y2, d);       // draw on y axis
			d->x1 = d->x2;
			d->x2 = d->x2 + d->zoom;
			i++;
		}
		d->y1 = d->y2;
		d->y2 = d->y2 + d->zoom;
		j++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_window, d->img, 0, 0);
	mlx_loop(d->mlx_ptr);
}

// int	mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

	//DRAW STAR
	// dda(30, 30, 500, 500, d);
	// dda(220, 30, 500, 500, d);
	// dda(500, 30, 500, 500, d);
	// dda(30, 350, 500, 500, d);
	// dda(30, 650, 500, 500, d);
	// dda(350, 970, 500, 500, d);
	// dda(770, 30, 500, 500, d);
	// dda(970, 30, 500, 500, d);
	// dda(30, 220, 500, 500, d);
	// dda(30, 500, 500, 500, d);
	// dda(30, 770, 500, 500, d);
	// dda(500, 500, 970, 220, d);
	// dda(500, 500, 970, 500, d);
	// dda(500, 500, 970, 770, d);
	// dda(500, 500, 970, 970, d);
	// dda(500, 500, 30, 970, d);
	// dda(500, 500, 220, 970, d);
	// dda(500, 500, 500, 970, d);
	// dda(500, 500, 770, 970, d);