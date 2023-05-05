/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:23:59 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 19:24:04 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_dnl_error(char *map_str)
{
	if (check_double_nl(map_str) == 1)
	{
		write (1, "Error\nThe map is not fully surrounded with walls!\n", 50);
		free(map_str);
		exit(1);
	}
}

void	get_map_matrix(int fd, t_axe *axe)
{
	char	*map_str;
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		write (1, "Error\nFile is empty!\n", 21);
		exit (1);
	}
	axe->columns = ft_strlen(line) - 1;
	axe->rows = 0;
	map_str = ft_calloc(1, 1);
	while (1)
	{
		map_str = ft_strjoin(map_str, line);
		axe->rows++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	display_dnl_error(map_str);
	axe->matrix = ft_split(map_str, '\n');
	free(map_str);
}
