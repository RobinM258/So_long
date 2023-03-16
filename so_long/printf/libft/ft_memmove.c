/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:33:15 by romartin          #+#    #+#             */
/*   Updated: 2022/11/23 14:55:51 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*s;
	char			*d;

	if (!src && !dst)
		return (0);
	i = 0;
	s = (char *)src;
	d = (char *)dst;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{	
			d[i] = s[i];
			i++;
		}
	}
	return ((char *)dst);
}
