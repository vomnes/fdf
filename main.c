/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 08:31:58 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/25 08:31:59 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

static int ft_check_min_x(t_env *env)
{
    int i;
    int min;
    int tmp_min;

    i = 0;
    min = 0;
    tmp_min = 0;
    while (i < env->data.map_total_size)
    {
        tmp_min = sqrt(2) / 2 * (env->coord[i].x - env->coord[i].y) * env->data.zoom;
        min = tmp_min < min ? tmp_min : min;
        i++;
    }
    min = (min < 0 ? -min : min);
    return (min);
}

static int ft_check_max_x(t_env *env)
{
    int i;
    int max;
    int tmp_max;

    i = 0;
    max = 0;
    tmp_max = 0;
    while (i < env->data.map_total_size)
    {
        tmp_max = sqrt(2) / 2 * (env->coord[i].x - env->coord[i].y) * env->data.zoom;
        max = tmp_max > max ? tmp_max : max;
        i++;
    }
    return (max);
}

static int ft_check_min_y(t_env *env)
{
    int i;
    int min;
    int tmp_min;

    i = 0;
    min = 0;
    tmp_min = 0;
    while (i < env->data.map_total_size)
    {
        tmp_min = -0.81649658092 * env->coord[i].z * env->data.deep + (1 / sqrt(6) * (env->coord[i].x + env->coord[i].y)) * env->data.zoom;
        min = tmp_min < min ? tmp_min : min;
        i++;
    }
    min = (min < 0 ? -min : min);
    return (min);
}

static int ft_check_max_y(t_env *env)
{
    int i;
    int max;
    int tmp_max;

    i = 0;
    max = 0;
    tmp_max = 0;
    while (i < env->data.map_total_size)
    {
        tmp_max = -0.81649658092 * env->coord[i].z * env->data.deep + (1 / sqrt(6) * (env->coord[i].x + env->coord[i].y)) * env->data.zoom;
        max = tmp_max > max ? tmp_max : max;
        i++;
    }
    return (max);
}

void ft_get_zoom(t_env *env)
{
    if (env->data.map_total_size <= 250)
        env->data.zoom = 60;
    else if (env->data.map_total_size <= 500)
        env->data.zoom = 50;
    else if (env->data.map_total_size <= 1000)
        env->data.zoom = 40;
    else if (env->data.map_total_size <= 5000)
        env->data.zoom = 30;
    else if (env->data.map_total_size <= 10000)
        env->data.zoom = 10;
    else if (env->data.map_total_size <= 25000)
        env->data.zoom = 8;
    else if (env->data.map_total_size <= 50000)
        env->data.zoom = 5;
    else if (env->data.map_total_size <= 100000)
        env->data.zoom = 4;
    else if (env->data.map_total_size <= 150000)
        env->data.zoom = 3;
    else if (env->data.map_total_size <= 250000)
        env->data.zoom = 2;
    else if (env->data.map_total_size <= 500000)
        env->data.zoom = 1;
    else
        env->data.zoom = 0.5;
}

static void	ft_init_data(t_env *env, int fd, char *input)
{
    env->data.map_length = ft_max_length(input);
    env->data.map_width = ft_width(input);
    env->data.map_total_size = env->data.map_length * env->data.map_width;
    env->data.zoom = 5;
    env->data.deep = 1.5;
}

int main(int args, char **argv)
{
    t_env env;
    char *input;
    int fd;
    int i;

    fd = 0;
    if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
        ft_putstr("Map Error\n");
        return (-1);
    }
    input = ft_get_input(fd);
    ft_init_data(&env, fd, input);
    if (!(env.coord = (t_point*)malloc(sizeof(t_point) * env.data.map_total_size)))
        return (-1);
    ft_coord_in_struct(input, &env, env.data.map_total_size);
    ft_get_zoom(&env);
    env.data.pos_x = ft_check_min_x(&env) + 50;
    env.data.pos_y = ft_check_min_y(&env) + 50;
    env.data.win_width = ft_check_max_x(&env) + env.data.pos_x + 50;
    env.data.win_height = ft_check_max_y(&env) + env.data.pos_y + 50;
    env.data.win_width = (env.data.win_width > 2250) ? 2250 : env.data.win_width;
    env.data.win_height = (env.data.win_height > 1250) ? 1250 : env.data.win_height;
    env.data.mlx = mlx_init();
    env.data.win = mlx_new_window(env.data.mlx, env.data.win_width,
    env.data.win_height, "fdf");
    ft_build_3d(&env);
    ft_printf("map_length >> %d\n", env.data.map_length);
    ft_printf("map_width >> %d\n", env.data.map_width);
    ft_printf("map_total_size >> %d\n", env.data.map_total_size);

    mlx_key_hook(env.data.win, ft_key_interact, &env);

    mlx_loop(env.data.mlx);
}

//    ft_draw_line(10, 5, i, 0, mlx, win);
//    mlx_key_hook(win, ft_print_key_num, 0);
