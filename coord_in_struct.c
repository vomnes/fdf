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

static void	ft_get_digit(char *input, t_env *env, int *i, int *index)
{
	int index_hex;
	int sign;

	index_hex = 0;
	sign = 1;
	if (input[*i] == '-')
	{
		(*i)++;
		sign = -1;
	}
	while (ft_isdigit(input[*i]))
		env->coord[*index].z = env->coord[*index].z * 10 + (input[(*i)++] - '0');
	env->coord[*index].z *= sign;
	if (input[*i] == ',')
	{
		*i += 3;
		index_hex = 0;
		while (ft_isxdigit(input[*i]))
			env->coord[*index].color.rgb_hex[index_hex++] = input[(*i)++];
		env->coord[*index].color.rgb_int =
		ft_hex_to_dec(env->coord[*index].color.rgb_hex);
		env->coord[*index].color.pick_up = 1;
	}
}

static void	ft_init_t_point(t_env *env, int *index)
{
	env->coord[*index].x = 0;
	env->coord[*index].y = 0;
	env->coord[*index].z = 0;
	env->coord[*index].color.rgb_int = 0;
	ft_bzero(env->coord[*index].color.rgb_hex, 10);
	env->coord[*index].color.pick_up = 0;
}

static void	ft_change_line(char *input, int *i, int *y, int *x)
{
	if (input[*i] == '\n')
	{
		(*y)++;
		*x = 0;
	}
}

int			ft_coord_in_struct(char *input, t_env *env, int len)
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
		ft_init_t_point(env, &index);
		if (ft_isdigit(input[i]) || input[i] == '-')
		{
			env->coord[index].x = x;
			env->coord[index].y = y;
			ft_get_digit(input, env, &i, &index);
			/*ft_printf("index : %3d >> x : %2d, y : %2d, z : %2d color_hex : %6s color_int : %10d color_pick_up : %1d \n", index,
			env->coord[index].x, env->coord[index].y, env->coord[index].z, env->coord[index].color.rgb_hex,
			env->coord[index].color.rgb_int, env->coord[index].color.pick_up);*/
			x++;
			index++;
		}
		ft_change_line(input, &i, &y, &x);
		i++;
	}
	return (0);
}

/*
ft_printf("index : %3d >> x : %2d, y : %2d, z : %2d color_hex : %6s color_int : %10d color_pick_up : %1d \n", index,
env->coord[index].x, env->coord[index].y, env->coord[index].z, env->coord[index].color.rgb_hex,
env->coord[index].color.rgb_int, env->coord[index].color.pick_up);
*/
