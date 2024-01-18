/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:52:26 by muhnal            #+#    #+#             */
/*   Updated: 2023/04/20 14:15:19 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_error_code(char error_code)
{
	if (error_code == 'c')
	{
		ft_printf("./client needs 2 argument:\n1.server PID(digit)\n");
		ft_printf("2.string start and end with double quote(\"string\")\n");
	}
	else if (error_code == 'd')
	{
		ft_printf("The server PID should consist of numbers.\n");
	}
	else if (error_code == 'z')
	{
		ft_printf("PID cannot be entirely zero.\n");
	}
}
