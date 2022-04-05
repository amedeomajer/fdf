/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:06:57 by amajer            #+#    #+#             */
/*   Updated: 2022/04/05 16:08:11 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	dda(t_xy xy1, t_xy xy2, t_data *d)
{
	float	dx;
	float	dy;
	float	steps;
	float	x_increment;
	float	y_increment;

	dx = xy2.x - xy1.x;
	dy = xy2.y - xy1.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_increment = dx / steps;
	y_increment = dy / steps;
	dx = d->i;
	d->i = 1;
	while (d->i <= steps)
	{
		my_mlx_pixel_put(d, (int)xy1.x + 400, (int)xy1.y + 400, 0x08737f);
		xy1.x = xy1.x + x_increment;
		xy1.y = xy1.y + y_increment;
		d->i++;
	}
	d->i = dx;
}

void	color_dda(t_xy xy1, t_xy xy2, t_data *d)
{
	float	dx;
	float	dy;
	float	steps;
	float	x_increment;
	float	y_increment;

	dx = xy2.x - xy1.x;
	dy = xy2.y - xy1.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_increment = dx / steps;
	y_increment = dy / steps;
	dx = d->i;
	d->i = 1;
	while (d->i <= steps)
	{
		my_mlx_pixel_put(d, (int)xy1.x + 400, (int)xy1.y + 400, 0xffffff);
		xy1.x = xy1.x + x_increment;
		xy1.y = xy1.y + y_increment;
		d->i++;
	}
	d->i = dx;
}
