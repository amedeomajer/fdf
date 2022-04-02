/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:23:31 by amajer            #+#    #+#             */
/*   Updated: 2022/03/24 19:13:52 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

void	print_square(t_data img, int x, int y, int side_length)
{
	int	i;
	int color = 0xffffff;
// big square
	i = -1;

	while (++i <= side_length)
		my_mlx_pixel_put(&img, x++, y, color-- / 2);
	i = -1;
	while (++i <= side_length)
		my_mlx_pixel_put(&img, x, y++, color-- / 3);
	i = -1;
	while (++i <= side_length)
		my_mlx_pixel_put(&img, x--, y, color-- / 4);
	i = -1;
	while (++i <= side_length)
		my_mlx_pixel_put(&img, x, y--, color-- / 6);
}

int		main()
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_data	img;
	int		x;
	int		y;
	int		side_length;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "suca");
	img.img = mlx_new_image(mlx_ptr, WINDOW_WIDTH - 1, WINDOW_HEIGHT -1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	x = 25;
	y = 25;
	side_length = 200;
	while (x < 400)
	{
		print_square(img, x, y, side_length);
		x = x + 5;
		y = y + 5;
		side_length = side_length - 10;
	}
	x = 150;
	y = 150;
	side_length = 200;
	while (x < 400)
	{
		print_square(img, x, y, side_length);
		x = x + 5;
		y = y + 5;
		side_length = side_length - 10;
	}
	x = 275;
	y = 25;
	side_length = 200;
	while (x < 400)
	{
		print_square(img, x, y, side_length);
		x = x + 5;
		y = y + 5;
		side_length = side_length - 10;
	}
	x = 275;
	y = 275;
	side_length = 200;
	while (x < 400)
	{
		print_square(img, x, y, side_length);
		x = x + 5;
		y = y + 5;
		side_length = side_length - 10;
	}
	x = 25;
	y = 275;
	side_length = 200;
	while (x < 400)
	{
		print_square(img, x, y, side_length);
		x = x + 5;
		y = y + 5;
		side_length = side_length - 10;
	}

	mlx_put_image_to_window(mlx_ptr, mlx_window, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
