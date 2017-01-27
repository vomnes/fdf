/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 08:49:44 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/25 08:49:46 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
//mlx_key_hook(win, ft_add, 0);
