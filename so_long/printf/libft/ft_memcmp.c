/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:02:34 by romartin          #+#    #+#             */
/*   Updated: 2022/11/22 10:30:05 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*c_s1;
	const unsigned char		*c_s2;

	c_s1 = (const unsigned char *)s1;
	c_s2 = (const unsigned char *)s2;
	if (n == 0 && s1 == s2)
		return (0);
	while (n > 0)
	{
		if (*c_s1 != *c_s2)
			return (*c_s1 - *c_s2);
		if (n)
		{
			c_s1++;
			c_s2++;
		}
		n--;
	}
	return (0);
}
