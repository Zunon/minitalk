/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:55:02 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/18 16:03:41 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk_bonus.h"

void	confirm(int sig)
{
	(void)sig;
	ft_printf("\n\033[3;32mSENDING!\033[0m\n");
}

void	send_byte(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c >>= 1;
		i++;
		usleep(250);
	}
}

int	main(int argc, char **argv)
{
	pid_t	serverpid;
	pid_t	clientpid;
	int		i;

	if (argc == 3)
	{
		signal(SIGUSR1, &confirm);
		serverpid = ft_atoi(argv[1]);
		i = 0;
		clientpid = getpid();
		ft_printf("\n\033[34;1;4mClient PID:\033[0m %d\n", clientpid);
		while (i < 4)
			send_byte(serverpid, ((unsigned char *)(&clientpid))[i++]);
		i = 0;
		pause();
		while ((argv[2])[i])
			send_byte(serverpid, (argv[2])[i++]);
		send_byte(serverpid, 0);
	}
	else
		ft_putendl_fd("ERROR: INCORRECT NUMBER OF ARGUMENTS", STDERR_FILENO);
	return (0);
}
