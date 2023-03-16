/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:21:04 by romartin          #+#    #+#             */
/*   Updated: 2022/12/05 15:30:50 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd, int *error)
{
	int		i;
	char	*str;
	char	c;

	str = "(null)";
	i = 0;
	if (s == NULL)
	{
		while (str[i])
		{
			c = str[i];
			ft_putchar_fd(c, fd, error);
			i++;
		}
		return (i);
	}
	while (s[i])
	{
		c = s[i];
		ft_putchar_fd(c, fd, error);
		i++;
	}		
	return (i);
}
