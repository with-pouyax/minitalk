/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:53:47 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/05 15:46:26 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include "ft_printf/ft_printf.h"

# define SLEEP_DURATION 100

void			handle_ack(int sig);
void			setup_signal_handlers(void);
void			send_bit(pid_t server_pid, unsigned char c, int bit_index);
void			send_char(pid_t server_pid, unsigned char c);
void			send_message(pid_t server_pid, const char *message);

sig_atomic_t	get_ack_received(void);
void			set_ack_received(sig_atomic_t ack);
int				ft_atoi(const char *nptr);

#endif
