/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_second.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    remove_element(t_node  **root, int value)
{
    t_node   *curr;
    t_node   *to_remove;
    int     str_comp;

    if (*root == NULL)
        return;
    if ((*root)->location == value)
    {
        to_remove = *root;
        *root = (*root)->next;
        free(to_remove);
        return ;
    }
    curr = *root;
    while (curr->next != NULL)
    {
        if (curr->next->location == value)
        {
            to_remove = curr->next;
            curr->next = curr->next->next;
            free(to_remove);
            return;
        }
        curr = curr->next;
    }
}