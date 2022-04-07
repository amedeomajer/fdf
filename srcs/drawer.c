/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:23:28 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 15:42:56 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric_helper(t_data *d)
{
	t_xy	*xy;

	xy = projection_call(d);
	if (d->depth[d->j][d->i] > 0 || d->depth[d->j][d->i + 1] > 0)
		color_dda(xy[0], xy[1], d);
	else
		dda(xy[0], xy[1], d);
	if (d->depth[d->j][d->i] > 0 || d->depth[d->j + 1][d->i] > 0)
		color_dda(xy[0], xy[2], d);
	else
		dda(xy[2], xy[0], d);
	if ((d->i == d->width - 1) && ((d->depth[d->j][d->i] > 0) || \
												d->depth[d->j + 1][d->i] > 0))
		color_dda(xy[1], xy[3], d);
	else
		dda(xy[1], xy[3], d);
	if ((d->j == d->height - 1) && ((d->depth[d->j + 1][d->i] > 0 \
										|| d->depth[d->j + 1][d->i + 1] > 0)))
		color_dda(xy[2], xy[3], d);
	else
		dda(xy[2], xy[3], d);
	d->x1 = d->x2;
	d->x2 = d->x2 + d->zoom;
	d->i++;
	free(xy);
}

void	draw_isometric(t_data *d)
{
	d->j = 0;
	d->y1 = d->start_y;
	d->y2 = d->start_y + d->zoom;
	while (d->j < d->height - 1)
	{
		d->x1 = d->start_x;
		d->x2 = d->start_x + d->zoom;
		d->i = 0;
		while (d->i < d->width - 1)
			isometric_helper(d);
		d->y1 = d->y2;
		d->y2 = d->y2 + d->zoom;
		d->j++;
	}
}

void	draw_top_line(t_data *d, t_xy xy[4])
{
	if (d->depth[d->j][d->i] > 0 || d->depth[d->j][d->i + d->k] > 0)
	{
		color_dda(xy[0], xy[1], d);
		if (d->i == d->width - 1)
			color_dda(xy[1], xy[3], d);
	}
	else
	{
		dda(xy[0], xy[1], d);
		if (d->i == d->width - 1)
			dda(xy[1], xy[3], d);
	}
}

void	parallel_helper(t_data *d, t_xy xy[4])
{
	d->k = 1;
	if (d->j + d->k == d->height || d->i + d->k == d->width)
		d->k = 0;
	draw_top_line(d, xy);
	if (d->depth[d->j][d->i] > 0 || d->depth[d->j + d->k][d->i] > 0)
	{
		color_dda(xy[0], xy[2], d);
		if (d->j == d->height - 1)
			color_dda(xy[2], xy[3], d);
	}
	else
	{
		dda(xy[0], xy[2], d);
		if (d->j == d->height - 1)
			dda(xy[2], xy[3], d);
	}
	d->x1 = d->x2;
	d->x2 = d->x2 + d->zoom;
	d->i++;
}

void	draw_parallel(t_data *d)
{
	t_xy	xy[4];

	d->j = 0;
	d->y1 = 0;
	d->y2 = 0;
	if (d->height > 1)
		initialize_y_for_multiline(d);
	while (d->j < d->height)
	{
		d->x1 = d->start_x;
		d->x2 = d->start_x + d->zoom;
		d->i = 0;
		while (d->i < d->width)
		{
			assign_values(xy, d);
			parallel_helper(d, xy);
		}
		if (d->height > 1)
		{
			d->y1 = d->y2;
			d->y2 = d->y2 + d->zoom;
		}
		d->j++;
	}
}
