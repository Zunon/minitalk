/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:57:16 by kalmheir          #+#    #+#             */
/*   Updated: 2021/10/05 07:55:55 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*old;
	t_list	*result;

	old = lst;
	if (!lst)
		return (0);
	result = ft_lstnew((*f)(lst->content));
	if (lst->next)
		lst = lst->next;
	while (lst->next)
	{
		ft_lstadd_back(&result, ft_lstnew((*f)(lst->content)));
		lst = lst->next;
	}
	ft_lstadd_back(&result, ft_lstnew((*f)(lst->content)));
	ft_lstclear(&old, del);
	return (result);
}
