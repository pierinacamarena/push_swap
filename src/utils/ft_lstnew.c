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

t_list	*ft_lstnew(void *content)
{
	t_list		*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (!content)
		list->content = NULL;
	else
		list->content = content;
	list->next = NULL;
	return (list);
}
