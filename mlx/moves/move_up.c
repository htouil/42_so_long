/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:45:20 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:45:21 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	cdts_for_up1(t_axe *axe, int i, int j)
{
	if (axe->matrix[j - 1][i] == 'E')
	{
		axe->matrix[j][i] = '0';
		axe->matrix[j - 1][i] = 'P';
		put_floor_onmap(axe, i, j);
		put_player_onmap(axe, i, j - 1);
		if (axe->check_c == 0)
			destroy_game(axe);
		return ;
	}
}

void	cdts_for_up2(t_axe *axe, int i, int j)
{
	if (axe->matrix[j - 1][i] == '0')
	{
		axe->matrix[j][i] = '0';
		axe->matrix[j - 1][i] = 'P';
		put_floor_onmap(axe, i, j);
		put_player_onmap(axe, i, j - 1);
		return ;
	}
	else if (axe->matrix[j - 1][i] == 'C')
	{
		axe->matrix[j][i] = '0';
		axe->matrix[j - 1][i] = 'P';
		axe->check_c--;
		put_floor_onmap(axe, i, j);
		put_floor_onmap(axe, i, j - 1);
		put_player_onmap(axe, i, j - 1);
		return ;
	}
}

void	merge_cdts_up(t_axe *axe, int i, int j)
{
	if (i == axe->e_x && j == axe->e_y)
	{
		if (axe->matrix[j - 1][i] != 'C')
			put_player_onmap(axe, i, j - 1);
		else
		{
			axe->check_c--;
			put_floor_onmap(axe, i, j);
			put_player_onmap(axe, i, j - 1);
		}
		axe->matrix[j][i] = 'E';
		axe->matrix[j - 1][i] = 'P';
		put_floor_onmap(axe, i, j);
		put_exit_onmap(axe, i, j);
		return ;
	}
	else if (axe->matrix[j - 1][i] == 'E')
		cdts_for_up1(axe, i, j);
	else if (axe->matrix[j - 1][i] == '0' || axe->matrix[j - 1][i] == 'C')
		cdts_for_up2(axe, i, j);
}

void	move_up(t_axe *axe)
{
	int		i;
	int		j;

	j = 0;
	while (j < axe->rows)
	{
		i = 0;
		while (i < axe->columns)
		{
			if ((axe->matrix[j][i] == 'P') && (axe->matrix[j - 1][i] != '1'))
			{
				merge_cdts_up(axe, i, j);
				display_moves(axe);
				return ;
			}
			i++;
		}
		j++;
	}
}
