/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:51:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/26 18:51:29 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
# define BUFF_SIZE 1048576

static char	*ft_realloc(char *buf, int total_size)
{
	char	*new_buf;
	int		i;

    i = 0;
	new_buf = (char*)malloc(sizeof(*new_buf) * (total_size + BUFF_SIZE + 1));
	if (new_buf == NULL)
		exit(-1);
	while (i < total_size)
	{
		new_buf[i] = buf[i];
		i++;
	}
	new_buf[i] = '\0';
	free(buf);
	return (new_buf);
}

char	*ft_get_input(int fd)
{
	char	*buf;
	int		ret;
	int		total_size;

    ret = 0;
	total_size = 0;
	if (!(buf = (char*)malloc(sizeof(*buf) * (BUFF_SIZE + 1))))
		exit(-1);
	while ((ret = read(fd, buf + total_size, BUFF_SIZE)) > 0)
	{
		total_size += ret;
		buf[total_size] = '\0';
		buf = ft_realloc(buf, total_size);
	}
	if (close(fd) == -1)
		exit(-1);
	return (buf);
}
