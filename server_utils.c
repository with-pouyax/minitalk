/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:19:26 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/05 15:52:03 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_bit(int sig, int *bit_index, unsigned char *current_char)
{
	if (sig == SIGUSR1)
		*current_char &= ~(1 << *bit_index);
	else if (sig == SIGUSR2)
		*current_char |= (1 << *bit_index);
	(*bit_index)++;
}

void	resize_buffer(int *char_index, int *buffer_size)
{
	struct s_server_data	*server_data;
	char					*new_message;

	server_data = get_server_data();
	*buffer_size *= 2;
	new_message = malloc(*buffer_size);
	if (!new_message)
	{
		free(server_data->message);
		write(STDERR_FILENO, "Memory allocation error\n", 24);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(new_message, server_data->message, *char_index);
	free(server_data->message);
	server_data->message = new_message;
}

void	process_complete_char(int *char_index, unsigned char *current_char, \
	int *bit_index, int *buffer_size)
{
	struct s_server_data	*server_data;

	server_data = get_server_data();
	server_data->message[(*char_index)++] = *current_char;
	if (*char_index >= *buffer_size)
		resize_buffer(char_index, buffer_size);
	if (*current_char == '\0')
	{
		ft_printf("%s\n", server_data->message);
		*char_index = 0;
	}
	*current_char = 0;
	*bit_index = 0;
}

void	init_signal_handling(int *bit_index, int *char_index, int *buffer_size, \
unsigned char *current_char)
{
	*bit_index = 0;
	*char_index = 0;
	*buffer_size = INITIAL_BUFFER_SIZE;
	*current_char = 0;
}

void	handle_signal(int sig, siginfo_t *siginfo, void *context)
{
	struct s_server_data	*server_data;
	static int				bit_index = 0;
	static int				char_index = 0;
	static int				buffer_size = INITIAL_BUFFER_SIZE;
	static unsigned char	current_char = 0;

	(void)context;
	server_data = get_server_data();
	if (bit_index == 0 && char_index == 0)
		init_signal_handling(&bit_index, &char_index, \
	&buffer_size, &current_char);
	server_data->client_pid = siginfo->si_pid;
	handle_bit(sig, &bit_index, &current_char);
	if (bit_index == 8)
		process_complete_char(&char_index, &current_char, &bit_index, \
		&buffer_size);
	if (kill(server_data->client_pid, SIGUSR1) == -1)
	{
		free(server_data->message);
		write(STDERR_FILENO, "Acknowledgment error\n", 21);
		exit(EXIT_FAILURE);
	}
}
