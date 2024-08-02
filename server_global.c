/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_global.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:34:35 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/01 08:53:33 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

struct s_server_data	*g_server_data = NULL;

struct s_server_data	*get_server_data(void)
{
	return (g_server_data);
}

void	set_server_data(struct s_server_data *data)
{
	g_server_data = data;
}
