/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:15:46 by muhnal            #+#    #+#             */
/*   Updated: 2023/04/20 14:18:25 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"
# include "libft.h"

/*
** client.c
*/

void	send_signals(int pid, char c);
void	send_char(int pid, char *str);
char	check_arguments(int argc, char *argv[]);

/*
** server.c
*/

void	read_write_signal(int sig);
void	sigusr1_handler(int sig);
void	sigusr2_handler(int sig);
void	kill_handler(int sig);

#endif
