/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 08:09:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/01 09:32:13 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_zoom(t_env *env)
{
	if (env->data.map_total_size <= 250)
		env->data.zoom = 60;
	else if (env->data.map_total_size <= 500)
		env->data.zoom = 50;
	else if (env->data.map_total_size <= 1000)
		env->data.zoom = 40;
	else if (env->data.map_total_size <= 5000)
		env->data.zoom = 30;
	else if (env->data.map_total_size <= 10000)
		env->data.zoom = 10;
	else if (env->data.map_total_size <= 25000)
		env->data.zoom = 8;
	else if (env->data.map_total_size <= 50000)
		env->data.zoom = 5;
	else if (env->data.map_total_size <= 100000)
		env->data.zoom = 4;
	else if (env->data.map_total_size <= 150000)
		env->data.zoom = 3;
	else if (env->data.map_total_size <= 250000)
		env->data.zoom = 2;
	else if (env->data.map_total_size <= 500000)
		env->data.zoom = 1;
	else
		env->data.zoom = 0.5;
	env->data.zoom_start = env->data.zoom;
}

void		ft_init_data(t_env *env, char *input)
{
	env->data.map_length = ft_max_length(input);
	env->data.map_width = ft_width(input);
	env->data.map_total_size = env->data.map_length * env->data.map_width;
	if (env->data.map_total_size <= 300000)
		env->data.elevation = 1.5;
	else
		env->data.elevation = 0.1;
	env->data.elevation_start = env->data.elevation;
	env->data.x_max = 0;
	env->data.x_min = 0;
	env->data.y_max = 0;
	env->data.y_min = 0;
	env->data.z_max = 0;
	env->data.z_min = 0;
}

void		ft_set_up_data(t_env *env)
{
	ft_get_zoom(env);
	ft_get_max_min_xyz(env);
	env->data.pos_x = env->data.x_min + 50;
	env->data.pos_y = env->data.y_min + 50;
	env->data.pos_x_start = env->data.pos_x;
	env->data.pos_y_start = env->data.pos_y;
	env->data.win_width = env->data.x_max + env->data.pos_x + 50;
	env->data.win_height = env->data.y_max + env->data.pos_y + 50;
	env->data.win_width =
	(env->data.win_width > 2250) ? 2250 : env->data.win_width;
	env->data.win_height =
	(env->data.win_height > 1250) ? 1250 : env->data.win_height;
	env->data.mlx = mlx_init();
	env->data.win = mlx_new_window(env->data.mlx, env->data.win_width,
					env->data.win_height, "fdf");
	env->color.scale = white;
	env->data.help = 0;
}
