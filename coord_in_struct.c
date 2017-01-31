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
	if (env->coord[*index].z >= 100000 || env->coord[*index].z <= -100000)
		env->coord[*index].z = 0;
	if (input[*i] == ',')
	{
		*i += 3;
		while (ft_isxdigit(input[*i]))
			env->coord[*index].color.rgb_hex[index_hex++] = input[(*i)++];
		env->coord[*index].color.rgb_int =
		ft_hex_to_dec(env->coord[*index].color.rgb_hex);
		env->coord[*index].color.pick_up = 1;
	}
}

static void	ft_init_t_point(t_env *env, t_index *index)
{
	env->coord[index->index].x = 0;
	env->coord[index->index].y = 0;
	env->coord[index->index].z = 0;
	env->coord[index->index].color.rgb_int = 0;
	ft_bzero(env->coord[index->index].color.rgb_hex, 10);
	env->coord[index->index].color.pick_up = 0;
}

static void	ft_change_line(t_env *env, char *input, t_index *index)
{
	if (input[index->i] == '\n')
	{
		while (index->x < env->data.map_length)
		{
			env->coord[index->index].x = index->x;
			env->coord[index->index].y = index->y;
			(index->index)++;
			(index->x)++;
		}
		(index->y)++;
		index->x = 0;
	}
}

int			ft_coord_in_struct(char *input, t_env *env)
{
	t_index index;

	index.i = 0;
	index.x = 0;
	index.y = 0;
	index.index = 0;
	//ft_printf("env->.data.map_width = %d\n", env->data.map_width);
	//ft_printf("env->data.map_length = %d\n", env->data.map_length);
	//ft_printf("env->data.map_total_size = %d\n", env->data.map_total_size);
	while (input[index.i] && index.index < env->data.map_total_size)
	{
		ft_init_t_point(env, &index);
		if (ft_isdigit(input[index.i]) || input[index.i] == '-')
		{
			env->coord[index.index].x = index.x;
			env->coord[index.index].y = index.y;
			ft_get_digit(input, env, &(index.i), &(index.index));
		//	ft_printf("index : %3d >> x : %2d, y : %2d, z : %2d color_hex : %6s color_int : %10d color_pick_up : %1d \n", index.index,
		//	env->coord[index.index].x, env->coord[index.index].y, env->coord[index.index].z, env->coord[index.index].color.rgb_hex,
		//	env->coord[index.index].color.rgb_int, env->coord[index.index].color.pick_up);
			(index.x)++;
			(index.index)++;
		}
		ft_change_line(env, input, &index);
		(index.i)++;
	}
	return (0);
}

/*
ft_printf("index : %3d >> x : %2d, y : %2d, z : %2d color_hex : %6s color_int : %10d color_pick_up : %1d \n", index,
env->coord[index].x, env->coord[index].y, env->coord[index].z, env->coord[index].color.rgb_hex,
env->coord[index].color.rgb_int, env->coord[index].color.pick_up);
*/
