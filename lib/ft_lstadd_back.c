/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:25:44 by kalmheir          #+#    #+#             */
/*   Updated: 2022/05/31 09:13:51 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newList)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = newList;
		newList->next = 0;
		return ;
	}
	ft_lstlast(*lst)->next = newList;
}
