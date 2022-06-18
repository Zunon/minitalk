/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:33:34 by kalmheir          #+#    #+#             */
/*   Updated: 2022/05/31 09:20:19 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  putstrip
 * --------------------
 * Prints a string to stdout with the option to ignore
 * percentage signs
 *
 * parameters:
 *  str: string to be printed
 *  ignore_percent: boolean value whether or not to ignore %
 */
void	putstrip(const char *str, char ignore_percent, size_t *count)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		putstrip("(null)", 0, count);
		return ;
	}
	while (str[i])
	{
		if (str[i] == '%' && ignore_percent)
		{
			i++;
			continue ;
		}
		put_charc(str[i], count);
		i++;
	}
}

void	put_pointerc(void *pointer, size_t *count)
{
	(*count) += 2;
	write(STDOUT_FILENO, "0x", 2);
	put_longhex((unsigned long)pointer, count);
}

void	put_nbrc(int num, size_t *count)
{
	char	digit;

	if (num == -2147483648)
	{
		putstrip("-2147483648", 1, count);
		return ;
	}
	else if (num < 0)
	{
		put_charc('-', count);
		num = -num;
	}
	if (num >= 10)
	{
		put_nbrc(num / 10, count);
		num = num % 10;
	}
	digit = num + '0';
	put_charc(digit, count);
}

void	put_unbrc(unsigned int num, size_t *count)
{
	char	digit;

	if (num >= 10)
	{
		put_unbrc(num / 10, count);
		num = num % 10;
	}
	digit = num + '0';
	put_charc(digit, count);
}

void	put_hex(unsigned int num, unsigned char isLower, size_t *count)
{
	char	digit;

	if (num >= 16)
	{
		put_hex(num / 16, isLower, count);
		num = num % 16;
	}
	if (isLower)
		digit = "0123456789abcdef"[num];
	else
		digit = "0123456789ABCDEF"[num];
	put_charc(digit, count);
}
