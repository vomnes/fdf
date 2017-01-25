#include "fdf.h"

int ft_print_key_num(int keycode, void *param)
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
