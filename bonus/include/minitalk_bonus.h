/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:15:46 by muhnal            #+#    #+#             */
/*   Updated: 2023/04/20 14:28:44 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "../include/ft_printf.h"
# include "../include/libft.h"

typedef struct s_msg
{
	char	ch;
	int		bit_count;
	int		client_pid;
}	t_msg;

void	receive_confirmation(int sig);
char	check_arguments(int argc, char *argv[]);
void	send_char(int pid, char *str);
void	send_signals(int pid, char c);
void	handle_error_code(char error_code);
void	read_write_signal_bonus(int sig, int client_pid);
void	sigusr1_handler_bonus(int sig, siginfo_t *info, void *context);
void	sigusr2_handler_bonus(int sig, siginfo_t *info, void *context);
void	kill_handler(int sig);

#endif
