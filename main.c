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

int ft_get_input(int args, char **argv)
{
    int fd;
    char *line;
    char **tab;
    char *new_line;
    char *tmp;
    int i;

    if ((fd = open(argv[1], O_RDONLY)) < 0)
        return (-1);
    i = 0;
    new_line = ft_strdup("\0");
    while (get_next_line(fd, &line) > 0)
    {
        tmp = ft_strdup(new_line);
        free(new_line);
        new_line = ft_strjoin(tmp, line);
        free(tmp);
        tmp = ft_strdup(new_line);
        free(new_line);
        new_line = ft_strjoin(tmp, "_\n");
        free(line);
        free(tmp);
    }
    ft_putendl(new_line);
    free(new_line);
    close (fd);
    return (0);
}

int ft_get_output(int args, char **argv)
{
    int fd;
    char *line;
    int i;
    int ret;
    char **stock;
    int **int_tab;
    int count;
    int k;

    if ((fd = open(argv[1], O_RDONLY)) < 0)
        return (-1);
    ret = 0;
    i = 0;
    if (!(int_tab = (int**)ft_memalloc(sizeof(*int_tab) * 11)))
        return (-1);
    while (get_next_line(fd, &line) > 0)
    {
        ft_printf("%s\n", line);
        if (!(stock = ft_strsplit(line, ' ')))
            return (-1);
        k = 0;
        count = 0;
        while (stock[count])
            count++;
        k = 0;
        if (!(int_tab[i] = (int*)ft_memalloc(sizeof(int_tab) * count)))
            return (-1);
        while (stock[k])
        {
            int_tab[i][k] = ft_atoi(stock[k]);
            //ft_putendl(stock[k]);
            free(stock[k]);
            stock[k] = NULL;
            k++;
        }
        free(line);
        line = NULL;
        free(stock);
        i++;
    }
    free(line);
    close (fd);
    return (0);
}

int main(int args, char **argv)
{
    void *mlx;
    void *win;
    int i;
    int k;

    ft_get_input(args, argv);
    sleep(10);
    /*mlx = mlx_init();
    win = mlx_new_window(mlx, 600, 600, "fdf");
    ft_draw_line(10, 5, i, 0, mlx, win);
    mlx_key_hook(win, ft_print_key_num, 0);
    mlx_key_hook(win, ft_push_exit, 0);
    mlx_loop(mlx);*/
}
