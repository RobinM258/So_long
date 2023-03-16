/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:50:17 by romartin          #+#    #+#             */
/*   Updated: 2022/11/24 16:53:44 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fromstart(char const *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (set[j] == str[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	ft_fromend(char const *str, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 0;
	while (set[j] && i >= 0)
	{
		if (set[j] == str[i])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (0);
	start = ft_fromstart(s1, set);
	end = ft_fromend(s1, set);
	if (start > end)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		str[0] = '\0';
	}
	else
		str = ft_substr(s1, start, end - start);
	return (str);
}
