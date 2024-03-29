/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_greater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
/*
int markup_head_count(t_stack stacka, int index)
{
    int i;
    int j;
    int count;

    i = index_value_finder(stacka, index);
    count = 1;
    if (i == (stacka.size - 1))
        return (1);
    j = i + 1;
    while (j < stacka.size)
    {
        if (stacka.array[i][0] < stacka.array[j][0]) 
        && (stacka.array[j] > prev_max))
        {
        //    printf("---(stacka.array[i] < stacka.array[j])---\n");
         //   prev_max = stacka.array[j];
            i = j;
            j++;
            count++;
        }
        else
        {
            //printf("---ELSE---\n");
            j++;       
        }
    }
    return (count);
}

int *head_greater_counter(t_stack stacka)
{
    int *counter;
    int i;
    int head;
    int min_head;
    int location;

    i = 0;
    //printf("count per index, incresing order\n");
    //printf("[index : count]\n");
    counter = (int *)malloc(sizeof(int) * stacka.size + 1);
    while (i < stacka.size)
    {
        location = index_value_finder(stacka, i);
        counter[location] = markup_head_count(stacka, i);
        //printf("[%d : %d]\n", i, counter[i]);
        i++;
    }
    return (counter);
}

int head_finder_greater(int *counter, int size)
{
    int head;
    int min_head;

    head = find_max(counter, size);
    min_head = multiple_max(counter, head, size);

    return(min_head);
}

void greater_selection(t_stack *stacka, int index)
{
    int i;
    int j;
    int count;

    i = index_value_finder(*stacka, index);
    count = 0;
    j = i + 1;
    while (count < i)
    {
        stacka->array[count][2] = 0;
        count++;
    }
    stacka->array[i][2] = 1;
    while (j < stacka->size)
    {
        if (stacka->array[i][0] < stacka->array[j][0])
        {
            stacka->array[j][2] = 1;
            i = j;
            j++;
            count++;
        }
        else
        {
            stacka->array[j][2] = 0;
            j++;
        }
    }
}

int *greater_temp_selection(t_stack *stacka, int index)
{
    int i;
    int j;
    int count;
    int *temp;

    temp = (int *)malloc(sizeof(int) * stacka->size);   
    i = index_value_finder(*stacka, index);
    count = 0;
    j = i + 1;
    while (count < i)
    {
        stacka->array[count][2] = 0;
        count++;
    }
    stacka->array[i][2] = 1;
    while (j < stacka->size)
    {
        if (stacka->array[i][0] < stacka->array[j][0])
        {
            temp[j] = 1;
            i = j;
            j++;
            count++;
        }
        else
        {
            temp[j] = 0;
            j++;
        }
    }
    return (temp);
}
*/