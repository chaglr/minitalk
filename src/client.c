/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:14:11 by muhnal            #+#    #+#             */
/*   Updated: 2023/04/19 12:01:16 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** a. argument count must equal 3(./client, pid, msg)
** b. 2. arg (pid) must be digit
** c. 2.arg (pid) can't be full zero
*/

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
	send_signals(pid, '\n');
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

	error_code = check_arguments(argc, argv);
	if (error_code == 0)
	{
		send_char(ft_atoi(argv[1]), argv[2]);
	}
	else if (error_code == 'c')
	{
		ft_printf("./client needs 2 argument:\n1.server PID(digit)\n");
		ft_printf("2.string start and end with double quote(\"string\")\n");
		return (1);
	}
	else if (error_code == 'd')
	{
		ft_printf("The server PID should consist of numbers.\n");
		return (1);
	}
	else if (error_code == 'z')
	{
		ft_printf("PID cannot be entirely zero.\n");
		return (1);
	}
	return (0);
}
