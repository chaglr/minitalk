/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:13:54 by muhnal            #+#    #+#             */
/*   Updated: 2023/04/19 11:59:35 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	read_write_signal(int sig)
{
	static char	ch = 0;
	static int	bit_count = 0;

	ch |= (sig & 1) << bit_count;
	if (bit_count < 7)
	{
		bit_count++;
	}
	else
	{
		write(1, &ch, 1);
		ch = 0;
		bit_count = 0;
	}
}

void	sigusr1_handler(int sig)
{
	(void)sig;
	read_write_signal(0);
}

void	sigusr2_handler(int sig)
{
	(void)sig;
	read_write_signal(1);
}

void	kill_handler(int sig)
{
	(void)sig;
	ft_printf("\nProcess was killed by you. \nServer stopped!\n");
	exit(0);
}

int	main(void)
{
	ft_printf("Server was started..\nThe Server's PID is: %d \n", getpid());
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);
	signal(SIGINT, kill_handler);
	while (1)
		pause();
	return (0);
}
