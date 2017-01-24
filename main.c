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

    ft_printf("======BEFORE=====\n");
    ft_printf("x0: %4d y0: %4d\n", x0, y0);
    ft_printf("x1: %4d y1: %4d\n", x1, y1);
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
    ft_printf("======AFTER======\n");
    ft_printf("x0: %4d y0: %4d\n", x0, y0);
    ft_printf("x1: %4d y1: %4d\n", x1, y1);
    ft_printf("dx: %4d dy: %4d\n", dx, dy);
    ft_printf("\n");
    x = x0;
    while (x <= x1)
    {
        mlx_pixel_put(mlx, win, x, y0 + (dy * (x - x0) / dx), 0x00FAAFF);
        x++;
    }
    return (0);
}

int ft_draw_line_two(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
    int dx;
    int dy;
    int y;

    dx = x1 - x0;
    dy = y1 - y0;
    ft_printf("======AFTER======\n");
    ft_printf("x0: %4d y0: %4d\n", x0, y0);
    ft_printf("x1: %4d y1: %4d\n", x1, y1);
    ft_printf("dx: %4d dy: %4d\n", dx, dy);
    y = y0;
    while (y <= y1)
    {
        mlx_pixel_put(mlx, win, x0 + (dx * (y - y0) / dy), y, 0x00FAAFF);
        y++;
    }
    return (0);
}

int ft_check_draw(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
    if (x0 <= x1 && ((x1 - x0) >= abs(y1 - y0)))
    {
        ft_printf("one_a\n");
        ft_draw_line_one(x0, y0, x1, y1, mlx, win);
    }
    else if (x0 > x1 && ((x1 - x0) <= abs(y1 - y0)))
    {
        ft_printf("one_b\n");
        ft_draw_line_one(x1, y1, x0, y0, mlx, win);
    }
    else if (x1 >= x0)
    {
        ft_printf("two_a\n");
        ft_draw_line_two(x0, y0, x1, y1, mlx, win);
    }
    else if (x1 < x0)
    {
        ft_printf("two_b\n");
        ft_draw_line_two(x1, y1, x0, y0, mlx, win);
    }
    return (0);
}
/*
A(-1;4) B(1;0)
y - y0 = (y1 - y0) / x1 - x0 * (x - x1)
*/
int main()
{
    void *mlx;
    void *win;
    int i;
    int k;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 600, 600, "fdf");

    i = 0;
    while (i < 600)
    {
        ft_check_draw(300, 300, i, 0, mlx, win);
        i += 1;
    }
    i = 0;
    while (i < 600)
    {
        ft_check_draw(300, 300, 600, i, mlx, win);
        i += 1;
    }
    i = 600;
    while (i > 0)
    {
        ft_check_draw(300, 300, i, 600, mlx, win);
        i -= 1;
    }
    i = 600;
    while (i > 0)
    {
        ft_check_draw(300, 300, 0, i, mlx, win);
        i -= 1;
    }

//    ft_check_draw(300, 300, 0, 300, mlx, win);
//    ft_check_draw(300, 300, 300, 0, mlx, win);
//    ft_check_draw(300, 300, 600, 600, mlx, win);
//    ft_check_draw(300, 300, 600, 300, mlx, win);
//    ft_check_draw(300, 300, 600, 0, mlx, win);
//    ft_check_draw(300, 300, 300, 600, mlx, win);
//    ft_check_draw(300, 300, 300, 0, mlx, win);
//    ft_check_draw(300, 300, 0, 300, mlx, win);
//    ft_check_draw(300, 300, 0, 600, mlx, win);


/*    ft_check_draw(0, 10, 10, 0, mlx, win);
    ft_check_draw(0, 0, 10, 10, mlx, win);
    ft_check_draw(10, 0, 0, 10, mlx, win);
    ft_check_draw(10, 10, 0, 0, mlx, win);
*/
//    ft_check_draw(10, 60, 10, 160, mlx, win);
//    ft_check_draw(10, 110, 110, 10, mlx, win); //--
//    ft_check_draw(10, 110, 60, 10, mlx, win); //--
/*    ft_check_draw(10, 10, 110, 110, mlx, win); //-a
    ft_check_draw(10, 10, 125, 110, mlx, win); //-a
    ft_check_draw(10, 10, 170, 110, mlx, win); //-a
    ft_check_draw(10, 10, 250, 110, mlx, win); //-a*/

//    ft_check_draw(10, 110, 10, 10, mlx, win);
//    ft_check_draw(20, 110, 10, 10, mlx, win);
//    ft_check_draw(30, 110, 10, 10, mlx, win);
    /*ft_check_draw(60, 110, 10, 10, mlx, win);
    ft_check_draw(85, 110, 10, 10, mlx, win);
    ft_check_draw(100, 110, 10, 10, mlx, win);
    ft_check_draw(110, 110, 10, 10, mlx, win); //-a
    ft_check_draw(125, 110, 10, 10, mlx, win); //-a
    ft_check_draw(170, 110, 10, 10, mlx, win); //-a
    ft_check_draw(250, 110, 10, 10, mlx, win); //-a*/

/*    ft_check_draw(10, 10, 10, 110, mlx, win); //==
    ft_check_draw(10, 10, 30, 110, mlx, win); //==
    ft_check_draw(10, 10, 60, 110, mlx, win); //==
    ft_check_draw(10, 10, 85, 110, mlx, win); //==
    ft_check_draw(10, 10, 100, 110, mlx, win); //==*/

/*    ft_check_draw(10, 10, 10, 10, mlx, win); //==
    ft_check_draw(30, 10, 10, 10, mlx, win); //==
    ft_check_draw(60, 10, 10, 10, mlx, win); //==
    ft_check_draw(85, 10, 10, 10, mlx, win); //==
    ft_check_draw(110, 10, 10, 10, mlx, win); //==*/

/*    ft_check_draw(10, 10, 10, 110, mlx, win); //==
    ft_check_draw(20, 10, 10, 110, mlx, win); //==
    ft_check_draw(30, 10, 10, 110, mlx, win); //==
    ft_check_draw(60, 10, 10, 110, mlx, win); //==
    ft_check_draw(85, 10, 10, 110, mlx, win); //==
    ft_check_draw(110, 10, 10, 110, mlx, win); //==*/
    mlx_key_hook(win, ft_put_key_num, 0);
    mlx_key_hook(win, ft_push_exit, 0);
    mlx_loop(mlx);
}
