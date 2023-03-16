/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:24:25 by romartin          #+#    #+#             */
/*   Updated: 2022/11/24 12:02:55 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	int				x;

	i = start;
	x = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) && ft_strlen(s) != 0)
		len = ft_strlen(s) - start;
	else if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	else if (ft_strlen(s) > start && len < start)
		len = len + 1 - 1;
	else if (len < start)
		len = start - len;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < (len + start) && s[i])
		str[x++] = s[i++];
	str[x] = 0;
	return (str);
}
