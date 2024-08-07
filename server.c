/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:18:43 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/05 16:45:50 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_server_data(void)
{
	struct s_server_data	*server_data;

	server_data = malloc(sizeof(struct s_server_data));
	if (!server_data)
	{
		write(STDERR_FILENO, "Memory allocation error\n", 24);
		exit(EXIT_FAILURE);
	}
	server_data->message = malloc(INITIAL_BUFFER_SIZE);
	if (!server_data->message)
	{
		write(STDERR_FILENO, "Memory allocation error\n", 24);
		free(server_data);
		exit(EXIT_FAILURE);
	}
	set_server_data(server_data);
}

void	setup_signal_handlers(void)
{
	struct sigaction		sa;
	struct s_server_data	*server_data;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
	sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		server_data = get_server_data();
		if (server_data)
		{
			free(server_data->message);
			free(server_data);
		}
		write(STDERR_FILENO, "Sigaction error\n", 16);
		exit(EXIT_FAILURE);
	}
}

void	signal_handler(int sig)
{
	struct s_server_data	*server_data;

	(void)sig;
	server_data = get_server_data();
	free(server_data->message);
	free(server_data);
	exit(0);
}

int	main(void)
{
	signal(SIGINT, signal_handler);
	init_server_data();
	setup_signal_handlers();
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
