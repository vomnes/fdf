/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:38:47 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/01 09:38:25 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_select_range(t_env *env, int *scale_i, int *scale_plus)
{
	if (*scale_i == 10 || *scale_plus == 10)
		env->print.color = env->color.ten;
	else if (*scale_i == 9 || *scale_plus == 9)
		env->print.color = env->color.nine;
	else if (*scale_i == 8 || *scale_plus == 8)
		env->print.color = env->color.eight;
	else if (*scale_i == 7 || *scale_plus == 7)
		env->print.color = env->color.seven;
	else if (*scale_i == 6 || *scale_plus == 6)
		env->print.color = env->color.six;
	else if (*scale_i == 5 || *scale_plus == 5)
		env->print.color = env->color.five;
	else if (*scale_i == 4 || *scale_plus == 4)
		env->print.color = env->color.four;
	else if (*scale_i == 3 || *scale_plus == 3)
		env->print.color = env->color.three;
	else if (*scale_i == 2 || *scale_plus == 2)
		env->print.color = env->color.two;
	else if (*scale_i == 1 || *scale_plus == 1)
		env->print.color = env->color.two;
	else if (*scale_i > 0.5 || *scale_plus > 0.5)
		env->print.color = env->color.one;
	else if (*scale_i == 0 || *scale_plus == 0)
		env->print.color = env->color.one;
}

void			ft_manage_colors(t_env *env, int *i, int plus)
{
	int scale_i;
	int scale_plus;

	scale_i = 10. / (float)env->data.z_max * env->coord[*i].z + 0.5;
	scale_plus = 10. / (float)env->data.z_max * env->coord[*i + plus].z + 0.5;
	ft_color_type_map(env);
	ft_color_type_white(env);
	ft_color_type_gold_original(env);
	ft_color_type_blue_red_white(env);
	ft_select_range(env, &scale_i, &scale_plus);
	if (env->coord[*i].z == 0 && env->coord[*i + plus].z == 0)
		env->print.color = env->color.zero;
	if (env->color.scale == original && env->coord[*i].color.pick_up == 1 &&
	env->coord[*i + plus].color.pick_up == 1)
		env->print.color = env->coord[*i].color.rgb_int;
}

int				ft_interaction_color(int keycode, t_env *env)
{
	if (keycode == KEY_W || keycode == KEY_M || keycode == KEY_G
	|| keycode == KEY_F || keycode == KEY_O)
	{
		if (keycode == KEY_W)
			env->color.scale = white;
		if (keycode == KEY_M)
			env->color.scale = map;
		if (keycode == KEY_G)
			env->color.scale = gold;
		if (keycode == KEY_F)
			env->color.scale = bbr;
		if (keycode == KEY_O)
			env->color.scale = original;
		mlx_clear_window(env->data.mlx, env->data.win);
		return (1);
	}
	return (0);
}
