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

int index_value_finder(t_stack stacka, int index)
{
    int i;
    int midpoint;
    int end;

    i = 0;
    end = stacka.size - 1;
    if (stacka.size % 2 == 0)
		midpoint = stacka.size / 2;
	else
		midpoint = end / 2;

    while (i < stacka.size)
    {
        if (stacka.array[i][1] == index)
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

    min = array[0];
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

int multiple_max(int *counter, int head, int size)
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
    //printf("total is %d\n", total);
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
    if (total == 1)
        return (potential_heads[0]);
    else
        i = find_min(potential_heads, total);
    return (i);
}

int temp_stay_a(t_stack stacka)
{
    int total;
    int i;

    total = 0;
    i = 0;
    while (i < stacka.size)
    {
        if (stacka.temp_a[i] == 1)
            total++;
        i++;
    }
    return(total);
}