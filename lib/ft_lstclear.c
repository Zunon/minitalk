/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:36:32 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/05 07:53:43 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*holder;

	if (!lst || !*lst || !del)
		return ;
	while ((*lst)->next)
	{
		holder = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = holder;
	}
	ft_lstdelone(*lst, del);
	*lst = 0;
}
