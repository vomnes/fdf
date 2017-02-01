/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 08:49:44 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/01 09:02:40 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_push_exit(int keycode)
{
	if (keycode == KEY_ESCAPE || keycode == KEY_Q)
		exit(1);
}

static int		ft_move_xy(int code, t_env *env)
{
	if (code == ARROW_LEFT || code == ARROW_RIGHT || code == ARROW_DOWN
	|| code == ARROW_UP || code == KEY_SPC || code == KEY_H || code == KEY_DOT)
	{
		if (code == ARROW_LEFT)
			env->data.pos_x += 10;
		if (code == ARROW_RIGHT)
			env->data.pos_x -= 10;
		if (code == ARROW_DOWN)
			env->data.pos_y -= 10;
		if (code == ARROW_UP)
			env->data.pos_y += 10;
		if (code == KEY_SPC)
		{
			env->data.pos_x = env->data.pos_x_start;
			env->data.pos_y = env->data.pos_y_start;
			env->data.zoom = env->data.zoom_start;
		}
		env->data.elevation = (code == KEY_DOT) ?
		env->data.elevation_start : env->data.elevation;
		if (code == KEY_H)
			env->data.help = 1 - env->data.help;
		mlx_clear_window(env->data.mlx, env->data.win);
		return (1);
	}
	return (0);
}

static int		ft_move_zoom_elevation(int keycode, t_env *env)
{
	float	change;

	change = 0;
	if (keycode == KEY_PLUS || keycode == KEY_LESS || keycode == KEY_D
	|| keycode == KEY_E)
	{
		if (keycode == KEY_PLUS)
			env->data.zoom += 1;
		if (keycode == KEY_LESS)
			env->data.zoom -= 1;
		if (env->data.elevation < 0.2 && env->data.elevation > 0)
			change = 0.01;
		if (env->data.elevation < 2 && env->data.elevation > 0)
			change = 0.1;
		else
			change = 0.5;
		if (keycode == KEY_E)
			env->data.elevation += change;
		if (keycode == KEY_D)
			env->data.elevation -= change;
		mlx_clear_window(env->data.mlx, env->data.win);
		return (1);
	}
	return (0);
}

int				ft_key_interact(int keycode, t_env *env)
{
	ft_push_exit(keycode);
	if (ft_move_xy(keycode, env) == 1)
		ft_build_iso(env);
	if (ft_move_zoom_elevation(keycode, env) == 1)
		ft_build_iso(env);
	if (ft_interaction_color(keycode, env) == 1)
		ft_build_iso(env);
	return (0);
}
