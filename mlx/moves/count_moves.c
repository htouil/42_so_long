/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:51:53 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:51:54 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	display_moves(t_axe *axe)
{
	int		i;
	char	*mvs;

	axe->mv_count++;
	mvs = ft_itoa(axe->mv_count);
	i = 0;
	write (1, "Successful moves: ", 18);
	while (mvs[i])
	{
		write(1, &mvs[i], 1);
		i++;
	}
	write (1, "\n", 1);
	free(mvs);
}
