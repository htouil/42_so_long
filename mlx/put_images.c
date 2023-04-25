/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:34:16 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:34:17 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_first_layer(t_axe *axe)
{
	int	i;
	int	j;

	j = -1;
	while (++j < axe->rows)
	{
		i = -1;
		while (++i < axe->columns)
		{
			put_floor_onmap(axe, i, j);
			if (axe->matrix[j][i] == '1')
				put_wall_onmap(axe, i, j);
			if (axe->matrix[j][i] == 'C')
				put_collectible_onmap(axe, i, j);
			if (axe->matrix[j][i] == 'P')
				put_player_onmap(axe, i, j);
			if (axe->matrix[j][i] == 'E')
				put_exit_onmap(axe, i, j);
		}
	}
}

void	put_images_onmap(t_axe *axe)
{
	axe->win.len = axe->columns * 32;
	axe->win.wid = axe->rows * 32;
	axe->mv_count = 0;
	axe->win.mlx = mlx_init();
	axe->win.mlx_win = mlx_new_window(axe->win.mlx, axe->win.len,
			axe->win.wid, "so_long");
	put_first_layer(axe);
	mlx_hook(axe->win.mlx_win, 2, 0, put_keycode, axe);
	mlx_hook(axe->win.mlx_win, 17, 0, destroy_game, axe);
	mlx_loop(axe->win.mlx);
}
