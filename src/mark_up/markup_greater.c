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
    //    printf("i is %d\n j is %d\n stacka.array[i] is %d\n stacka.array[j] is %d\n count is %d\n", i, j, stacka.array[i], stacka.array[j], count);
    //    printf("prev_max is %d\n", prev_max);
        if (stacka.array[i] < stacka.array[j]) //&& (stacka.array[j] > prev_max))
        {
        //    printf("---(stacka.array[i] < stacka.array[j])---\n");
         //   prev_max = stacka.array[j];
            i = j;
            j++;
            count++;
          //  printf("i is %d\n j is %d\n stacka.array[i] is %d\n stacka.array[j] is %d\n, count is %d\n", i, j, stacka.array[i], stacka.array[j], count);
        //    printf("prev_max is %d\n", prev_max);
        }
        else
        {
            //printf("---ELSE---\n");
            j++;
        //    printf("i is %d\n j is %d\n stacka.array[i] is %d\n stacka.array[j] is %d\n, count is %d\n", i, j, stacka.array[i], stacka.array[j], count);
        //    printf("prev_max is %d\n", prev_max);       
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

    i = 0;
    //printf("count per index, incresing order\n");
    //printf("[index : count]\n");
    counter = (int *)malloc(sizeof(int) * stacka.size + 1);
    while (i < stacka.size)
    {
        counter[i] = markup_head_count(stacka, i);
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
        stacka->bool_index[count] = 0;
        count++;
    }
    stacka->bool_index[i] = 1;
    while (j < stacka->size)
    {
        if (stacka->array[i] < stacka->array[j])
        {
            stacka->bool_index[j] = 1;
            i = j;
            j++;
            count++;
        }
        else
        {
            stacka->bool_index[j] = 0;
            j++;
        }
    }
}