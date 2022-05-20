/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    insert_end(t_node **root, char *str, int location)
{
    t_node *new_node;
    t_node *curr;
    
    new_node= malloc(sizeof(t_node));
    if (new_node == NULL)
        exit(1);
    new_node->next = NULL;
    new_node->str = str;
    new_node->location = location;
    if (*root == NULL)
    {
        *root = new_node;
        return ;
    }
    curr = *root;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}


void    insert_after(t_node *chosen_node, char *str, int location)
{
    t_node* new_node;

    new_node = malloc(sizeof(t_node));
    if (new_node == NULL)
        return;
    new_node->str = str;
    new_node->location = location;
    new_node->next = chosen_node->next;
    chosen_node->next = new_node;
}

void    insert_begining(t_node **root, char *str, int location)
{
    int len;
    t_node *new_node;

    len = ft_strlen(str);
    new_node = malloc(sizeof(t_node));
    if (new_node == NULL)
        return;
    new_node->str = str;
    new_node->location = location;
    new_node->next = *root;
    *root = new_node;
}

t_node *init_list(void)
{
    t_node *root;

    root = NULL;
    return (root);
}

void    deallocate(t_node **root)
{
    t_node    *curr;
    t_node    *aux;

    curr = *root;
    while (curr != NULL)
    {
        aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}