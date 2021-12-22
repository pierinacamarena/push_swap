/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int index_head_count(t_stack stacka, int *indices, int index)
{
    int i;
    int j;
    int count;
    int prev_max;

    count = 1;
    i = index_value_finder(stacka, indices, index);
    if (i == (stacka.max_size - 1))
        return(1);
    prev_max = indices[i];
    j = i + 1;
    while (j < stacka.max_size)
    {
        if ((indices[i] + 1) == indices[j])
        {
            i = j;
            j++;
            count++;
        }
        else
            j++;
    }
    return(count);
}

int find_head_index(t_stack stacka, int *indices)
{
    int counter[stacka.size];
    int i;
    int head;

    i = 0;
    printf("count per index, incresing order\n");
    printf("[index : count]\n");
    while (i < stacka.size)
    {
        counter[i] = index_head_count(stacka, indices, i);
        printf("[%d : %d]\n", i, counter[i]);
        i++;
    }
    head = find_max(counter, stacka.size);
    return (head);
}
