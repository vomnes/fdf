/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 08:31:58 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/01 09:34:17 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int args, char **argv)
{
	t_env	env;
	char	*input;
	int		fd;
	int		i;

	fd = 0;
	if (args != 2)
	{
		ft_putstr("usage : fdf map_file\n");
		return (0);
	}
	if (open(argv[1], O_DIRECTORY) > 0)
	{
		ft_putstr("Map Error\n");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr("Map Error\n");
		return (-1);
	}
	input = ft_get_input(fd);
	ft_init_data(&env, input);
	if (!(env.coord = (t_point*)malloc(sizeof(t_point) *
	env.data.map_total_size)))
		return (-1);
	ft_coord_in_struct(input, &env);
	ft_set_up_data(&env);
	ft_build_iso(&env);
	mlx_key_hook(env.data.win, ft_key_interact, &env);
	mlx_loop(env.data.mlx);
}
