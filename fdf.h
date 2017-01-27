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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define KEY_ESCAPE 53
# define KEY_Q 12

typedef	struct		s_color
{
    char            rgb_hex[10];
    int             rgb_int;
    int             pick_up;
}                   t_color;

typedef	struct		s_point
{
    int             x;
    int             y;
    int             z;
    t_color         color;
}                   t_point;

char	*ft_get_input(int fd);

int ft_coord_in_struct(char *input, t_point *coord, int len);

int			ft_max_length(char *input);
int			ft_width(char *input);

int ft_build_3d(t_point *coord, int length, int width, void *mlx, void *win);

int ft_draw_line(int x0, int y0, int x1, int y1, void *mlx, void *win);

int ft_print_key_num(int keycode, void *param);
int ft_push_exit(int keycode, void *param);

#endif
