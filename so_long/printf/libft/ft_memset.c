/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:35:52 by romartin          #+#    #+#             */
/*   Updated: 2022/11/25 09:25:12 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t destsize)
{
	char	*t;

	t = b;
	while (destsize > 0)
	{
		*t = (unsigned char)c;
		t++;
		destsize--;
	}
	return (b);
}
