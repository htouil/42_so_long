/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:03:19 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:03:20 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_extension(char *filename)
{
	int	i;

	i = ft_strlen(filename) - 1;
	if (filename[i] == 'r' && filename[i - 1] == 'e' && filename[i - 2] == 'b'
		&& filename[i - 3] == '.')
		return (1);
	return (0);
}