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

static int ft_line_slow(t_env *e)
{
    int dx;
    int dy;
    int x;

    if (e->print.x1 - e->print.x0 < 0 && e->print.y1 - e->print.y0 >= 0)
    {
        ft_swap(&(e->print.x0), &(e->print.x1));
        ft_swap(&(e->print.y0), &(e->print.y1));
    }
    else if (e->print.x1 - e->print.x0 < 0 && e->print.y1 - e->print.y0 < 0)
    {
        ft_swap(&(e->print.x0), &(e->print.x1));
        ft_swap(&(e->print.y0), &(e->print.y1));
    }
    dx = e->print.x1 - e->print.x0;
    dy = e->print.y1 - e->print.y0;
    x = e->print.x0;
    while (x <= e->print.x1)
    {
        mlx_pixel_put(e->data.mlx, e->data.win, x, e->print.y0 +
        (dy * (x - e->print.x0) / dx), e->print.color);
        x++;
    }
    return (0);
}

static int ft_line_hard(t_env *e)
{
    int dx;
    int dy;
    int y;

    if (e->print.x1 - e->print.x0 >= 0 && e->print.y1 - e->print.y0 <= 0)
    {
        ft_swap(&(e->print.x0), &(e->print.x1));
        ft_swap(&(e->print.y0), &(e->print.y1));
    }
    else if (e->print.x1 - e->print.x0 < 0 && e->print.y1 - e->print.y0 < 0)
    {
        ft_swap(&(e->print.x0), &(e->print.x1));
        ft_swap(&(e->print.y0), &(e->print.y1));
    }
    dx = e->print.x1 - e->print.x0;
    dy = e->print.y1 - e->print.y0;
    y = e->print.y0;
    while (y <= e->print.y1)
    {
        mlx_pixel_put(e->data.mlx, e->data.win, e->print.x0 +
        (dx * (y - e->print.y0) / dy), y,e->print.color);
        y++;
    }
    return (0);
}

int ft_draw_line(t_env *env)
{
    if (env->print.x0 != env->print.x1 || env->print.y0 != env->print.y1)
    {
        if (abs(env->print.x1 - env->print.x0) <
        abs(env->print.y1 - env->print.y0)
        || abs(env->print.x1 - env->print.x0) <
        abs(env->print.y1 - env->print.y0))
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
