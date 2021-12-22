/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int index_value_finder(t_stack stacka, int * indices, int index)
{
    int i;
    int midpoint;
    int end;

    i = 0;
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
    return (i);
}

int find_max(int *array, int len)
{
    int max;
    int i;
    int count;

    max = array[0];
    i = 1;
    count = 0;
    while(i < len)
    {
        if (array[i] > max)
            max = array[i];
        i++;
    }
    return(max);
}

int find_min(int *array, int len)
{
    int min;
    int i;
    int count;

    max = array[0];
    i = 1;
    count = 0;
    while(i < len)
    {
        if (array[i] < min)
            min = array[i];
        i++;
    }
    return (min);
}

int *multiple_max(int *counter, int head, int size)
{
    int total;
    int i;
    int j;
    int *potential_heads;

    i = 0;
    total = 0;
    while (i < size)
    {
        if (counter[i] == head)
            total++;
        i++;
    }
    potential_heads = (int *)malloc(sizeof(int) * total);
    i = 0;
    j = 0;
    while (i < size)
    {
        if (counter[i] == head)
        {
            potential_heads[j] = i;
            j++; 
        }
        i++;
    }
    return (potential_heads);
}