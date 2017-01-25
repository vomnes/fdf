/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 08:34:42 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/25 08:34:45 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# include <math.h>

# define KEY_ESCAPE 53
# define KEY_Q 12

int ft_draw_line(int x0, int y0, int x1, int y1, void *mlx, void *win);

int ft_print_key_num(int keycode, void *param);
int ft_push_exit(int keycode, void *param);

#endif
