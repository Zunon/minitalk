/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:33:22 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/06 14:25:36 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *str, char sep)
{
	int	n;

	n = 0;
	while (str[n] && str[n] != sep)
		n++;
	return (n);
}

static int	count_words(char const *str, char sep)
{
	if (!*str)
		return (0);
	while (*str && *str == sep)
		str++;
	if (!*str)
		return (0);
	while (*str && *str != sep)
		str++;
	if (!*str)
		return (1);
	else
		return (1 + count_words(str, sep));
}

static char	**returner(char const *str)
{
	char	**result;

	if (!str)
	{
		result = malloc(sizeof(char *));
		if (!result)
			return (0);
		result[0] = 0;
		return (result);
	}
	else
	{
		result = malloc(sizeof(char *) * 2);
		if (!result)
			return (0);
		result[0] = ft_strdup(str);
		result[1] = 0;
		return (result);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s || !*s)
		return (returner(0));
	if (!c)
		return (returner(s));
	words = count_words(s, c);
	i = 0;
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		result[i++] = ft_substr(s, 0, word_len(s, c));
		s += word_len(s, c);
	}
	result[i] = 0;
	return (result);
}
