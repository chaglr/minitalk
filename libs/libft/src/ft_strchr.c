/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:06:20 by muhnal            #+#    #+#             */
/*   Updated: 2022/11/16 08:52:30 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *) s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main () {
   const char str[] = "This is just a String";
   const char ch = 'u';
   char *p;
   p = ft_strchr(str, ch);
   printf("String starting from %c is: %s", ch, p);
   return 0;
}
*/
