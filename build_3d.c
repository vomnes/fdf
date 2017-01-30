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

/*
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
*/

void ft_manage_colors(t_env *env, int *i, int plus)
{
    int scale_i;
    int scale_plus;

//    ft_printf("env->data.z_max : %d - env->data.z_min : %d\n", env->data.z_max, env->data.z_min);
    scale_i = 10 / env->data.z_max * env->coord[*i].z;
    ft_printf("scale_i : %d\n", scale_i);
    scale_plus = env->coord[*i + plus].z;
/*
    if (scale_i == 10 || scale_plus == 10)
        env->print.color = COLOR_GREEN;
    if (scale_i == 9 || scale_plus == 9)
        env->print.color = COLOR_GREEN;
    if (scale_i == 8 || scale_plus == 8)
        env->print.color = COLOR_GREEN;
    if (scale_i == 7 || scale_plus == 7)
        env->print.color = COLOR_GREEN;
    if (scale_i == 6 || scale_plus == 6)
        env->print.color = COLOR_GREEN;
    if (scale_i == 5 || scale_plus == 5)
        env->print.color = COLOR_GREEN;
    if (scale_i == 4 || scale_plus == 4)
        env->print.color = COLOR_GREEN;
    if (scale_i == 3 || scale_plus == 3)
        env->print.color = COLOR_GREEN;
    if (scale_i == 2 || scale_plus == 2)
        env->print.color = COLOR_GREEN;
    if (scale_i == 1 || scale_plus == 1)
        env->print.color = COLOR_GREEN;
    if (scale_i == 0 || scale_plus == 0)
        env->print.color = COLOR_GREEN;
*/
    if (env->coord[*i].color.pick_up == 1 && env->coord[*i + plus].color.pick_up == 1)
        env->print.color = env->coord[*i].color.rgb_int;
    else if ((scale_i <= 10 && scale_i > 0) || (scale_plus <= 10 && scale_plus > 0))
        env->print.color = COLOR_GREEN;
    else if (scale_i > 10 || scale_plus > 10)
        env->print.color = COLOR_BROWN;
    else if (scale_i == 0)
        env->print.color = COLOR_BLUE;
    else
        env->print.color = COLOR_BROWN;
}

void ft_rotation_x(t_env *e, int angle)
{
    int i;
    int tmp;

    i = 0;
    tmp = 0;
    while (i < e->data.map_total_size)
    {
        tmp = e->coord[i].y;
        e->coord[i].y = e->coord[i].y * cos(angle) + e->coord[i].z * sin(angle);
        e->coord[i].z = -tmp * sin(angle) + e->coord[i].z * cos(angle);
        i++;
    }
}

int ft_build_iso(t_env *e)
{
    t_edit pos;
    int length;
    int i;
    float sqrt_z;
    int angle;

    i = 0;
    angle = -90;
    sqrt_z = -0.81649658092;
    length = e->data.map_length;

    //ft_rotation_x(e, angle);
    while (i < e->data.map_total_size)
    {
        pos.x_a = sqrt(2)/2 * (e->coord[i].x - e->coord[i].y) * e->data.zoom + e->data.pos_x;
        pos.y_a = sqrt_z * e->coord[i].z * e->data.deep + (1 / sqrt(6) * (e->coord[i].x + e->coord[i].y)) * e->data.zoom + e->data.pos_y;
        pos.x_b = sqrt(2)/2 * (e->coord[i + 1].x - e->coord[i + 1].y) * e->data.zoom + e->data.pos_x;
        pos.y_b = sqrt_z * e->coord[i + 1].z * e->data.deep + (1 / sqrt(6) * (e->coord[i + 1].x + e->coord[i + 1].y)) * e->data.zoom + e->data.pos_y;
        pos.x_c = sqrt(2)/2 * (e->coord[i + length].x - e->coord[i + length].y) * e->data.zoom + e->data.pos_x;
        pos.y_c = sqrt_z * e->coord[i + length].z * e->data.deep + (1 / sqrt(6) * (e->coord[i + length].x + e->coord[i + length].y)) * e->data.zoom + e->data.pos_y;

        ft_manage_colors(e, &i, 1);
        e->print.x0 = pos.x_a;
        e->print.y0 = pos.y_a;
        e->print.x1 = pos.x_b;
        e->print.y1 = pos.y_b;
        if (e->coord[i].x < e->data.map_length - 1)
            ft_draw_line(e);
        e->print.x0 = pos.x_a;
        e->print.y0 = pos.y_a;
        e->print.x1 = pos.x_c;
        e->print.y1 = pos.y_c;
        ft_manage_colors(e, &i, length);
        if (e->coord[i].y < e->data.map_width - 1)
            ft_draw_line(e);
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
