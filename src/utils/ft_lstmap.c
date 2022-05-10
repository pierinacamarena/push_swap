/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:43:25 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:50:57 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;

	if (!lst || !del)
		return (NULL);
	if (!f)
		return (NULL);
	elem = ft_lstnew(f(lst->content));
	if (!elem)
		return (NULL);
	if (lst->next)
	{
		elem->next = ft_lstmap(lst->next, f, del);
		if (!elem->next)
		{
			ft_lstdelone(elem, del);
			return (NULL);
		}
	}
	else
		elem->next = NULL;
	return (elem);
}
*/
