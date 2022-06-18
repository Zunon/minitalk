/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 09:53:28 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/18 13:00:56 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "../lib/libft.h"
# include <signal.h>
# define QUEUE_SIZE 1024

typedef struct s_queue
{
	size_t	size;
	int		front;
	int		rear;
	int		*queue;
}				t_sigqueue;
#endif
