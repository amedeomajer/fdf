/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:15:50 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 16:06:00 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	initialize_y_for_multiline(t_data *d)
{
	d->y1 = d->start_y;
	d->y2 = d->start_y + d->zoom;
}

void	assign_values(t_xy *xy, t_data *d)
{
	xy[0].x = d->x1;
	xy[0].y = d->y1;
	xy[1].x = d->x2;
	xy[1].y = d->y1;
	xy[2].x = d->x1;
	xy[2].y = d->y2;
	xy[3].x = d->x2;
	xy[3].y = d->y2;
}
