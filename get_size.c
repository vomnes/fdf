/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:48:37 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/01 09:26:28 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_max_length(char *input)
{
	int i;
	int length;
	int max_length;

	i = 0;
	length = 0;
	max_length = 0;
	while (input[i] != '\0')
	{
		if (ft_isxdigit(input[i]) && input[i + 1] == ' ')
			length++;
		if ((ft_isxdigit(input[i]) && input[i + 1] == '\n') ||
		(input[i] == ' ' && input[i + 1] == '\n'))
		{
			if (input[i] == ' ' && input[i + 1] == '\n')
				;
			else
				length++;
			max_length = (length > max_length) ? length : max_length;
			length = 0;
		}
		i++;
	}
	return (max_length);
}

int			ft_width(char *input)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (input[i] != '\0')
	{
		if (ft_isxdigit(input[i]) && (input[i + 1] == '\n'
		|| (input[i + 1] == ' ' && input[i + 2] == '\n')))
			width++;
		i++;
	}
	return (width);
}

void		ft_get_max_min_xyz(t_env *e)
{
	int i;
	int tmp_x;
	int tmp_y;
	int tmp_z;

	i = -1;
	tmp_x = 0;
	tmp_y = 0;
	tmp_z = 0;
	while (++i < e->data.map_total_size)
	{
		tmp_x = sqrt(2) / 2 * (e->coord[i].x - e->coord[i].y) *
		e->data.zoom;
		e->data.x_max = tmp_x > e->data.x_max ? tmp_x : e->data.x_max;
		e->data.x_min = tmp_x < e->data.x_min ? tmp_x : e->data.x_min;
		tmp_y = -0.81649658092 * e->coord[i].z * e->data.elevation +
		(1 / sqrt(6) * (e->coord[i].x + e->coord[i].y)) * e->data.zoom;
		e->data.y_max = tmp_y > e->data.y_max ? tmp_y : e->data.y_max;
		e->data.y_min = tmp_y < e->data.y_min ? tmp_y : e->data.y_min;
		tmp_z = e->coord[i].z;
		e->data.z_max = tmp_z > e->data.z_max ? tmp_z : e->data.z_max;
		e->data.z_min = tmp_z < e->data.z_min ? tmp_z : e->data.z_min;
	}
	e->data.y_min = (e->data.y_min < 0 ? -e->data.y_min : e->data.y_min);
	e->data.x_min = (e->data.x_min < 0 ? -e->data.x_min : e->data.x_min);
}
