/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyz_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amajer <amajer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:54:47 by amajer            #+#    #+#             */
/*   Updated: 2022/04/07 16:15:18 by amajer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	**ft_free(char **str, int a)
{
	while (a >= 0)
		free(str[a--]);
	free(str);
	return (NULL);
}

void	create_matrix(t_data *d)
{
	int	i;

	i = 0;
	d->depth = (int **)malloc(sizeof(int *) * (d->height + 1));
	if (!d->depth)
		error("**depth allocation failed");
	d->depth[d->height] = NULL;
	while (i < d->height)
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
	int		gnl_ret;

	gnl_ret = get_next_line(fd, &line);
	if (gnl_ret == 0)
		error("file is empty!");
	while (gnl_ret == 1)
	{
		values_array = ft_strsplit(line, ' ');
		while (values_array[d->i] != 0)
			d->i++;
		if (!d->height)
			d->width = d->i;
		if (d->i != d->width)
			error("file's lines are different sizes");
		d->height++;
		ft_strdel(&line);
		ft_free(values_array, d->width);
		values_array = NULL;
		gnl_ret = get_next_line(fd, &line);
	}
	if (gnl_ret == -1)
		error("read malfunction");
	d->i = 0;
}

void	convert_map_to_int_array(int fd, t_data *d)
{
	char	*line;
	char	**values_array;
	int		gnl_ret;

	gnl_ret = get_next_line(fd, &line);
	while (gnl_ret == 1)
	{
		d->i = 0;
		values_array = ft_strsplit(line, ' ');
		while (values_array[d->i] != NULL)
		{
			d->depth[d->j][d->i] = ft_atoi(values_array[d->i]);
			d->i++;
		}
		ft_strdel(&line);
		d->j++;
		ft_free(values_array, d->width);
		values_array = NULL;
		gnl_ret = get_next_line(fd, &line);
	}
	if (line)
		ft_strdel(&line);
	if (gnl_ret == -1)
		error("read malfunction");
}
