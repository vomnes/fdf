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

int			ft_max_length(char *input)
{
	int i;
	int length;
    int max_length;

	i = 0;
	length = 0;
    max_length = 0;
	while (input[i] != '\0')
	{
		if (ft_isxdigit(input[i]) && input[i + 1] == ' ')
			length++;
        if (ft_isxdigit(input[i]) && input[i + 1] == '\n')
        {
            length++;
            max_length = (length > max_length) ? length : max_length;
            length = 0;
        }
		i++;
	}
	return (max_length);
}

int			ft_width(char *input)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (input[i] != '\0')
	{
        if (ft_isxdigit(input[i]) && input[i + 1] == '\n')
                width++;
		i++;
	}
	return (width - 1);
}

int ft_build_3d(t_point *coord, int length_width, int max_len, void *mlx, void *win, int width)
{
    int new_x;
    int new_y;
    int new_x_right;
    int new_y_right;
    int new_x_down;
    int new_y_down;
    float cte1;
    float cte2;
    int i;

    i = 0;
    cte1 = 0.75;
    cte2 = 0.90;
    while (i < length_width)
    {
        printf(">> x: %10d - y: %10d - z: %10d | %d %d %d\n", coord[i].x, coord[i].y, coord[i].z, i, i + 1, i + max_len);
/*        new_x = cte1 * coord[i].x - cte2 * coord[i].y;
        new_y = 0 + (cte1 / 2) * coord[i].x +  (cte2 / 2) * coord[i].y;
        new_x *= 50;
        new_y *= 50;
    //    printf("x: %10d - y: %10d\n", abs(new_x), abs(new_y));
        new_x_right = cte1 * coord[i + 1].x - cte2 * coord[i + 1].y;
        new_y_right = 0 + (cte1 / 2) * coord[i + 1].x +  (cte2 / 2) * coord[i].y;
        new_x_right *= 50;
        new_y_right *= 50;
        new_x_down = cte1 * coord[i + max_len].x - cte2 * coord[i + max_len].y;
        new_y_down = 0 + (cte1 / 2) * coord[i + max_len].x +  (cte2 / 2) * coord[i].y;
        new_x_down *= 50;
        new_y_down *= 50;*/
    //    printf("x: %10d - y: %10d\n", abs(new_x_right), abs(new_y_right));
        new_x = sqrt(2)/2 * (coord[i].x - coord[i].y);
        new_y = sqrt(2 / 3) * 0 - (1 / sqrt(6)) * (coord[i].x + coord[i].y);
        new_x *= 50;
        new_y *= 50;
        new_x_right = sqrt(2)/2 * (coord[i + 1].x - coord[i + 1].y);
        new_y_right = sqrt(2 / 3) * 0 - (1 / sqrt(6)) * (coord[i + 1].x + coord[i + 1].y);
        new_x_right *= 50;
        new_y_right *= 50;
        new_x_down = sqrt(2)/2 * (coord[i + max_len].x - coord[i + max_len].y);
        new_y_down = sqrt(2 / 3) * 0 - (1 / sqrt(6)) * (coord[i + max_len].x + coord[i + max_len].y);
        new_x_down *= 50;
        new_y_down *= 50;
    //    printf("x: %10d - y: %10d\n", abs(new_x_down), abs(new_y_down));
    //    ft_printf("ft_draw_line(%d, %d, %d, %d, mlx, win)", new_x, new_x, new_x_right, new_y_right);
        if (coord[i].x < max_len - 1 && abs(new_x - new_y) != 0 && abs(new_x_right - new_y_right) != 0)
            ft_draw_line(new_x, new_x, new_x_right, new_y_right, mlx, win);
    //    ft_printf("ft_draw_line(%d, %d, %d, %d, mlx, win)", new_x, new_x, abs(new_x_down), abs(new_y_down));
        if (coord[i].y < width - 1 && abs(new_x - new_y) != 0 && abs(new_x_right - new_y_right) != 0)
            ft_draw_line(new_x, new_x, new_x_down, new_y_down, mlx, win);
        i++;
    }
    return (0);
}

//    new_x = sqrt(2)/2 * (x - y);
//    new_y = sqrt((2 / 3) * z) - (1 / sqrt(6) * (x + y));

int main(int args, char **argv)
{
    void *mlx;
    void *win;
    int fd;
    int i;
    char *input;
    t_point *coord;
    int length_width;
    int max_len;

    fd = 0;
    if ((fd = open(argv[1], O_RDONLY)) < 0)
        return (-1);
    input = ft_get_input(fd);
    length_width = ft_size_input(input);
    if (!(coord = (t_point*)malloc(sizeof(t_point) * length_width)))
        return (-1);
    ft_coord_in_struct(input, coord, length_width);
    max_len = ft_max_length(input);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1000, 1000, "fdf");
//    ft_draw_line(0, -6, 1, -7, mlx, win);
    ft_build_3d(coord, length_width, max_len, mlx, win, ft_width(input));
    mlx_key_hook(win, ft_push_exit, 0);
    mlx_loop(mlx);
}

//    ft_draw_line(10, 5, i, 0, mlx, win);
//    mlx_key_hook(win, ft_print_key_num, 0);
