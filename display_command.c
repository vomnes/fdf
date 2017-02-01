/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:57:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/01 14:02:08 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_display_string(t_env *env, int x, int y, char *str)
{
	mlx_string_put(env->data.mlx, env->data.win, x, y, COLOR_WHITE, str);
}

static void	ft_display_help(t_env *env, int m)
{
	int right;

	right = env->data.win_width - 175 - m;
	ft_display_string(env, m, 2, "Press ESC or Q for exit");
	ft_display_string(env, m, 22, "Press H for display help");
	ft_display_string(env, m, 42, "Arrows: Change position");
	ft_display_string(env, m, 62, "  E   : Elevation");
	ft_display_string(env, m, 82, "  D   : Deep");
	ft_display_string(env, m, 102, "  .   : Cancel elevation");
	ft_display_string(env, m, 122, " +/-  : Zoom ");
	ft_display_string(env, m, 142, "Space : Back to start position and zoom");
	ft_display_string(env, right, 2, "Color Original: O");
	ft_display_string(env, right, 22, "Color White   : W");
	ft_display_string(env, right, 42, "Color B/W/R   : F");
	ft_display_string(env, right, 62, "Color Gold    : G");
	ft_display_string(env, right, 82, "Color Map     : M");
}

void		ft_display_command(t_env *env)
{
	int m;

	m = 10;
	if (env->data.win_width < 440)
		ft_display_string(env, m, 2, "Exit: Q");
	else
	{
		if (env->data.help == 0)
		{
			ft_display_string(env, m, 2, "Press ESC or Q for exit");
			ft_display_string(env, m, 22, "Press H for display help");
		}
		else
			ft_display_help(env, m);
	}
}
