/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:35:14 by amajer            #+#    #+#             */
/*   Updated: 2022/04/05 18:52:19 by amajer           ###   ########.fr       */
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

int	key_event(int key, void *param)
{
	printf(" %i	", key);
	if (key == 53)
		esc((t_data *)param);
	if (key == 24)
		zoom_in((t_data *)param);
	if (key == 27)
		zoom_out((t_data *)param);
	if (key == 123)
		move_left((t_data *)param);
	if (key == 124)
		move_right((t_data *)param);
	if (key == 126)
		move_up((t_data *)param);
	if (key == 125)
		move_down((t_data *)param);
	if (key == 35)
		switch_to_parallel((t_data *)param);
	return (0);
}
