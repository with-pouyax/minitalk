/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:13:53 by pghajard          #+#    #+#             */
/*   Updated: 2024/07/31 17:06:49 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include "ft_printf/ft_printf.h"

# define INITIAL_BUFFER_SIZE 1024

struct	s_server_data
{
	char	*message;
	pid_t	client_pid;
};

struct s_server_data	*get_server_data(void);
void					set_server_data(struct s_server_data *data);
void					handle_bit(int sig, int *bit_index, \
unsigned char *current_char);
void					resize_buffer(int *char_index, int *buffer_size);
void					process_complete_char(int *char_index, \
unsigned char *current_char, int *bit_index, int *buffer_size);
void					handle_signal(int sig, \
siginfo_t *siginfo, void *context);
void					init_server_data(void);
void					setup_signal_handlers(void);

#endif // SERVER_H