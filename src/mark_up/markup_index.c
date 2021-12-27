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

/**
function that counts how many numbers would sty in stacka, if index was the head
**/

int index_head_count(t_stack stacka, int index)
{
    int i;
    int j;
    int count;

    count = 1;
    i = index_value_finder(stacka, index);
    if (i == (stacka.max_size - 1))
        return(1);
    j = i + 1;
    while (j < stacka.max_size)
    {
        if ((stacka.indices[i] + 1) == stacka.indices[j])
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

/**
function that creates an array with the count of each index as a respective head
**/
int *head_index_counter(t_stack stacka)
{
    int counter[stacka.size];
    int i;
    int head;
    int min_head;

    i = 0;
    printf("count per index, incresing order\n");
    printf("[index : count]\n");
    while (i < stacka.size)
    {
        counter[i] = index_head_count(stacka, i);
        printf("[%d : %d]\n", i, counter[i]);
        i++;
    }
    //head = find_max(counter, stacka.size);
    //min_head = multiple_max(counter, head, stacka.max_size);
    return (counter);
}

int head_finder_index(int *counter, int size)
{
    int head;
    int min_head;

    head = find_max(counter, size);
    min_head = multiple_max(counter, head, size);

    return(min_head);
}

void index_selection(t_stack *stacka, int index)
{
    int i;
    int j;

    count = 0;
    i = index_value_finder(*stacka, index);
    if (i == (stacka->max_size - 1))
        return(1);
    j = i + 1;
    while (count < i)
    {
        stacka->list[count] = 0;
        count++;
    }
    stacka->list[i] = 1;
    while (j < stacka->max_size)
    {
        if ((stacka->indices[i] + 1) == stacka->indices[j])
        {
            stacka->list[j] = 1;
            i = j;
            j++;
        }
        else
        {
            stacka->list[j] = 0;
            j++;
        }
    }
}