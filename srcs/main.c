/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:18:09 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 16:14:07 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	initialize_struct(t_data *d)
{
	d->width = 0;
	d->height = 0;
	d->depth = NULL;
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		error("failed to initialize mlx_ptr");
	d->mlx_window = mlx_new_window(d->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, \
																		"fdf");
	if (!d->mlx_window)
		error("failed to initialize mlx_window");
	d->img = mlx_new_image(d->mlx_ptr, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
																	&d->endian);
	d->angle = 30;
	d->zoom = 15;
	d->start_x = 0;
	d->start_y = 0;
	d->z_scale = 1;
	d->i = 0;
	d->j = 0;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	d;

	initialize_struct(&d);
	if (argc != 2)
		error("input ONE argument!");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("open failed!");
	count_lines(fd, &d);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("open failed!");
	create_matrix(&d);
	convert_map_to_int_array(fd, &d);
	if (d.height > 1)
		draw_isometric(&d);
	else
		draw_iso_single_line(&d);
	mlx_put_image_to_window(d.mlx_ptr, d.mlx_window, d.img, 0, 0);
	mlx_hook(d.mlx_window, ON_DESTROY, 0, esc, &d);
	mlx_hook(d.mlx_window, ON_KEYDOWN, (1L << 0), key_event, (void *)&d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
