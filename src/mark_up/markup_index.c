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

int markup_head_count(t_stack stacka, int *indices, int index)
{
    int i;
    int j;
    int midpoint;
    int end;
    int count;

    i = 0;
    count = 1;
    end = stacka.max_size - 1;
    if (stacka.max_size % 2 == 0)
		midpoint = stacka.max_size / 2;
	else
		midpoint = end / 2;

    while (i < stacka.max_size)
    {
        if (indices[i] == index)
            break;
        i++;
    }
    if (i == end)
        return (0);
    j = i + 1;
    while (j < stacka.max_size)
    {
        if (stacka.array[i] < stacka.array[j])
        {
            i++;
            j++;
            count++;
        }
        else
            j++;
    }
    return (count);
}

int find_max(int *array, int len)
{
    int max;
    int i;

    max = array[0];
    i = 1;
    while(i < len)
    {
        if (array[i] > max)
            max = array[i];
        i++;
    }
    return(max);
}

int find_head_greater(t_stack stacka, int *indices)
{
    int counter[stacka.size];
    int i;
    int head;

    while (i < stacka.size)
    {
        counter[i] = markup_head_count(stacka, indices, i);
        i++;
    }
    head = find_max(counter, stacka.size);
    return (head);
}
