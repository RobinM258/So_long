/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:46:34 by romartin          #+#    #+#             */
/*   Updated: 2022/12/06 09:29:21 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long long n, int *error, int i)
{
	int					count;
	char				*str;

	count = 0;
	if (i == 0)
		count += ft_putstr_fd("0x", 1, error);
	str = "0123456789abcdef";
	if (n >= 16)
	{
		i++;
		count += ft_pointer(n / 16, error, i);
		count += ft_pointer(n % 16, error, i);
	}
	else
		count += ft_putchar_fd(str[n], 1, error);
	return (count);
}
