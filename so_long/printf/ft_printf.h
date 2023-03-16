/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:25:05 by romartin          #+#    #+#             */
/*   Updated: 2022/12/06 09:27:32 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_unsigned_putnbr(unsigned int nb, int *error);
int		ft_hexa_min(unsigned int n, int *error);
int		ft_hexa_max(unsigned int n, int *error);
int		ft_pointer(unsigned long long n, int *error, int i);

#endif