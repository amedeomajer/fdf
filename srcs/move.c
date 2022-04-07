/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:34:01 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 17:34:02 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	move_left(t_data *d)
{
	d->start_x = d->start_x - 30;
	mlx_destroy_image(d->mlx_ptr, d->img);
	d->img = mlx_new_image(d->mlx_ptr, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
																&d->endian);
	if (d->height > 1)
		draw_isometric(d);
	else
		draw_iso_single_line(d);
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_window, d->img, 0, 0);
	return (0);
}

int	move_right(t_data *d)
{
	d->start_x = d->start_x + 30;
	mlx_destroy_image(d->mlx_ptr, d->img);
	d->img = mlx_new_image(d->mlx_ptr, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
																	&d->endian);
	if (d->height > 1)
		draw_isometric(d);
	else
		draw_iso_single_line(d);
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_window, d->img, 0, 0);
	return (0);
}

int	move_up(t_data *d)
{
	d->start_y = d->start_y - 30;
	mlx_destroy_image(d->mlx_ptr, d->img);
	d->img = mlx_new_image(d->mlx_ptr, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
																	&d->endian);
	if (d->height > 1)
		draw_isometric(d);
	else
		draw_iso_single_line(d);
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_window, d->img, 0, 0);
	return (0);
}

int	move_down(t_data *d)
{
	d->start_y = d->start_y + 30;
	mlx_destroy_image(d->mlx_ptr, d->img);
	d->img = mlx_new_image(d->mlx_ptr, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
																	&d->endian);
	if (d->height > 1)
		draw_isometric(d);
	else
		draw_iso_single_line(d);
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_window, d->img, 0, 0);
	return (0);
}
