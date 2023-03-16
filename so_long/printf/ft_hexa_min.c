/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:46:34 by romartin          #+#    #+#             */
/*   Updated: 2022/12/05 15:20:11 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_min(unsigned int nb, int *error)
{
	char	c;
	int		count;

	count = 0;
	if (nb >= 16)
		count += ft_hexa_min(nb / 16, error);
	if (nb % 16 >= 10)
	{
		c = nb % 16 + 87;
	}
	else
		c = nb % 16 + '0';
	count = count + ft_putchar_fd(c, 1, error);
	return (count);
}
