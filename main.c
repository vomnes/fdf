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
    int length_width;

    if ((fd = open(argv[1], O_RDONLY)) < 0)
        return (-1);
    input = ft_get_input(fd);
    length_width = ft_size_input(input);
    if (!(coord = (t_point*)malloc(sizeof(t_point) * length_width)))
        return (-1);
    ft_transform_input(input, coord, length_width);
    /*mlx = mlx_init();
    win = mlx_new_window(mlx, 600, 600, "fdf");
    ft_draw_line(10, 5, i, 0, mlx, win);
    mlx_key_hook(win, ft_print_key_num, 0);
    mlx_key_hook(win, ft_push_exit, 0);
    mlx_loop(mlx);*/
}
