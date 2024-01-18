/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:26:41 by muhnal            #+#    #+#             */
/*   Updated: 2023/01/03 17:37:42 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ft_pointer
//ft_unsigned_dec
//ft_hex
#include "ft_printf.h"

int	ft_udec(unsigned int u)
{
	int	i;

	i = 0;
	if (u <= 9)
		i += ft_putchar(u + '0');
	else
	{
		i += ft_udec(u / 10);
		i += ft_udec(u % 10);
	}
	return (i);
}

int	ft_pointer(unsigned long p)
{
	int	i;

	i = 0;
	if (p >= 16)
		i += ft_pointer(p / 16);
	if ((p % 16) < 10)
		i += ft_putchar((p % 16) + '0');
	else
		i += ft_putchar((p % 16) - 10 + 'a');
	return (i);
}

int	ft_hex(unsigned int x, char b)
{
	int	i;

	i = 0;
	if (x >= 16)
		i += ft_hex(x / 16, b);
	if ((x % 16) < 10)
		i += ft_putchar((x % 16) + '0');
	else
	{
		if (b == 'x')
			i += ft_putchar((x % 16) - 10 + 'a');
		else
			i += ft_putchar((x % 16) - 10 + 'A');
	}
	return (i);
}
