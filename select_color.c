/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:38:56 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/31 11:38:57 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void ft_color_type_map(t_env *env)
{
    if (env->color.scale == map)
    {
        env->color.ten = COLOR_WHITE;
        env->color.nine = COLOR_WHITE;
        env->color.eight = COLOR_LIGHT_BROWN;
        env->color.seven = COLOR_LIGHT_BROWN;
        env->color.six = COLOR_LIGHT_BROWN;
        env->color.five = COLOR_GREEN_YELLOW;
        env->color.four = COLOR_BROWN;
        env->color.three = COLOR_YELLOW;
        env->color.two = COLOR_GREEN;
        env->color.one = COLOR_DARK_GREEN;
        env->color.zero = COLOR_BLUE;
    }
}

void ft_color_type_white(t_env *env)
{
    if (env->color.scale == white)
    {
        env->color.ten = COLOR_WHITE;
        env->color.nine = COLOR_WHITE;
        env->color.eight = COLOR_WHITE;
        env->color.seven = COLOR_WHITE;
        env->color.six = COLOR_WHITE;
        env->color.five = COLOR_WHITE;
        env->color.four = COLOR_WHITE;
        env->color.three = COLOR_WHITE;
        env->color.two = COLOR_WHITE;
        env->color.one = COLOR_WHITE;
        env->color.zero = COLOR_WHITE;
    }
}

void ft_color_type_gold(t_env *env)
{
    if (env->color.scale == gold)
    {
        env->color.ten = COLOR_GOLD;
        env->color.nine = COLOR_GOLD;
        env->color.eight = COLOR_GOLD;
        env->color.seven = COLOR_GOLD;
        env->color.six = COLOR_GOLD;
        env->color.five = COLOR_GOLD;
        env->color.four = COLOR_GOLD;
        env->color.three = COLOR_GOLD;
        env->color.two = COLOR_GOLD;
        env->color.one = COLOR_GOLD;
        env->color.zero = COLOR_WHITE;
    }
}

void ft_color_type_original(t_env *env)
{
    if (env->color.scale == original)
    {
        env->color.ten = COLOR_GOLD;
        env->color.nine = COLOR_GOLD;
        env->color.eight = COLOR_GOLD;
        env->color.seven = COLOR_GOLD;
        env->color.six = COLOR_GOLD;
        env->color.five = COLOR_GOLD;
        env->color.four = COLOR_GOLD;
        env->color.three = COLOR_GOLD;
        env->color.two = COLOR_GOLD;
        env->color.one = COLOR_GOLD;
        env->color.zero = COLOR_WHITE;
    }
}

void ft_color_type_bbr(t_env *env)
{
    if (env->color.scale == bbr)
    {
        env->color.ten = COLOR_RED_BBR;
        env->color.nine = COLOR_RED_BBR;
        env->color.eight = COLOR_RED_BBR;
        env->color.seven = COLOR_RED_BBR;
        env->color.six = COLOR_WHITE;
        env->color.five = COLOR_WHITE;
        env->color.four = COLOR_WHITE;
        env->color.three = COLOR_WHITE;
        env->color.two = COLOR_WHITE;
        env->color.one = COLOR_WHITE;
        env->color.zero = COLOR_BLUE_BBR;
    }
}
