#include "libft.h"
#include "ft_printf.h"
#include <mlx.h>
#include <math.h>

# define KEY_ESCAPE 53
# define KEY_Q 12

int ft_put_key_num(int keycode, void *param)
{
    ft_printf("Key event --> %d\n", keycode);
    return (0);
}

int ft_push_exit(int keycode, void *param)
{
    if (keycode == KEY_ESCAPE || keycode == KEY_Q)
        exit(1);
    return (0);
}

int ft_draw_line_one(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
    int dx;
    int dy;
    int x;

    if (x1 - x0 < 0 && y1 - y0 >= 0)
    {
        ft_swap(&x0, &x1);
        ft_swap(&y0, &y1);
    }
    else if (x1 - x0 < 0 && y1 - y0 < 0)
    {
        ft_swap(&x0, &x1);
        ft_swap(&y0, &y1);
    }
    dx = x1 - x0;
    dy = y1 - y0;
    ft_printf("x0: %3d y0: %3d\n", x0, y0);
    ft_printf("x1: %3d y1: %3d\n", x1, y1);
    ft_printf("dx: %3d dy: %3d\n\n", dx, dy);
    x = x0;
    while (x <= x1)
    {
        mlx_pixel_put(mlx, win, x, y0 + (dy * (x - x0) / dx), 0x00FAAFF);
        x++;
    }
    return (0);
}

int ft_check_draw(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
//    if (x0 <= x1 && ((x1 - x0) >= abs(y1 - y0)))
//    {
//        ft_printf("one\n");
//        if (x1 - x0 < 0 || y1 - y0 < 0)
//        {
//            ft_swap(&x0, &x1);
//            ft_swap(&y0, &y1);
//        }
        ft_draw_line_one(x0, y0, x1, y1, mlx, win);
//    }
//    else
//    {
//        ft_printf("two\n");
//        ft_draw_line_two(x0, y0, x1, y1, mlx, win);
//    }
    return (0);
}


int main()
{
    void *mlx;
    void *win;
    int i;
    int k;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 600, 600, "fdf");
//    ft_check_draw(0, 10, 10, 0, mlx, win);
//    ft_check_draw(0, 0, 10, 10, mlx, win);
    ft_check_draw(10, 0, 0, 10, mlx, win);
    ft_check_draw(10, 10, 0, 0, mlx, win);
//    ft_check_draw(0, 100, 100, 0, mlx, win);
//    ft_check_draw(0, 100, 50, 0, mlx, win);
//    ft_check_draw(50, 0, 0, 100, mlx, win);
    mlx_key_hook(win, ft_put_key_num, 0);
    mlx_key_hook(win, ft_push_exit, 0);
    mlx_loop(mlx);
}

int ft_draw_line_two(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
    int dx;
    int dy;
    int y;

    if (x1 - x0 < 0 && y1 - y0 >= 0)
        ft_swap(&x0, &x1);
    else if (x1 - x0 < 0 && y1 - y0 < 0)
    {
        ft_swap(&x0, &x1);
        ft_swap(&y0, &y1);
    }
    dx = x1 - x0;
    dy = y1 - y0;
    y = y0;
    while (y <= y1)
    {
        mlx_pixel_put(mlx, win, x0 + (dx * (y - y0) / dy), y, 0x00FAAFF);
        y++;
    }
    return (0);
}
