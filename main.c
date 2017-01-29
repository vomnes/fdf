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

static int ft_check_min_x(t_point *coord, t_data *data)
{
    int i;
    int min;
    int tmp_min;

    i = 0;
    min = 0;
    tmp_min = 0;
    while (i < data->map_total_size)
    {
        tmp_min = sqrt(2)/2 * (coord[i].x - coord[i].y) * data->zoom;
        min = tmp_min < min ? tmp_min : min;
        i++;
    }
    min = (min < 0 ? -min : min);
    return (min);
}

static int ft_check_max_x(t_point *coord, t_data *data)
{
    int i;
    int max;
    int tmp_max;

    i = 0;
    max = 0;
    tmp_max = 0;
    while (i < data->map_total_size)
    {
        tmp_max = sqrt(2)/2 * (coord[i].x - coord[i].y) * data->zoom;
        max = tmp_max > max ? tmp_max : max;
        i++;
    }
    return (max);
}

static int ft_check_min_y(t_point *coord, t_data *data)
{
    int i;
    int min;
    int tmp_min;

    i = 0;
    min = 0;
    tmp_min = 0;
    while (i < data->map_total_size)
    {
        tmp_min = -0.81649658092 * coord[i].z * data->deep + (1 / sqrt(6) * (coord[i].x + coord[i].y)) * data->zoom;
        min = tmp_min < min ? tmp_min : min;
        i++;
    }
    min = (min < 0 ? -min : min);
    return (min);
}

static int ft_check_max_y(t_point *coord, t_data *data)
{
    int i;
    int max;
    int tmp_max;

    i = 0;
    max = 0;
    tmp_max = 0;
    while (i < data->map_total_size)
    {
        tmp_max = -0.81649658092 * coord[i].z * data->deep + (1 / sqrt(6) * (coord[i].x + coord[i].y)) * data->zoom;
        max = tmp_max > max ? tmp_max : max;
        i++;
    }
    return (max);
}

static void	ft_init_data(t_data *data, int fd)
{

    data->win_width = 0;
    data->win_height = 0;
    data->input = ft_get_input(fd);
    data->map_length = ft_max_length(data->input);
    data->map_width = ft_width(data->input);
    data->map_total_size = data->map_length * data->map_width;
    data->zoom = 80;
    data->pos_x = 0;
    data->pos_y = 0;
    data->deep = 10;
}

int ft_move_xy(int keycode, t_data *data, void *param);

int expose_hook(t_point *coord, t_data *data)
{
    ft_build_3d(coord, data);
    return (0);
}

int main(int args, char **argv)
{
    t_point *coord;
    t_data  data;
    int fd;
    int i;

    fd = 0;
    if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
        ft_putstr("Map Error\n");
        return (-1);
    }
    ft_init_data(&data, fd);
    if (!(coord = (t_point*)malloc(sizeof(t_point) * data.map_total_size)))
        return (-1);
    ft_coord_in_struct(data.input, coord, data.map_total_size);
    data.pos_x = ft_check_min_x(coord, &data) + 50;
    data.pos_y = ft_check_min_y(coord, &data) + 50;
    data.win_width = ft_check_max_x(coord, &data) + data.pos_x + 50;
    data.win_height = ft_check_max_y(coord, &data) + data.pos_y + 50;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, data.win_width,
    data.win_height, "fdf");
    ft_build_3d(coord, &data);
    //mlx_key_hook(data.win, ft_print_key_num, 0);
    mlx_key_hook(data.win, ft_push_exit, 0);
//    mlx_expose_hook(data.win, expose_hook, 0);
//    mlx_key_hook(data.win, &ft_move_xy, 0);
    mlx_loop(data.mlx);
}

//    ft_draw_line(10, 5, i, 0, mlx, win);
//    mlx_key_hook(win, ft_print_key_num, 0);
