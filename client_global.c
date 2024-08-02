/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_global.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:18:00 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/01 08:51:28 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_ack_received = 0;

sig_atomic_t	get_ack_received(void)
{
	return (g_ack_received);
}

void	set_ack_received(sig_atomic_t ack)
{
	g_ack_received = ack;
}
