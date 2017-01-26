# include "fdf.h"

int ft_build_3d(t_point *coord, int length, int width, void *mlx, void *win)
{
    int new_x;
    int new_y;
    int new_x_right;
    int new_y_right;
    int new_x_down;
    int new_y_down;
    int i;

    i = 0;
    while (i < length * width)
    {
        if (coord[i].x < length - 1)
            ft_draw_line(coord[i].x + 5 * coord[i].x + 5, coord[i].y + 5 * coord[i].y + 5,
            coord[i + 1].x + 5 * coord[i + 1].x + 5, coord[i + 1].y + 5 * coord[i + 1].y + 5, mlx, win);
        if (coord[i].y < width - 1)
            ft_draw_line(coord[i].x + 5 * coord[i].x + 5, coord[i].y + 5 * coord[i].y + 5,
            coord[i + length].x + 5 * coord[i + length].x + 5, coord[i + length].y + 5 * coord[i + length].y + 5, mlx, win);
        i++;
    }
    return (0);
}

//    new_x = sqrt(2)/2 * (x - y);
//    new_y = sqrt((2 / 3) * z) - (1 / sqrt(6) * (x + y));
