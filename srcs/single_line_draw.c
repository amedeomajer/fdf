/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_line_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:45:48 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 18:01:56 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_iso_single_line(t_data *d)
{
	t_xy	xy1;
	t_xy	xy2;

	d->i = 0;
	d->x1 = d->start_x;
	d->x2 = d->start_x + d->zoom;
	while (d->i < d->width - 1)
	{
		xy1.x = (d->x1 - 0) * cos(M_PI * d->angle / 180);
		xy1.y = (-d->depth[0][d->i] * d->z_scale + (d->x1 + 0)) \
												* sin(M_PI * d->angle / 180);
		xy2.x = (d->x2 - 0) * cos(M_PI * d->angle / 180);
		xy2.y = (-d->depth[0][d->i + 1] * d->z_scale + (d->x2 + 0)) * \
													sin(M_PI * d->angle / 180);
		if (d->depth[0][d->i] || d->depth[0][d->i + 1])
			color_dda(xy1, xy2, d);
		else
			dda(xy1, xy2, d);
		d->i++;
		d->x1 = d->x2;
		d->x2 = d->x2 + d->zoom;
	}
}
