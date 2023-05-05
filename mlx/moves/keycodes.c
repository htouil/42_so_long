/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:51:45 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:51:45 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	put_keycode(int key, t_axe *axe)
{
	if (key == MU)
		move_up(axe);
	else if (key == ML)
		move_left(axe);
	else if (key == MD)
		move_down(axe);
	else if (key == MR)
		move_right(axe);
	else if (key == ESC)
		destroy_game(axe);
	return (0);
}

int	destroy_game(t_axe *axe)
{
	mlx_destroy_window(axe->win.mlx, axe->win.mlx_win);
	free_tmp(axe->matrix, axe);
	if (axe->check_c == 0)
	{
		write (1, "Congratulations!\n", 17);
		exit(0);
	}
	exit(1);
	return (0);
}
