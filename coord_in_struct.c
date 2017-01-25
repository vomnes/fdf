/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_in_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:53:45 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/25 19:34:55 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_digit(char *input, t_point *coord, int *i, int *index)
{
	int index_hex;

	index_hex = 0;
	while (ft_isdigit(input[*i]))
		coord[*index].z = coord[*index].z * 10 + (input[(*i)++] - '0');
	if (input[*i] == ',')
	{
		*i += 3;
		index_hex = 0;
		while (ft_isxdigit(input[*i]))
			coord[*index].color.rgb_hex[index_hex++] = input[(*i)++];
		coord[*index].color.rgb_int =
		ft_hex_to_dec(coord[*index].color.rgb_hex);
	}
}

static void	ft_init_t_point(t_point *coord, int *index)
{
	coord[*index].x = 0;
	coord[*index].y = 0;
	coord[*index].z = 0;
	coord[*index].color.rgb_int = 0;
	ft_bzero(coord[*index].color.rgb_hex, 10);
}

static void	ft_change_line(char *input, int *i, int *y, int *x)
{
	if (input[*i] == '\n')
	{
		(*y)++;
		*x = 0;
	}
}

int			ft_coord_in_struct(char *input, t_point *coord, int len)
{
	int i;
	int x;
	int y;
	int index;

	i = 0;
	x = 0;
	y = 0;
	index = 0;
	while (input[i] && index < len)
	{
		ft_init_t_point(coord, &index);
		if (ft_isdigit(input[i]))
		{
			coord[index].x = x;
			coord[index].y = y;
			ft_get_digit(input, coord, &i, &index);
			x++;
			index++;
		}
		ft_change_line(input, &i, &y, &x);
		i++;
	}
	return (0);
}

int			ft_size_input(char *input)
{
	int i;
	int length;

	i = 0;
	length = 0;
	while (input[i] != '\0')
	{
		if (ft_isxdigit(input[i]) && (input[i + 1] == ' '
			|| input[i + 1] == '\n'))
			length++;
		i++;
	}
	return (length);
}

/*
//            ft_printf("index : %3d >> x : %2d, y : %2d, z : %2d color_hex : %6s color_int : %10d\n", index,
//            coord[index].x, coord[index].y, coord[index].z, coord[index].color.rgb_hex, coord[index].color.rgb_int);
*/
