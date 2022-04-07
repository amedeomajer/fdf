/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:32:52 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 14:08:58 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	zoom_in(t_data *d)
{
	d->zoom = d->zoom + 5;
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

int	zoom_out(t_data *d)
{
	d->zoom = d->zoom - 5;
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

int	z_scale_plus(t_data *d)
{
	d->z_scale = d->z_scale + 5;
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