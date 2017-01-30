/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 08:31:44 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/25 08:31:44 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

static int ft_line_slow(t_env *env)
{
    int dx;
    int dy;
    int x;

    if (env->print.x1 - env->print.x0 < 0 && env->print.y1 - env->print.y0 >= 0)
    {
        ft_swap(&(env->print.x0), &(env->print.x1));
        ft_swap(&(env->print.y0), &(env->print.y1));
    }
    else if (env->print.x1 - env->print.x0 < 0 && env->print.y1 - env->print.y0 < 0)
    {
        ft_swap(&(env->print.x0), &(env->print.x1));
        ft_swap(&(env->print.y0), &(env->print.y1));
    }
    dx = env->print.x1 - env->print.x0;
    dy = env->print.y1 - env->print.y0;
    x = env->print.x0;
    while (x <= env->print.x1)
    {
        mlx_pixel_put(env->data.mlx, env->data.win, x, env->print.y0 +
        (dy * (x - env->print.x0) / dx), env->print.color);
        x++;
    }
    return (0);
}

static int ft_line_hard(t_env *env)
{
    int dx;
    int dy;
    int y;

    if (env->print.x1 - env->print.x0 >= 0 && env->print.y1 - env->print.y0 <= 0)
    {
        ft_swap(&(env->print.x0), &(env->print.x1));
        ft_swap(&(env->print.y0), &(env->print.y1));
    }
    else if (env->print.x1 - env->print.x0 < 0 && env->print.y1 - env->print.y0 < 0)
    {
        ft_swap(&(env->print.x0), &(env->print.x1));
        ft_swap(&(env->print.y0), &(env->print.y1));
    }
    dx = env->print.x1 - env->print.x0;
    dy = env->print.y1 - env->print.y0;
    y = env->print.y0;
    while (y <= env->print.y1)
    {
        mlx_pixel_put(env->data.mlx, env->data.win, env->print.x0 +
        (dx * (y - env->print.y0) / dy), y, env->print.color);
        y++;
    }
    return (0);
}

int ft_draw_line(t_env *env)
{
    if (env->print.x0 != env->print.x1 || env->print.y0 != env->print.y1)
    {
        if (abs(env->print.x1 - env->print.x0) < abs(env->print.y1 - env->print.y0)
        || abs(env->print.x1 - env->print.x0) < abs(env->print.y1 - env->print.y0))
            ft_line_hard(env);
        else
            ft_line_slow(env);
    }
    return (0);
}

/*
i = 0;
while (i < 600)
{
    ft_draw_line(300, 300, i, 0, mlx, win);
    i += 1;
}
i = 0;
while (i < 600)
{
    ft_draw_line(300, 300, 600, i, mlx, win);
    i += 1;
}
i = 600;
while (i > 0)
{
    ft_draw_line(300, 300, i, 600, mlx, win);
    i -= 1;
}
i = 600;
while (i > 0)
{
    ft_draw_line(300, 300, 0, i, mlx, win);
    i -= 1;
}
*/
