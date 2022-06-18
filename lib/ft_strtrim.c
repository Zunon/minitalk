/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:02:59 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/05 07:59:17 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_i;
	size_t	end_i;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	start_i = 0;
	end_i = ft_strlen(s1) - 1;
	while (ft_strchr(set, (int)s1[start_i]))
		start_i++;
	while (ft_strchr(set, (int)s1[end_i]))
		end_i--;
	return (ft_substr(s1, start_i, end_i - start_i + 1));
}
