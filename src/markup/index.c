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
    int i;
    int *processed;
    int index;

    processed = (int *)malloc(sizeof(int) * stack->size + 1);
    while (i < stack->size)
    {
        index = find_min(stacka);
        processed[i] = index
        min = stacka->array[index];
        i++;
    }


    min = find_min(stacka);
}

int   find_min(t_stack *stacka)
{
    int i;
    int j;

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