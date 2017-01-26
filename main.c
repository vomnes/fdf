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

int main(int args, char **argv)
{
    void *mlx;
    void *win;
    int fd;
    int i;
    char *input;
    t_point *coord;
    int length;
    int width;

    fd = 0;
    if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
        ft_putstr("Map Error\n");
        return (-1);
    }
    input = ft_get_input(fd);
    length = ft_max_length(input);
    width = ft_width(input);
    if (!(coord = (t_point*)malloc(sizeof(t_point) * (length * width))))
        return (-1);
    ft_coord_in_struct(input, coord, length * width);

    mlx = mlx_init();
    win = mlx_new_window(mlx, 2500, 1000, "fdf");
    ft_build_3d(coord, length, width, mlx, win);
    mlx_key_hook(win, ft_push_exit, 0);
    mlx_loop(mlx);
}

//    ft_draw_line(10, 5, i, 0, mlx, win);
//    mlx_key_hook(win, ft_print_key_num, 0);
