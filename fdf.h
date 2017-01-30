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

# define KEY_Q 12
# define KEY_P 35
# define KEY_L 37
# define KEY_SPACE 49
# define KEY_ESCAPE 53
# define KEY_PLUS 69
# define KEY_LESS 78
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
    int             pos_x_start;
    int             pos_y;
    int             pos_y_start;
    float           zoom;
    float           zoom_start;
    float           deep;
}                   t_data;

typedef	struct		s_env
{
    t_point         *coord;
    t_print         print;
    t_data          data;
}                   t_env;



char        *ft_get_input(int fd);

int         ft_coord_in_struct(char *input, t_env *env, int len);

int			ft_max_length(char *input);
int			ft_width(char *input);

int ft_build_3d(t_env *env);

int         ft_draw_line(t_env *env);

int ft_key_interact(int keycode, t_env *env);

#endif
