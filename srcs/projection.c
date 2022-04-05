/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:42 by amajer            #+#    #+#             */
/*   Updated: 2022/04/05 17:25:57 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_xy	projection(float x, float y, float z, t_data *d)
{
	t_xy	xy;

	xy.y = -z + (x + y) * sin(M_PI * d->angle / 180);
	xy.x = (x - y) * cos(M_PI * d->angle / 180);
	return (xy);
}

t_xy	*projection_call(t_data *d)
{
	t_xy	*xy;

	xy = (t_xy *)malloc(sizeof(t_xy) * 4);
	xy[0] = projection(d->x1, d->y1, d->depth[d->j][d->i] * (d->zoom / 3), d);
	xy[1] = projection(d->x2, d->y1, d->depth[d->j][d->i + d->k] * \
															(d->zoom / 3), d);
	xy[2] = projection(d->x1, d->y2, d->depth[d->j + d->k][d->i] * \
															(d->zoom / 3), d);
	xy[3] = projection(d->x2, d->y2, d->depth[d->j + d->k][d->i + \
													d->k] * (d->zoom / 3), d);
	return (xy);
}