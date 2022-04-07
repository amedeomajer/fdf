/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:35:14 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 16:16:37 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	move_events(int key, void *param)
{
	if (key == 123)
		move_left((t_data *)param);
	if (key == 124)
		move_right((t_data *)param);
	if (key == 125)
		move_down((t_data *)param);
	if (key == 126)
		move_up((t_data *)param);
	return (0);
}

int	key_event(int key, void *param)
{
	if (key > 122 && key < 127)
		move_events(key, param);
	if (key == 53)
		esc((t_data *)param);
	if (key == 24)
		zoom_in((t_data *)param);
	if (key == 27)
		zoom_out((t_data *)param);
	if (key == 35)
		switch_to_parallel((t_data *)param);
	if (key == 43)
		change_angle_minnus((t_data *)param);
	if (key == 47)
		change_angle_plus((t_data *)param);
	if (key == 6)
		z_scale_minus((t_data *)param);
	if (key == 7)
		z_scale_plus((t_data *)param);
	return (0);
}
