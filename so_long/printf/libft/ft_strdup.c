/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:53:11 by romartin          #+#    #+#             */
/*   Updated: 2022/11/21 12:16:06 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*red;
	int		i;

	i = 0;
	red = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!red)
		return (NULL);
	while (s1[i])
	{
		red[i] = s1[i];
		i++;
	}
	red[i] = '\0';
	return (red);
}
