/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:39:10 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/05 07:54:35 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*newstr;

	i = 0;
	len = ft_strlen(s1);
	newstr = malloc(len + 1);
	if (!newstr)
		return (0);
	while (i < (len + 1))
	{
		newstr[i] = s1[i];
		i++;
	}
	return (newstr);
}
