/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:01:32 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 20:01:33 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*ss;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		ss = malloc(sizeof(char));
		if (!ss)
			return (0);
		ss[i] = '\0';
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		ss = malloc((len + 1) * sizeof(char));
		if (!ss)
			return (0);
		while (i++ < len)
			*(ss + i - 1) = *(s + start + i - 1);
		*(ss + i - 1) = '\0';
	}
	return (ss);
}

int	count_it(char *str, char occ)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != occ && (str[i + 1] == occ || str[i + 1] == '\0'))
				counter++;
		i++;
	}
	return (counter);
}

void	free_it(char **str, int d)
{
	while (d)
	{
		free(str[d]);
		d--;
	}
	free(str);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		pos;

	if (!s)
		return (NULL);
	arr = (char **)malloc((count_it((char *)s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	pos = -1;
	while (++pos < count_it((char *)s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		arr[pos] = ft_substr(s, j, i - j);
		if (!arr[pos])
			return (free_it(arr, pos), NULL);
	}
	return (arr[pos] = NULL, arr);
}
