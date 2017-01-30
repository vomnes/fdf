/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 08:49:44 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/25 08:49:46 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_print_key_num(int keycode)
{
    ft_printf("Key event --> %d\n", keycode);
}

void ft_push_exit(int keycode)
{
    if (keycode == KEY_ESCAPE || keycode == KEY_Q)
        exit(1);
}

int ft_move_xy(int keycode, t_env *env)
{
    if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT || keycode == ARROW_DOWN
    || keycode == ARROW_UP)
    {
        if (keycode == ARROW_LEFT)
            env->data.pos_x += 10;
        if (keycode == ARROW_RIGHT)
            env->data.pos_x -= 10;
        if (keycode == ARROW_DOWN)
            env->data.pos_y -= 10;
        if (keycode == ARROW_UP)
            env->data.pos_y += 10;
        mlx_clear_window(env->data.mlx, env->data.win);
        return (1);
    }
    return (0);
}

int ft_move_zoom_deep(int keycode, t_env *env)
{
    if (keycode == KEY_PLUS || keycode == KEY_LESS || keycode == KEY_P
    || keycode == KEY_L)
    {
        if (keycode == KEY_PLUS)
            env->data.zoom += 1;
        if (keycode == KEY_LESS)
            env->data.zoom -= 1;
        if (keycode == KEY_P)
            env->data.deep += 0.5;
        if (keycode == KEY_L)
            env->data.deep -= 0.5;
        mlx_clear_window(env->data.mlx, env->data.win);
        return (1);
    }
    return (0);
}


int ft_key_interact(int keycode, t_env *env)
{
    ft_print_key_num(keycode);
    ft_push_exit(keycode);
    if (ft_move_xy(keycode, env) == 1)
        ft_build_3d(env);
    if (ft_move_zoom_deep(keycode, env) == 1)
        ft_build_3d(env);
    return (0);
}

//mlx_key_hook(win, ft_add, 0);
