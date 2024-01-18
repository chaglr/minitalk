/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:20:33 by muhnal            #+#    #+#             */
/*   Updated: 2023/01/03 16:25:20 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//write
# include <unistd.h>

//variable func
# include <stdarg.h>
//ft_printf.c
int	ft_printf(const char *s, ...);
//ft_utils.c
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
//ft_libft.c
int	ft_udec(unsigned int u);
int	ft_pointer(unsigned long p);
int	ft_hex(unsigned int x, char b);
#endif
