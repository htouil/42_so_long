/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:12:32 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:12:34 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strncmp(char *s1, char *s2)
{
	int			i;

	i = 0;
	while (s1 && s2)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int	check_double_nl(char *lgmap)
{
	int	i;

	i = 0;
	while (lgmap[i])
	{
		if (lgmap[i] == '\n' && lgmap[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_map_frame1(t_axe *axe)
{
	int	i;

	i = 0;
	while (i < axe->rows)
	{
		if (ft_strlen(axe->matrix[i]) != axe->columns)
			return (0);
		i++;
	}
	return (1);
}

int	check_map_frame2(t_axe *axe)
{
	int	i;

	i = 0;
	while (i < axe->columns)
	{
		if (axe->matrix[0][i] != '1' || axe->matrix[axe->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < axe->rows)
	{
		if (axe->matrix[i][0] != '1' || axe->matrix[i][axe->columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
