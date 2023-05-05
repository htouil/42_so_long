/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:48:37 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 19:48:39 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*joined;

	if (!str1)
	{
		str1 = malloc(1 * sizeof(char));
		if (!str1)
			exit (1);
		str1[0] = '\0';
	}
	joined = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = -1;
	j = 0;
	while (str1[++i])
		joined[i] = str1[i];
	while (str2[j])
		joined[i++] = str2[j++];
	joined[i] = '\0';
	free (str1);
	return (joined);
}

int	ft_strchr_nl(char *searched)
{
	int	i;

	if (!searched)
		return (0);
	i = 0;
	while (searched[i] != '\0')
	{
		if (searched[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
