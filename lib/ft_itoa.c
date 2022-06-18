/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:34:32 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/06 13:30:53 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_pow(nb, power - 1));
}

static char	fast_log10(int n)
{
	if (n == (int)0x80000000)
		return (10);
	if (n < 0)
		n = -n;
	if (n <= 9)
		return (1);
	if (n <= 99)
		return (2);
	if (n <= 999)
		return (3);
	if (n <= 9999)
		return (4);
	if (n <= 99999)
		return (5);
	if (n <= 999999)
		return (6);
	if (n <= 9999999)
		return (7);
	if (n <= 99999999)
		return (8);
	if (n <= 999999999)
		return (9);
	return (10);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		digits;
	int		neg;
	int		i;

	i = 0;
	digits = fast_log10(n);
	neg = n < 0;
	result = malloc(neg + digits + 1);
	if (!result)
		return (0);
	if (neg)
		result[i++] = '-';
	result[digits + neg] = 0;
	if (neg)
		neg = -1;
	else
		neg = 1;
	while (digits)
		result[i++] = (neg * ((n / ft_pow(10, --digits)) % 10)) + '0';
	return (result);
}
