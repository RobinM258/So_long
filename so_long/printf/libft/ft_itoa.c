/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:36:17 by romartin          #+#    #+#             */
/*   Updated: 2022/11/25 08:57:31 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long c)
{
	int	i;

	i = 1;
	if (c < 0)
	{
		c = c * -1;
		i++;
	}
	while (c >= 10)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa2(char *ret, int i, int j, long c)
{
	if (c < 0)
	{
		j = 1;
		c = c * -1;
	}
	i--;
	while (c >= 10)
	{
		ret[i--] = 48 + (c % 10);
		c = c / 10;
	}
	ret[i] = 48 + c;
	if (j == 1)
		ret[--i] = 45;
	return (ret);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	long	c;
	char	*ret;

	j = 0;
	c = (long)n;
	i = ft_len(c);
	ret = malloc(sizeof(char) * (ft_len(c) + 1));
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	ret = ft_itoa2(ret, i, j, c);
	return (ret);
}
