/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:40:58 by romartin          #+#    #+#             */
/*   Updated: 2022/12/05 11:31:34 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int nb, int fd, int *error)
{
	char	c;
	long	nbr;
	int		count;

	count = 0;
	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1, error);
		nbr = (long)nbr * -1;
		count++;
	}
	if (nbr > 9)
		count += ft_putnbr_fd(nbr / 10, 1, error);
	c = nbr % 10 + '0';
	count = count + ft_putchar_fd(c, fd, error);
	return (count);
}
