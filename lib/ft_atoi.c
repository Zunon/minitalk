/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:32:38 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/05 07:53:13 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	sign;
	size_t	i;
	int		result;
	int		dtc;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 0x09 && str[i] <= 0x0d) || str[i] == 0x20)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit((int)(str[i])))
	{
		dtc = result;
		result *= 10;
		result += (1 * sign) * (str[i] - '0');
		if ((dtc ^ result) & 0x80000000 && dtc != 0)
			return ((dtc < 0) - 1);
		i++;
	}
	return (result);
}
