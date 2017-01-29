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

static void	ft_init_data(t_data *data, int fd)
{

    data->win_width = 600;
    data->win_height = 600;
    data->input = ft_get_input(fd);
    data->map_length = ft_max_length(data->input);
    data->map_width = ft_width(data->input);
    data->map_total_size = data->map_length * data->map_width;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->win_width,
    data->win_height, "fdf");
    data->pos_x = 350;
    data->pos_y = 350;
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
    ft_build_3d(coord, &data);
    //mlx_key_hook(data.win, ft_print_key_num, 0);
    mlx_key_hook(data.win, ft_push_exit, 0);
    //mlx_key_hook(data.win, ft_move_xy, 0);
    mlx_loop(data.mlx);
}

//    ft_draw_line(10, 5, i, 0, mlx, win);
//    mlx_key_hook(win, ft_print_key_num, 0);
