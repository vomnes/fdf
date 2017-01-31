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

static void ft_transform_xyz(t_env *e, t_edit *pos, int *i)
{
    int length;
    float sqrt_z;

    sqrt_z = -0.81649658092;
    length = e->data.map_length;
    pos->x_a = sqrt(2)/2 * (e->coord[*i].x - e->coord[*i].y) * e->data.zoom +
    e->data.pos_x;
    pos->y_a = sqrt_z * e->coord[*i].z * e->data.deep + (1 / sqrt(6) *
    (e->coord[*i].x + e->coord[*i].y)) * e->data.zoom + e->data.pos_y;
    pos->x_b = sqrt(2)/2 * (e->coord[*i + 1].x - e->coord[*i + 1].y) *
    e->data.zoom + e->data.pos_x;
    pos->y_b = sqrt_z * e->coord[*i + 1].z * e->data.deep + (1 / sqrt(6) *
    (e->coord[*i + 1].x + e->coord[*i + 1].y)) * e->data.zoom + e->data.pos_y;
    pos->x_c = sqrt(2)/2 * (e->coord[*i + length].x - e->coord[*i + length].y)
    * e->data.zoom + e->data.pos_x;
    pos->y_c = sqrt_z * e->coord[*i + length].z * e->data.deep + (1 / sqrt(6)
    * (e->coord[*i + length].x + e->coord[*i + length].y)) * e->data.zoom +
    e->data.pos_y;
}

static void ft_print_lines(t_env *env, t_edit *pos, int *i)
{
    ft_manage_colors(env, &(*i), 1);
    env->print.x0 = pos->x_a;
    env->print.y0 = pos->y_a;
    env->print.x1 = pos->x_b;
    env->print.y1 = pos->y_b;
    if (env->coord[*i].x < env->data.map_length - 1)
        ft_draw_line(env);
    env->print.x0 = pos->x_a;
    env->print.y0 = pos->y_a;
    env->print.x1 = pos->x_c;
    env->print.y1 = pos->y_c;
    ft_manage_colors(env, &(*i), env->data.map_length);
    if (env->coord[*i].y < env->data.map_width - 1)
        ft_draw_line(env);
}

void ft_build_iso(t_env *env)
{
    t_edit pos;
    int i;

    i = 0;
    while (i < env->data.map_total_size)
    {
        ft_transform_xyz(env, &pos, &i);
        ft_print_lines(env, &pos, &i);
        i++;
    }
}
