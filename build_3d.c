/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:50:04 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/26 18:50:08 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void ft_rotation_x(t_point *coord, int angle, int length, int width)
{
    int i;
    int new_y;
    int new_z;

    i = 0;
    new_y = 0;
    new_z = 0;
    while (i < length * width)
    {
    //    coord[i].z = 0;
        new_y = coord[i].y * cos(angle)  + coord[i].z * sin(angle);
        new_z = -coord[i].y * sin(angle) + coord[i].z * cos(angle);
        coord[i].y = new_y;
        coord[i].z = new_z;
        i++;
    }
}

void ft_rotation_y(t_point *coord, int angle, int length, int width)
{
    int i;
    int new_x;
    int new_z;

    i = 0;
    new_x = 0;
    new_z = 0;
    while (i < length * width)
    {
    //    coord[i].z = 0;
        new_x = coord[i].x * cos(angle) - coord[i].z * sin(angle);
        new_z = coord[i].x * sin(angle) + coord[i].z * cos(angle);
        coord[i].x = new_x;
        coord[i].z = new_z;
        i++;
    }
}

int ft_build_3d(t_point *coord, int length, int width, void *mlx, void *win)
{
    int i;
    float x_a;
    float y_a;
    float x_b;
    float y_b;
    float x_c;
    float y_c;
    int plus_x;
    int plus_y;
    float zoom;
    float zoom_one;

    i = 0;
    plus_x = 225;
    plus_y = 150;
    zoom = 30;
    zoom_one = 30;
    int angle;
    angle = 90;
    float var1 = -0.81649658092;
    float var2 = -0.81;
    float var3 = 0.95;
    float var4 = 1.8;
//    ft_rotation_x(coord, 90, length, width);
//    ft_rotation_x(coord, -90, length, width);

//    ft_rotation_x(coord, 90, length, width);
//    ft_rotation_y(coord, 5, length, width);
    while (i < length * width)
    {
        x_a = sqrt(2)/2 * (coord[i].x - coord[i].y) * zoom;
        y_a = var1 * coord[i].z * zoom_one + (1 / sqrt(6) * (coord[i].x + coord[i].y)) * zoom;
        x_b = sqrt(2)/2 * (coord[i + 1].x - coord[i + 1].y) * zoom;
        y_b = var1 * coord[i + 1].z * zoom_one + (1 / sqrt(6) * (coord[i + 1].x + coord[i + 1].y)) * zoom;
        x_c = sqrt(2)/2 * (coord[i + length].x - coord[i + length].y) * zoom;
        y_c = var1 * coord[i + length].z * zoom_one + (1 / sqrt(6) * (coord[i + length].x + coord[i + length].y)) * zoom;

        /*new_x_a = x_a * cos(10) - x_a * sin(10);
        new_y_a = x_a * sin(10) - y_a * cos(10);
        new_x_b = x_b * cos(10) - x_b * sin(10);
        new_y_b = x_b * sin(10) - x_b * cos(10);
        new_x_c = x_c * cos(10) - x_c * sin(10);
        new_y_c = x_c * sin(10) - x_c * cos(10);*/

        if (coord[i].x < length - 1)
            ft_draw_line(x_a + plus_x, y_a + plus_y, x_b + plus_x, y_b + plus_y, mlx, win);
        if (coord[i].y < width - 1)
            ft_draw_line(x_a + plus_x, y_a + plus_y, x_c + plus_x, y_c + plus_y, mlx, win);
        i++;
    }
    return (0);
}

//float var1 = -0.8;
//float var2 = -0.81;
//float var3 = 0.95;
//float var4 = 1.8;

//    sqrt(2)/2 * (coord[i].x - coord[i].y);
//    sqrt(2 / 3) * coord[i].z - (1 / sqrt(6) * (coord[i].x + coord[i].y));

//    new_x = sqrt(2)/2 * (x - y);
//    new_y = sqrt((2 / 3) * z) - (1 / sqrt(6) * (x + y));
