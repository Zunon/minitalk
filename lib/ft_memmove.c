/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 23:38:30 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/05 07:54:20 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	else if (dst == src)
		return (dst);
	else if (src < dst)
	{
		i = len;
		while (--i != __UINT64_MAX__)
			((char *)dst)[i] = ((char *)src)[i];
	}
	else
	{
		i = -1;
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
