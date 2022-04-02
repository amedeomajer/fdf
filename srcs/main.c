/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:18:09 by amajer            #+#    #+#             */
/*   Updated: 2022/04/02 19:06:53 by amajer           ###   ########.fr       */
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
	d->mlx_window = mlx_new_window(d->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (!d->mlx_window)
		error("failed to initialize mlx_window");
	d->img = mlx_new_image(d->mlx_ptr, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
	d->angle = 0.8;
	d->zoom = 35;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*d;

	d = (t_data*)malloc(sizeof(t_data));
	initialize_struct(d);
	if (argc != 2)
		error("input ONE argument!");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("open failed!");
	count_lines(fd, d);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("open failed!");
	create_matrix(d);
	convert_map_to_int_array(fd, d);
	
	//printf("h = %i, w = %i", d->height, d->width);
	
	
	
	
	// int	i = 0;
	// int	j = 0;
	// while (j < d->height)
	// {
	// 	i = 0;
	// 	while (i < d->width)
	// 	{
	// 		printf("%i ", d->depth[j][i]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	j++;
	// }
	d->width = 27;
	draw_map1(d);
	return (0);
}