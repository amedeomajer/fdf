/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:54:47 by amajer            #+#    #+#             */
/*   Updated: 2022/03/31 15:24:24 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	create_matrix(t_data *d)
{
	int	i;

	i = 0;
	d->depth = (int **)malloc(sizeof(int *) * (d->height + 1));
	if (!d->depth)
		error("**depth allocation failed");
	d->depth[d->height] = NULL;
	while(i < d->height)
	{
		d->depth[i] = (int *)malloc(sizeof(int ) * d->width);
		if (!d->depth[i])
			error("*depth allocation failed");
		i++;
	}
}


/*
	loops through to count lines and how many data pieces are in one line
*/

void	count_lines(int fd, t_data *d)
{
	char	*line;
	char	**values_array;
	int		i;

	while (get_next_line(fd, &line))
	{
		i = 0;
		values_array = ft_strsplit(line, ' ');
		while (values_array[i] != 0)
			i++;
		if (!d->height)
			d->width = i;
		if (i != d->width)
			error("file lines are different sizes");
		d->height++;
		ft_strdel(&line);
	}
	i = 0;
	while (values_array[i] != 0)
	{
		ft_strdel(&values_array[i]);
		i++;
	}
}

void	convert_map_to_int_array(int fd, t_data *d)
{
	char	*line;
	char	**values_array;
	int		i;
	int		j;

	j = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		values_array = ft_strsplit(line, ' ');
		while (values_array[i] != NULL)
		{
			d->depth[j][i] = ft_atoi(values_array[i]);
			i++;
		}
		ft_strdel(&line);
		j++;
		i = 0;
		while (values_array[i] != 0)
		{
			ft_strdel(&values_array[i]);
			i++;
		}
	}
}