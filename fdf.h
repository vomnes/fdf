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

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

typedef	struct		s_print
{
    int              x0;
    int              y0;
    int              x1;
    int              y1;
    int              color;
}                   t_print;

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

typedef	struct		s_data
{
    void            *mlx;
    void            *win;
    int             win_width;
    int             win_height;
    char            *input;
    int             map_length;
    int             map_width;
    int             map_total_size;
    int             pos_x;
    int             pos_y;
    float             zoom;
    float           deep;
}                   t_data;




char        *ft_get_input(int fd);

int         ft_coord_in_struct(char *input, t_point *coord, int len);

int			ft_max_length(char *input);
int			ft_width(char *input);

int ft_build_3d(t_point *coord, t_data *data, t_print *print);

int         ft_draw_line(t_print *print, t_data *data);

int         ft_print_key_num(int keycode, void *param);
int         ft_push_exit(int keycode, void *param);

#endif
