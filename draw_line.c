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

static int ft_line_slow(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
    int dx;
    int dy;
    int x;

    if (x1 - x0 < 0 && y1 - y0 >= 0)
    {
        ft_swap(&x0, &x1);
        ft_swap(&y0, &y1);
    }
    else if (x1 - x0 < 0 && y1 - y0 < 0)
    {
        ft_swap(&x0, &x1);
        ft_swap(&y0, &y1);
    }
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    while (x <= x1)
    {
        mlx_pixel_put(mlx, win, x, y0 + (dy * (x - x0) / dx), 0x00FAAFF);
        x++;
    }
    return (0);
}

static int ft_line_hard(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
    int dx;
    int dy;
    int y;

    if (x1 - x0 >= 0 && y1 - y0 <= 0)
    {
        ft_swap(&x0, &x1);
        ft_swap(&y0, &y1);
    }
    else if (x1 - x0 < 0 && y1 - y0 < 0)
    {
        ft_swap(&x0, &x1);
        ft_swap(&y0, &y1);
    }
    dx = x1 - x0;
    dy = y1 - y0;
    y = y0;
    while (y <= y1)
    {
        mlx_pixel_put(mlx, win, x0 + (dx * (y - y0) / dy), y, 0x00FAAFF);
        y++;
    }
    return (0);
}

int ft_draw_line(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
    if (x1 > y1 && y1 < y0 && abs(x1 - x0) < abs(y1 - y0))
        ft_line_hard(x0, y0, x1, y1, mlx, win);
    else if (x1 < y1 && y1 > y0 && abs(x1 - x0) < abs(y1 - y0))
        ft_line_hard(x0, y0, x1, y1, mlx, win);
    else
        ft_line_slow(x0, y0, x1, y1, mlx, win);
    return (0);
}
