/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:40:30 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/12 09:35:06 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atopid_t(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf ("Invalid server PID\n");
		return (EXIT_FAILURE);
	}
	setup_signal_handlers();
	send_message(server_pid, argv[2]);
	return (EXIT_SUCCESS);
}
