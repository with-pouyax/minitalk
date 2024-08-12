/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atopid_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pghajard <pghajard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:02:11 by pghajard          #+#    #+#             */
/*   Updated: 2024/08/12 09:50:06 by pghajard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

pid_t	ft_atopid_t(const char *nptr)
{
	int		i;
	int		sign;
	pid_t	r;

	i = 0;
	sign = 1;
	r = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = (r * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0')
		return (-1);
	return (r * (pid_t)sign);
}
