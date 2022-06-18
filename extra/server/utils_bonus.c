/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:18:05 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/18 16:03:31 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk_bonus.h"

extern t_sigqueue	g_sigq;

void	print_char(pid_t *clientpid)
{
	char	c;

	c = get_byte();
	if (!c)
	{
		ft_printf("\n");
		*clientpid = 0;
		while (g_sigq.size)
			dequeue();
	}
	ft_printf("%c", c);
}

void	get_client(pid_t *clientpid, int *i)
{
	int	j;

	j = *i;
	while (j++ < 32)
		pause();
	j = 0;
	while (j < 4)
		*clientpid += (get_byte() << ((j++) * 8));
	ft_printf("\n\033[3;32mMessage From PID\033[3;33m %d\033[0m:\n", *clientpid);
	usleep(500);
	kill(*clientpid, SIGUSR1);
	*i = 0;
	while ((*i)++ < 8)
		pause();
}
