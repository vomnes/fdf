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

static void ft_get_max_min_xyz(t_env *env)
{
    int i;
    int tmp_x;
    int tmp_y;
    int tmp_z;

    i = -1;
    tmp_x = 0;
    tmp_y = 0;
    tmp_z = 0;
    while (++i < env->data.map_total_size)
    {
        tmp_x = sqrt(2) / 2 * (env->coord[i].x - env->coord[i].y) *
        env->data.zoom;
        env->data.x_max = tmp_x > env->data.x_max ? tmp_x : env->data.x_max;
        env->data.x_min = tmp_x < env->data.x_min ? tmp_x : env->data.x_min;
        tmp_y = -0.81649658092 * env->coord[i].z * env->data.deep +
        (1 / sqrt(6) * (env->coord[i].x + env->coord[i].y)) * env->data.zoom;
        env->data.y_max = tmp_y > env->data.y_max ? tmp_y : env->data.y_max;
        env->data.y_min = tmp_y < env->data.y_min ? tmp_y : env->data.y_min;
        tmp_z = env->coord[i].z;
        env->data.z_max = tmp_z > env->data.z_max ? tmp_z : env->data.z_max;
        env->data.z_min = tmp_z < env->data.z_min ? tmp_z : env->data.z_min;
    }
    env->data.y_min = (env->data.y_min < 0 ? -env->data.y_min : env->data.y_min);
    env->data.x_min = (env->data.x_min < 0 ? -env->data.x_min : env->data.x_min);
}

//ft_printf(">data.x_max : %d - data.x_min : %d\n", env->data.x_max, env->data.x_min);
//ft_printf(">data.y_max : %d - data.y_min : %d\n", env->data.y_max, env->data.y_min);
//ft_printf(">data.z_max : %d - data.z_min : %d\n", env->data.z_max, env->data.z_min);

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
    env->data.zoom_start = env->data.zoom;
}

static void	ft_init_data(t_env *env, int fd, char *input)
{
    env->data.map_length = ft_max_length(input);
    env->data.map_width = ft_width(input);
    env->data.map_total_size = env->data.map_length * env->data.map_width;
    if (env->data.map_total_size <= 300000)
        env->data.deep = 1.5;
    else
        env->data.deep = 0.1;
    env->data.x_max = 0;
    env->data.x_min = 0;
    env->data.y_max = 0;
    env->data.y_min = 0;
    env->data.z_max = 0;
    env->data.z_min = 0;
}

static void	ft_set_up_data(t_env *env)
{
    ft_get_zoom(env);
    ft_get_max_min_xyz(env);
    env->data.pos_x = env->data.x_min + 50;
    env->data.pos_y = env->data.y_min + 50;
    env->data.pos_x_start = env->data.pos_x;
    env->data.pos_y_start = env->data.pos_y;
    env->data.win_width = env->data.x_max + env->data.pos_x + 50;
    env->data.win_height = env->data.y_max + env->data.pos_y + 50;
    env->data.win_width =
    (env->data.win_width > 2250) ? 2250 : env->data.win_width;
    env->data.win_height =
    (env->data.win_height > 1250) ? 1250 : env->data.win_height;
    env->data.mlx = mlx_init();
    env->data.win = mlx_new_window(env->data.mlx, env->data.win_width,
    env->data.win_height, "fdf");
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
    ft_set_up_data(&env);
    ft_build_iso(&env);
    ft_printf("map_length >> %d\n", env.data.map_length);
    ft_printf("map_width >> %d\n", env.data.map_width);
    ft_printf("map_total_size >> %d\n", env.data.map_total_size);
    mlx_key_hook(env.data.win, ft_key_interact, &env);
    mlx_loop(env.data.mlx);
}

//    ft_draw_line(10, 5, i, 0, mlx, win);
//    mlx_key_hook(win, ft_print_key_num, 0);
