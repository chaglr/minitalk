/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:25:42 by muhnal            #+#    #+#             */
/*   Updated: 2023/01/03 18:39:01 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatspec(char c, va_list arg)
{
	int	p;

	p = 0;
	if (c == 's')
		p += ft_putstr(va_arg(arg, char *));
	else if (c == 'c')
		p += ft_putchar(va_arg(arg, int));
	else if (c == 'd' || c == 'i')
		p += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		p += ft_udec(va_arg(arg, unsigned int));
	else if (c == 'p')
		p += (ft_putstr("0x") + ft_pointer(va_arg(arg, unsigned long)));
	else if (c == 'x')
		p += ft_hex(va_arg(arg, unsigned int), 'x');
	else if (c == 'X')
		p += ft_hex(va_arg(arg, unsigned int), 'X');
	else if (c == '%')
		p += ft_putchar('%');
	else
		return (ft_putchar(c));
	return (p);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		j;

	va_start(arg, s);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			j++;
		}
		if (s[i] == '%')
		{
			i++;
			while (s[i] == ' ' && s[i])
				i++;
			j += ft_formatspec(s[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (j);
}
