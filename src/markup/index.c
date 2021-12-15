/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    indexing(t_stack *stacka)
{
    int min;
    int j;
    int i;
    int *processed;

    i = 0;
    j = 0;

    min = find_min(stacka);
}

void   find_min(t_stack *stacka)
{
    int i;
    int j;
    int *processed;

    i = 0;
    j = 1;

    while ((i < stacka->size) && (j < stacka->size))
    {
        if (stacka->array[i] > stacka->array[j])
        {
            i++;
            j++;   
        }
        else
            j++;
    }
    return (i);
}