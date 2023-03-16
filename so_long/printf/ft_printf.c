/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:06:40 by romartin          #+#    #+#             */
/*   Updated: 2022/12/06 09:47:05 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_arg(va_list ap, char c, int *error)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = i + ft_putchar_fd(va_arg(ap, int), 1, error);
	else if (c == 'd' || c == 'i')
		i = i + ft_putnbr_fd(va_arg(ap, int), 1, error);
	else if (c == 's')
		i = i + ft_putstr_fd(va_arg(ap, char *), 1, error);
	else if (c == 'u')
		i = i + ft_unsigned_putnbr(va_arg(ap, int), error);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1, error);
		i++;
	}
	else if (c == 'x')
		i = i + ft_hexa_min(va_arg(ap, int), error);
	else if (c == 'X')
		i = i + ft_hexa_max(va_arg(ap, int), error);
	else if (c == 'p')
		i = i + ft_pointer(va_arg(ap, unsigned long long), error, i);
	else
		return (-1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		error;

	i = -1;
	count = 0;
	error = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
			count += ft_get_arg(ap, str[i++ + 1], &error);
		else
		{
			ft_putchar_fd(str[i], 1, &error);
			count++;
		}
	}
	va_end(ap);
	if (error < 0)
		return (-1);
	return (count);
}
