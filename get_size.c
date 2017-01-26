/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:48:37 by vomnes            #+#    #+#             */
/*   Updated: 2017/01/26 18:48:39 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int			ft_max_length(char *input)
{
	int i;
	int length;
    int max_length;

	i = 0;
	length = 0;
    max_length = 0;
	while (input[i] != '\0')
	{
		if (ft_isxdigit(input[i]) && input[i + 1] == ' ')
			length++;
        if ((ft_isxdigit(input[i]) && input[i + 1] == '\n') ||
        (input[i] == ' ' && input[i + 1] == '\n'))
        {
            if (input[i] == ' ' && input[i + 1] == '\n')
                ;
            else
                length++;
            max_length = (length > max_length) ? length : max_length;
            length = 0;
        }
		i++;
	}
	return (max_length);
}

int			ft_width(char *input)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (input[i] != '\0')
	{
        if (ft_isxdigit(input[i]) && (input[i + 1] == '\n'
        || (input[i + 1] == ' ' && input[i + 2] == '\n')))
            width++;
		i++;
	}
	return (width);
}
