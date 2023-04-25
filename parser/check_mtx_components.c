/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mtx_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:19:30 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:19:31 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_content(t_axe *axe)
{
	int		i;
	int		j;

	j = 0;
	while (j < axe->rows)
	{
		i = 0;
		while (i < axe->columns)
		{
			if (axe->matrix[j][i] != '0' && axe->matrix[j][i] != '1'
			&& axe->matrix[j][i] != 'C' && axe->matrix[j][i] != 'E'
			&& axe->matrix[j][i] != 'P')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_map_collectibles(t_axe *axe)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < axe->rows)
	{
		i = 0;
		while (i < axe->columns)
		{
			if (axe->matrix[j][i] == 'C')
			{
				axe->check_c++;
				k++;
			}
			i++;
		}
		j++;
	}
	if (k < 1)
		return (0);
	return (1);
}

int	check_map_player(t_axe *axe)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < axe->rows)
	{
		i = 0;
		while (i < axe->columns)
		{
			if (axe->matrix[j][i] == 'P')
			{
				axe->check_p++;
				k++;
			}
			i++;
		}
		j++;
	}
	if (k == 0)
		return (0);
	else if (k > 1)
		return (2);
	return (1);
}

int	check_map_exit(t_axe *axe)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (++j < axe->rows)
	{
		i = -1;
		while (++i < axe->columns)
		{
			if (axe->matrix[j][i] == 'E')
			{
				axe->e_x = i;
				axe->e_y = j;
				axe->check_e++;
				k++;
			}
		}	
	}
	if (k == 0)
		return (0);
	else if (k > 1)
		return (2);
	return (1);
}
