/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 08:34:42 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/01 10:05:57 by vomnes           ###   ########.fr       */
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

# define KEY_W 13
# define KEY_M 46
# define KEY_G 5
# define KEY_F 3
# define KEY_O 31

# define KEY_SPACE 49
# define KEY_ESCAPE 53
# define KEY_PLUS 69
# define KEY_LESS 78
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

# define COLOR_GOLD 0x00ffcc00
# define COLOR_BLACK 0x00000000
# define COLOR_WHITE 0x00ffffff;
# define COLOR_BLACK_BROWN 0x002F1D13;
# define COLOR_LIGHT_BROWN 0x00A05A00;
# define COLOR_GREEN_YELLOW 0x00B59F25;
# define COLOR_YELLOW 0x00E6E632;
# define COLOR_BROWN 0x007d4c00;
# define COLOR_GREEN 0x0016ac07;
# define COLOR_DARK_GREEN 0x00078734;
# define COLOR_BLUE 0x000c6cd1;
# define COLOR_BLUE_BBR 0x000023864;
# define COLOR_RED_BBR 0x000D50020;

typedef	struct		s_color
{
	char			rgb_hex[10];
	int				rgb_int;
	int				pick_up;
}					t_color;

typedef	struct		s_point
{
	int				x;
	int				y;
	int				z;
	t_color			color;
}					t_point;

typedef	struct		s_data
{
	void			*mlx;
	void			*win;
	int				win_width;
	int				win_height;
	char			*input;
	int				map_length;
	int				map_width;
	int				map_total_size;
	int				pos_x;
	int				pos_x_start;
	int				pos_y;
	int				pos_y_start;
	float			zoom;
	float			zoom_start;
	float			deep;
	int				x_max;
	int				x_min;
	int				y_max;
	int				y_min;
	int				z_max;
	int				z_min;
}					t_data;

typedef	struct		s_print
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				color;
}					t_print;

typedef enum		e_type_color
{
	white,
	map,
	gold,
	bbr,
	original
}					t_type_color;

typedef	struct		s_listcolor
{
	int				ten;
	int				nine;
	int				eight;
	int				seven;
	int				six;
	int				five;
	int				four;
	int				three;
	int				two;
	int				one;
	int				zero;
	t_type_color	scale;
}					t_listcolor;

typedef	struct		s_env
{
	t_point			*coord;
	t_data			data;
	t_print			print;
	t_listcolor		color;
}					t_env;

typedef	struct		s_edit
{
	float			x_a;
	float			y_a;
	float			x_b;
	float			y_b;
	float			x_c;
	float			y_c;
}					t_edit;

typedef	struct		s_index
{
	int				i;
	int				x;
	int				y;
	int				index;
}					t_index;

char				*ft_get_input(int fd);
void				ft_init_data(t_env *env, char *input);
int					ft_max_length(char *input);
int					ft_width(char *input);
int					ft_coord_in_struct(char *input, t_env *env);
void				ft_set_up_data(t_env *env);
void				ft_get_max_min_xyz(t_env *env);

void				ft_build_iso(t_env *env);

void				ft_color_type_map(t_env *env);
void				ft_color_type_white(t_env *env);
void				ft_color_type_gold(t_env *env);
void				ft_color_type_original(t_env *env);
void				ft_color_type_blue_red_white(t_env *env);
void				ft_manage_colors(t_env *env, int *i, int plus);

int					ft_draw_line(t_env *env);

int					ft_interaction_color(int keycode, t_env *env);
int					ft_key_interact(int keycode, t_env *env);

#endif
