/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:53:56 by romartin          #+#    #+#             */
/*   Updated: 2022/11/23 14:58:40 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src1;

	if ((!src && !dst) && n > 0)
		return (0);
	src1 = (char *)dst;
	i = 0;
	while (n > i)
	{
		*(char *)src1 = *(char *)src;
		i++;
		src1++;
		src++;
	}
	return ((char *)dst);
}
