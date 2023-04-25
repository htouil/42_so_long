/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:27:45 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:27:45 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_map_errors0(char *arg)
{
	if (check_map_extension(arg) == 0)
	{
		write (1, "Error\nThe file extention is not `.ber`!\n", 40);
		exit(1);
	}
}

void	display_map_errors1(t_axe *axe)
{
	if (check_map_frame1(axe) == 0 || check_map_frame2(axe) == 0)
	{
		write (1, "Error\nThe map is not fully surrounded with walls!\n", 50);
		free_tmp(axe->matrix, axe);
		exit(1);
	}
	if (check_map_content(axe) == 0)
	{
		write (1, "Error\nThe map doesn't have all the contents needed!\n", 52);
		free_tmp(axe->matrix, axe);
		exit(1);
	}
}

void	display_map_errors2(t_axe *axe)
{
	if (check_map_collectibles(axe) == 0)
	{
		write (1, "Error\nThe map has less than 1 collectible!\n", 43);
		free_tmp(axe->matrix, axe);
		exit(1);
	}
	if (check_map_player(axe) == 0 || check_map_player(axe) == 2)
	{
		write (1, "Error\nThe map doesn't have one and one only player!\n", 52);
		free_tmp(axe->matrix, axe);
		exit(1);
	}
	if (check_map_exit(axe) == 0 || check_map_exit(axe) == 2)
	{
		write (1, "Error\nThe map doesn't have one and one only exit!\n", 50);
		free_tmp(axe->matrix, axe);
		exit(1);
	}
	if (check_map_path1(axe) == 0)
	{
		write (1, "Error\nThe map has an invalid path!\n", 35);
		free_tmp(axe->matrix, axe);
		exit(1);
	}
}
