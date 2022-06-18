/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:54:56 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/18 15:24:32 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"

t_sigqueue	g_sigq;

void	enqueue(int sig)
{
	if (!g_sigq.size)
	{
		g_sigq.queue[0] = sig;
		g_sigq.front = 0;
		g_sigq.rear = 0;
		g_sigq.size = 1;
	}
	else if (g_sigq.size == QUEUE_SIZE)
		ft_putstr_fd("ERROR: ENQUEUING FULL QUEUE!\n", STDERR_FILENO);
	else
	{
		g_sigq.rear = (g_sigq.rear + 1) % QUEUE_SIZE;
		g_sigq.size++;
		g_sigq.queue[g_sigq.rear] = sig;
	}
}

int	dequeue(void)
{
	int	result;

	if (!g_sigq.size)
	{
		ft_putstr_fd("ERROR: DEQUEUEING EMPTY QUEUE!\n", STDERR_FILENO);
		return (-1);
	}
	else if (g_sigq.size == 1)
	{
		result = g_sigq.queue[g_sigq.front];
		g_sigq.front = -1;
		g_sigq.rear = -1;
		g_sigq.size--;
	}
	else
	{
		result = g_sigq.queue[g_sigq.front];
		g_sigq.front = (g_sigq.front + 1) % QUEUE_SIZE;
		g_sigq.size--;
	}
	return (result);
}

unsigned char	get_byte(void)
{
	unsigned char	result;
	int				i;

	result = 0;
	i = 0;
	while (i < 8)
		result += (dequeue() - SIGUSR1) << i++;
	return (result);
}

int	main(void)
{
	int		i;
	pid_t	clientpid;

	clientpid = 0;
	g_sigq.queue = ft_calloc(QUEUE_SIZE, sizeof(int));
	g_sigq.size = 0;
	g_sigq.front = -1;
	g_sigq.rear = -1;
	ft_printf("\n\033[34;1;4mServer PID\033[0m: %d\n", getpid());
	signal(SIGUSR1, &enqueue);
	signal(SIGUSR2, &enqueue);
	while (1)
	{
		i = -1;
		while (++i < 8)
			pause();
		while ((g_sigq.size && !(g_sigq.size % 8)) || g_sigq.size > 8)
		{
			if (!clientpid)
				get_client(&clientpid, &i);
			print_char(&clientpid);
		}
	}
	return (0);
}