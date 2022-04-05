/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:40:25 by amajer            #+#    #+#             */
/*   Updated: 2022/04/05 16:44:11 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < WINDOW_WIDTH - 2 && y < WINDOW_HEIGHT - 2 && x > 1 && y > 1)
	{
		dst = data->addr + (y * data->line_length + x * 4);
		*(unsigned int *)dst = color;
	}
}
