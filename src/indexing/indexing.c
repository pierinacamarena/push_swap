/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int index_finder(t_stack stacka, int numb)
{
    int i;

    i = 0;
    while (i < stacka.max_size)
    {
        if (stacka.array[i][0] == numb)
            return (i);
        i++;
    }
    return (-1);
}

void set_index(int *arr, t_stack *stacka)
{
    int i;
    int index;

    i = 0;
    while (i < stacka->size)
    {
        index = index_finder(*stacka, arr[i]);
        stacka->array[index][1] = i;
        i++;
    }
}
