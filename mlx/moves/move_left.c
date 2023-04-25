/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:45:10 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:45:12 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	cdts_for_left1(t_axe *axe, int i, int j)
{
	if (axe->matrix[j][i - 1] == 'E')
	{
		axe->matrix[j][i] = '0';
		axe->matrix[j][i - 1] = 'P';
		put_floor_onmap(axe, i, j);
		put_player_onmap(axe, i - 1, j);
		if (axe->check_c == 0)
			destroy_game(axe);
		return ;
	}
}

void	cdts_for_left2(t_axe *axe, int i, int j)
{
	if (axe->matrix[j][i - 1] == '0')
	{
		axe->matrix[j][i] = '0';
		axe->matrix[j][i - 1] = 'P';
		put_floor_onmap(axe, i, j);
		put_player_onmap(axe, i - 1, j);
		return ;
	}
	else if (axe->matrix[j][i - 1] == 'C')
	{
		axe->matrix[j][i] = '0';
		axe->matrix[j][i - 1] = 'P';
		axe->check_c--;
		put_floor_onmap(axe, i, j);
		put_floor_onmap(axe, i - 1, j);
		put_player_onmap(axe, i - 1, j);
		return ;
	}
}

void	merge_cdts_left(t_axe *axe, int i, int j)
{
	if (i == axe->e_x && j == axe->e_y)
	{
		if (axe->matrix[j][i - 1] != 'C')
			put_player_onmap(axe, i - 1, j);
		else
		{
			axe->check_c--;
			put_floor_onmap(axe, i, j);
			put_player_onmap(axe, i - 1, j);
		}
		axe->matrix[j][i] = 'E';
		axe->matrix[j][i - 1] = 'P';
		put_floor_onmap(axe, i, j);
		put_exit_onmap(axe, i, j);
		return ;
	}
	else if (axe->matrix[j][i - 1] == 'E')
		cdts_for_left1(axe, i, j);
	else if (axe->matrix[j][i - 1] == '0' || axe->matrix[j][i - 1] == 'C')
		cdts_for_left2(axe, i, j);
}

void	move_left(t_axe *axe)
{
	int		i;
	int		j;

	j = 0;
	while (j < axe->rows)
	{
		i = 0;
		while (i < axe->columns)
		{
			if ((axe->matrix[j][i] == 'P') && (axe->matrix[j][i - 1] != '1'))
			{
				merge_cdts_left(axe, i, j);
				display_moves(axe);
				return ;
			}
			i++;
		}
		j++;
	}
}
