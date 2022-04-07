/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:46:34 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 16:07:00 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_d(t_data *d)
{
	int	j;

	j = 0;
	while (j < d->height)
	{
		free(d->depth[j]);
		d->depth[j] = NULL;
		j++;
	}
	free(d->depth);
	d->depth = NULL;
}

int	change_angle_minnus(t_data *d)
{
	d->angle = d->angle - 5;
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

int	change_angle_plus(t_data *d)
{
	d->angle = d->angle + 5;
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

int	esc(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img);
	mlx_destroy_window(d->mlx_ptr, d->mlx_window);
	free_d(d);
	system("leaks fdf");
	exit(0);
	return (0);
}

int	switch_to_parallel(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img);
	d->img = mlx_new_image(d->mlx_ptr, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
																	&d->endian);
	draw_parallel(d);
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_window, d->img, 0, 0);
	return (0);
}
