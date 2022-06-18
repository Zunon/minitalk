/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:34:56 by kalmheir          #+#    #+#             */
/*   Updated: 2022/05/31 09:19:25 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_longhex(unsigned long num, size_t *count)
{
	char	digit;

	if (num >= 16)
	{
		put_longhex(num / 16, count);
		num = num % 16;
	}
	digit = "0123456789abcdef"[num];
	put_charc(digit, count);
}

void	switcher(char c, va_list *list, size_t *count)
{
	if (c == 'c')
		put_charc(va_arg(*list, int), count);
	else if (c == 's')
		putstrip(va_arg(*list, char *), 0, count);
	else if (c == 'p')
		put_pointerc(va_arg(*list, void *), count);
	else if (c == 'd' || c == 'i')
		put_nbrc(va_arg(*list, int), count);
	else if (c == 'u')
		put_unbrc(va_arg(*list, unsigned int), count);
	else if (c == 'x' || c == 'X')
		put_hex(va_arg(*list, unsigned int),
			(unsigned char)((c - 'X') / 32), count);
	else if (c == '%')
		put_charc('%', count);
}

void	iterator(const char *str, va_list *list, size_t *count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			put_charc(str[i], count);
		else
		{
			i++;
			if (str[i] == 0)
				break ;
			switcher(str[i], list, count);
		}
		i++;
	}
}
