/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:29:27 by romartin          #+#    #+#             */
/*   Updated: 2022/12/05 11:51:43 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int nb, int *error)
{
	char	c;
	long	nbr;
	int		i;

	i = 0;
	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1, error);
		nbr = (long)nbr * -1;
		i++;
	}
	if (nbr > 9)
		i += ft_unsigned_putnbr(nbr / 10, error);
		i++;
	c = nbr % 10 + '0';
	ft_putchar_fd(c, 1, error);
	return (i);
}
