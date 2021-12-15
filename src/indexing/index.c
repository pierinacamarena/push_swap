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

int *indexing(t_stack *stacka)
{
    int min;
    int i;
    int *processed;
    int index;

    processed = (int *)malloc(sizeof(int) * stacka->size + 1);
    i = 1;
    processed[0] = find_min(stacka);
    while (i < stacka->size)
    {
        index = find_indices(stacka, processed, i);
        processed[i] = index;
        i++;
    }
    return(processed);
}

int   find_min(t_stack *stacka)
{
    int i;
    int min_index[2];

    min_index[0] = stacka->array[0];
    i = 1;
    while ((i < stacka->size))
    {
        if (stacka->array[i] < min_index[0])
        {
            min_index[0] = stacka->array[i];
            min_index[1] = i;
        }
        i++;
    }
    return (min_index[1]);
}

int   find_indices(t_stack *stacka, int *processed, int len)
{
    int i;
    int check;
    int min_index[2];

    min_index[0] = stacka->array[0];
    i = 1;
    while ((i < stacka->size))
    {
        if (stacka->array[i] < min_index[0])
        {
            check = check_min(processed, len, i);
            if (check == 0)
            {
                min_index[0] = stacka->array[i];
                min_index[1] = i;
            }
        }
        i++;
    }

    return (min_index[1]);
}

int check_min(int *processed, int len, int i)
{
    int j;
    
    j = 0;
    while (j < len)
    {
        if (i == processed[j])
            return (1);
        j++;
    } 
    return (0);
}