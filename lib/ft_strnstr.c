/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:07:17 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/06 19:50:59 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset(size_t *m, size_t *n, long long int *startpos)
{
	*m = 0;
	*n = (size_t)(*startpos);
	*startpos = -1;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i[2];
	long long int	startpos;

	if (haystack == needle || !*needle)
		return ((char *)haystack);
	else if (!*haystack)
		return (0);
	i[0] = 0;
	i[1] = 0;
	startpos = -1;
	while ((i[0] < len) && needle[i[1]] && haystack[i[0]])
	{
		if (haystack[i[0]] == needle[i[1]])
		{
			i[1]++;
			if (startpos == -1)
				startpos = i[0];
		}
		else if (i[1])
			reset(&i[1], &i[0], &startpos);
		i[0]++;
	}
	if (!needle[i[1]])
		return ((char *)(haystack + i[0] - ft_strlen(needle)));
	return (0);
}
