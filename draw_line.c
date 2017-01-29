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

static int ft_line_slow(t_print *print, t_data *data)
{
    int dx;
    int dy;
    int x;

    if (print->x1 - print->x0 < 0 && print->y1 - print->y0 >= 0)
    {
        ft_swap(&(print->x0), &(print->x1));
        ft_swap(&(print->y0), &(print->y1));
    }
    else if (print->x1 - print->x0 < 0 && print->y1 - print->y0 < 0)
    {
        ft_swap(&(print->x0), &(print->x1));
        ft_swap(&(print->y0), &(print->y1));
    }
    dx = print->x1 - print->x0;
    dy = print->y1 - print->y0;
    x = print->x0;
    while (x <= print->x1)
    {
        mlx_pixel_put(data->mlx, data->win, x, print->y0 +
        (dy * (x - print->x0) / dx), print->color);
        x++;
    }
    return (0);
}

static int ft_line_hard(t_print *print, t_data *data)
{
    int dx;
    int dy;
    int y;

    if (print->x1 - print->x0 >= 0 && print->y1 - print->y0 <= 0)
    {
        ft_swap(&(print->x0), &(print->x1));
        ft_swap(&(print->y0), &(print->y1));
    }
    else if (print->x1 - print->x0 < 0 && print->y1 - print->y0 < 0)
    {
        ft_swap(&(print->x0), &(print->x1));
        ft_swap(&(print->y0), &(print->y1));
    }
    dx = print->x1 - print->x0;
    dy = print->y1 - print->y0;
    y = print->y0;
    while (y <= print->y1)
    {
        mlx_pixel_put(data->mlx, data->win, print->x0 +
        (dx * (y - print->y0) / dy), y, print->color);
        y++;
    }
    return (0);
}

int ft_draw_line(t_print *print, t_data *data)
{
    if (print->x0 != print->x1 || print->y0 != print->y1)
    {
        if (abs(print->x1 - print->x0) < abs(print->y1 - print->y0)
        || abs(print->x1 - print->x0) < abs(print->y1 - print->y0))
            ft_line_hard(print, data);
        else
            ft_line_slow(print, data);
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
