/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:13:44 by romartin          #+#    #+#             */
/*   Updated: 2022/11/23 14:54:10 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

static int	ft_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_free(char **strs, int j)
{
	while (j >= 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
	return (NULL);
}

static char	**ft_split2(char const *s, char c, int word, char **strs)
{
	int	j;
	int	size;
	int	i;

	j = 0;
	i = 0;
	(strs = (char **)malloc((word + 1) * sizeof(char *)));
	if (!strs)
		return (NULL);
	while (j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size(s + i, c);
		strs[j] = ft_substr(s, i, size);
		if (!(strs[j]))
			return (ft_free(strs, j));
		i += size;
		j++;
	}
	strs[j] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**strs;

	strs = NULL;
	if (!s)
		return (NULL);
	word = ft_count(s, c);
	strs = ft_split2(s, c, word, strs);
	return (strs);
}
