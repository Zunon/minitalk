/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:32:16 by kalmheir          #+#    #+#             */
/*   Updated: 2022/05/31 09:19:21 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Function:  ft_printf
 * --------------------
 * prints a formatted string to stdout that mimics the
 * original printf() from libc
 *
 * parameters:
 *  str: input string, with formatting macros
 *  ...: variadic variables to be inserted into string
 *
 * returns: total number of printed characters
 *
 *
 * Requirements:
 * -------------
 * Doesn't implement the buffer management of printf()
 *
 * Handles the following conversions:
 *  %c: Character
 *  %s: String
 *  %p: Pointer (void * -> hex integer)
 *  %d and %i: Signed Integer
 *  %u: Unsigned Integer
 *  %x: Lowercase Hexadecimal Integer
 *  %X: Uppercase Hexadecimal Integer
 *  %%: Escaped % symbol
 */
int	ft_printf(const char *str, ...)
{
	size_t	chars;
	va_list	args;

	chars = 0;
	va_start(args, str);
	iterator(str, &args, &chars);
	va_end(args);
	return (chars);
}

void	put_charc(char c, size_t *count)
{
	(*count)++;
	write(STDOUT_FILENO, &c, 1);
}
