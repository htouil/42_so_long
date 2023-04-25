/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:23:29 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:23:30 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tmp(char **tmp, t_axe *axe)
{
	int	j;

	j = 0;
	while (j < axe->rows)
	{
		if (tmp[j])
			free(tmp[j]);
		j++;
	}
	free(tmp);
}

char	**fill_tmp(t_axe *axe)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = malloc((axe->rows + 1) * sizeof(char *));
	if (!tmp)
		return (0);
	j = -1;
	while (++j < axe->rows)
	{
		tmp[j] = malloc((axe->columns + 1) * sizeof(char));
		if (!tmp[j])
			return (0);
		i = 0;
		while (i < axe->columns)
		{
			tmp[j][i] = axe->matrix[j][i];
			i++;
		}
		tmp[j][i] = '\0';
	}
	tmp[j] = NULL;
	return (tmp);
}

void	check_map_path2(char **tmp, t_axe *axe)
{
	int	i;
	int	j;

	j = 0;
	while (j < axe->rows)
	{
		i = 0;
		while (i < axe->columns)
		{
			if (tmp[j][i] == 'P')
			{
				if (tmp[j - 1][i] != '1')
					tmp[j - 1][i] = 'P';
				if (tmp[j][i + 1] != '1')
					tmp[j][i + 1] = 'P';
				if (tmp[j + 1][i] != '1')
					tmp[j + 1][i] = 'P';
				if (tmp[j][i - 1] != '1')
					tmp[j][i - 1] = 'P';
			}
			i++;
		}
		j++;
	}
}

int	check_map_path1(t_axe *axe)
{
	int		i;
	char	**tmp;

	tmp = fill_tmp(axe);
	i = 0;
	while (i < 100)
	{
		check_map_path2(tmp, axe);
		if (check_tmp_collectibles(tmp, axe) == 0
			&& check_tmp_exit(tmp, axe) == 0)
			break ;
		i++;
	}
	if (check_tmp_exit(tmp, axe) == 0 && check_tmp_collectibles(tmp, axe) == 0)
	{
		free_tmp(tmp, axe);
		return (1);
	}
	free_tmp(tmp, axe);
	return (0);
}
