/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:23:06 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 19:23:08 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_errors(char *arg, t_axe *axe)
{
	int	fd;

	display_map_errors0(arg);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		write (1, "ERROR\nInvalid file!\n", 20);
		exit (1);
	}
	get_map_matrix(fd, axe);
	display_map_errors1(axe);
	display_map_errors2(axe);
	close(fd);
}

int	main(int ac, char **av)
{
	t_axe	axe;

	if (ac != 2)
		return (1);
	test_errors(av[1], &axe);
	put_images_onmap(&axe);
	return (0);
}
