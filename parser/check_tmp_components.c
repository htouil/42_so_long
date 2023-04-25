/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tmp_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:22:29 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:22:30 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_tmp_collectibles(char **tmp, t_axe *axe)
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
			if (tmp[j][i] == 'C')
				k++;
			i++;
		}
		j++;
	}
	if (k == 0)
		return (0);
	return (1);
}

int	check_tmp_exit(char **tmp, t_axe *axe)
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
			if (tmp[j][i] == 'E')
				k++;
			i++;
		}
		j++;
	}
	if (k == 0)
		return (0);
	return (1);
}
