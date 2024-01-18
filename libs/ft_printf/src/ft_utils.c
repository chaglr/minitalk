/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:29:28 by muhnal            #+#    #+#             */
/*   Updated: 2023/01/03 11:36:38 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//function some of used inside others
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	i = 0;
	if (n >= 0 && n <= 9)
		i += ft_putchar(n + '0');
	else if (n < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(n * -1);
	}
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}
