/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:28:14 by romartin          #+#    #+#             */
/*   Updated: 2022/11/23 13:13:36 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	int		i;
	int		j;
	char	*red;

	j = -1;
	i = -1;
	if (!s1 || !s2)
		return (0);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	red = malloc(sizeof(char) * (i1 + i2 + 1));
	if (!red)
		return (NULL);
	while (s1[++i])
		red[i] = s1[i];
	while (s2[++j])
	{
		red[i] = s2[j];
		i++;
	}
	red[i] = '\0';
	return (red);
}
