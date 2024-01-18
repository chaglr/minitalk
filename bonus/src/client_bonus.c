/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:47:09 by muhnal            #+#    #+#             */
/*   Updated: 2023/04/20 10:53:37 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	receive_confirmation(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Client: Message acknowledged by server.\n");
	}
}

char	check_arguments(int argc, char *argv[])
{
	char	zero_count;
	int		i;

	i = 0;
	zero_count = 0;
	if (argc != 3)
		return ('c');
	while (i < (int)ft_strlen(argv[1]))
	{
		if (!ft_isdigit(argv[1][i]))
			return ('d');
		else if (argv[1][i] == '0')
			zero_count++;
		i++;
	}
	if (zero_count == i)
		return ('z');
	return (0);
}

void	send_char(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		send_signals(pid, str[i]);
		i++;
	}
	send_signals(pid, '\0');
}

void	send_signals(int pid, char c)
{
	int	i;
	int	signal;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			signal = SIGUSR2;
		else
			signal = SIGUSR1;
		if (kill(pid, signal) == -1)
		{
			ft_putstr_fd("client: Wrong PID Number\n", STDERR_FILENO);
			exit(1);
		}
		c >>= 1;
		usleep(100);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	error_code;

	signal(SIGUSR1, receive_confirmation);
	error_code = check_arguments(argc, argv);
	if (error_code == 0)
	{
		send_char(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		handle_error_code(error_code);
		return (1);
	}
	return (0);
}
