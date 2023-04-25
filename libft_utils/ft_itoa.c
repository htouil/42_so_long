/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:44:57 by htouil            #+#    #+#             */
/*   Updated: 2023/04/24 21:44:58 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *s1)
{
	char	*d;
	int		i;

	i = 0;
	d = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!d)
		return (0);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			j;
	long int	x;

	x = n;
	j = count(x);
	if (x == 0)
		return (ft_strdup("0"));
	nbr = malloc((j + 1) * sizeof(char));
	if (!nbr)
		return (0);
	if (x < 0)
	{
		nbr[0] = '-';
		x *= -1;
	}
	nbr[j] = '\0';
	while (j-- > 0 && x != 0)
	{
		nbr[j] = (x % 10) + '0';
		x /= 10;
	}
	return (nbr);
}
