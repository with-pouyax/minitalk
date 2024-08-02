/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:55:03 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/01 10:04:39 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	handle_ack(int sig)
{
	(void)sig;
	set_ack_received(1);
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error setting up signal handler: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void	send_bit(pid_t server_pid, unsigned char c, int bit_index)
{
	int	sig;

	if ((c & (1 << bit_index)) != 0)
		sig = SIGUSR2;
	else
		sig = SIGUSR1;
	if (kill(server_pid, sig) == -1)
	{
		write(STDERR_FILENO, "Error sending signal\n", 21);
		exit(EXIT_FAILURE);
	}
	while (!get_ack_received())
		usleep(SLEEP_DURATION);
	set_ack_received(0);
}

void	send_char(pid_t server_pid, unsigned char c)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 8)
	{
		send_bit(server_pid, c, bit_index);
		bit_index++;
	}
}

void	send_message(pid_t server_pid, const char *message)
{
	while (*message)
	{
		send_char(server_pid, *message);
		message++;
	}
	send_char(server_pid, '\0');
}
