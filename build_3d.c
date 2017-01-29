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

void ft_rotation_x(t_point *coord, int angle, t_data *data)
{
    int i;
    int new_y;
    int new_z;

    i = 0;
    new_y = 0;
    new_z = 0;
    while (i < data->map_total_size)
    {
    //    coord[i].z = 0;
        new_y = coord[i].y * cos(angle)  + coord[i].z * sin(angle);
        new_z = -coord[i].y * sin(angle) + coord[i].z * cos(angle);
        coord[i].y = new_y;
        coord[i].z = new_z;
        i++;
    }
}

void ft_rotation_y(t_point *coord, int angle, t_data *data)
{
    int i;
    int new_x;
    int new_z;

    i = 0;
    new_x = 0;
    new_z = 0;
    while (i < data->map_total_size)
    {
    //    coord[i].z = 0;
        new_x = coord[i].x * cos(angle) - coord[i].z * sin(angle);
        new_z = coord[i].x * sin(angle) + coord[i].z * cos(angle);
        coord[i].x = new_x;
        coord[i].z = new_z;
        i++;
    }
}

int ft_build_3d(t_point *coord, t_data *data, t_print *print)
{
    int i;
    float x_a = 0;
    float y_a = 0;
    float x_b;
    float y_b;
    float x_c;
    float y_c;
    int plus_x;
    int plus_y;
    float zoom;
    float zoom_one;
    int length;
    int min;
    int check_min;

    zoom = data->zoom;
    zoom_one = data->deep;
    float var1 = -0.81649658092;
    length = data->map_length;
    plus_x = data->pos_x;//sqrt(2)/2 * (coord[data->map_width].x - coord[data->map_width].y) * zoom;
    plus_y = data->pos_y;//var1 * coord[0].z * zoom_one + (1 / sqrt(6) * (coord[0].x + coord[0].y)) * zoom;
    i = 0;
    while (i < data->map_total_size)
    {
        x_a = sqrt(2)/2 * (coord[i].x - coord[i].y) * zoom;
        y_a = var1 * coord[i].z * zoom_one + (1 / sqrt(6) * (coord[i].x + coord[i].y)) * zoom;
        x_b = sqrt(2)/2 * (coord[i + 1].x - coord[i + 1].y) * zoom;
        y_b = var1 * coord[i + 1].z * zoom_one + (1 / sqrt(6) * (coord[i + 1].x + coord[i + 1].y)) * zoom;
        x_c = sqrt(2)/2 * (coord[i + length].x - coord[i + length].y) * zoom;
        y_c = var1 * coord[i + length].z * zoom_one + (1 / sqrt(6) * (coord[i + length].x + coord[i + length].y)) * zoom;

        //ft_printf("pick_up >> %d, rgb_hex >> %s\n", coord[i].color.pick_up, coord[i].color.rgb_hex);
        if (coord[i].color.pick_up == 1 && coord[i + 1].color.pick_up == 1)
            print->color = coord[i].color.rgb_int;
        else if (coord[i].z == 0)
            print->color = 0x0080ccff;
        else if (coord[i].z > 0 || coord[i + 1].z > 0)
            print->color = 0x00b33c;
        else
            print->color = 0x00994d00;
        print->x0 = x_a + plus_x;
        print->y0 = y_a + plus_y;
        print->x1 = x_b + plus_x;
        print->y1 = y_b + plus_y;
        if (coord[i].x < data->map_length - 1)
            ft_draw_line(print, data);
        if (coord[i].color.pick_up == 1 && coord[i + length].color.pick_up == 1)
            print->color = coord[i].color.rgb_int;
        else if (coord[i].z == 0)
            print->color = 0x0080ccff;
        else if (coord[i].z > 0 || coord[i + length].z > 0)
            print->color = 0x00b33c;
        else
            print->color = 0x00000000;
        print->x1 = x_c + plus_x;
        print->y1 = y_c + plus_y;
        if (coord[i].y < data->map_width - 1)
            ft_draw_line(print, data);
        i++;
    }
    return (0);
}


    /*new_x_a = x_a * cos(10) - x_a * sin(10);
    new_y_a = x_a * sin(10) - y_a * cos(10);
    new_x_b = x_b * cos(10) - x_b * sin(10);
    new_y_b = x_b * sin(10) - x_b * cos(10);
    new_x_c = x_c * cos(10) - x_c * sin(10);
    new_y_c = x_c * sin(10) - x_c * cos(10);*/

    //    ft_rotation_x(coord, 90, length, width);
    //    ft_rotation_x(coord, -90, length, width);

    //    ft_rotation_x(coord, 90, length, width);
    //    ft_rotation_y(coord, 5, length, width);

//float var1 = -0.8;
//float var2 = -0.81;
//float var3 = 0.95;
//float var4 = 1.8;

//    sqrt(2)/2 * (coord[i].x - coord[i].y);
//    sqrt(2 / 3) * coord[i].z - (1 / sqrt(6) * (coord[i].x + coord[i].y));

//    new_x = sqrt(2)/2 * (x - y);
//    new_y = sqrt((2 / 3) * z) - (1 / sqrt(6) * (x + y));
