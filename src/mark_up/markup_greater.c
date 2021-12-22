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

int markup_head_count(t_stack stacka, int *indices, int index)
{
    int i;
    int j;
    int count;

    i = index_value_finder(stacka, indices, index);
    count = 1;
    if (i == (stacka.max_size - 1))
        return (1);
    j = i + 1;
    while (j < stacka.max_size)
    {
    //    printf("i is %d\n j is %d\n stacka.array[i] is %d\n stacka.array[j] is %d\n count is %d\n", i, j, stacka.array[i], stacka.array[j], count);
      //  printf("prev_max is %d\n", prev_max);
        if (stacka.array[i] < stacka.array[j]) //&& (stacka.array[j] > prev_max))
        {
        //    printf("---(stacka.array[i] < stacka.array[j])---\n");
            //prev_max = stacka.array[j];
            i = j;
            j++;
            count++;
        //    printf("i is %d\n j is %d\n stacka.array[i] is %d\n stacka.array[j] is %d\n, count is %d\n", i, j, stacka.array[i], stacka.array[j], count);
            //printf("prev_max is %d\n", prev_max);
        }
        else
        {
        //    printf("---ELSE---\n");
            j++;
        //    printf("i is %d\n j is %d\n stacka.array[i] is %d\n stacka.array[j] is %d\n, count is %d\n", i, j, stacka.array[i], stacka.array[j], count);
          //  printf("prev_max is %d\n", prev_max);       
        }
    }
    return (count);
}

int find_head_greater(t_stack stacka, int *indices)
{
    int counter[stacka.size];
    int i;
    int head;
    int *m_indeces

    i = 0;
    printf("count per index, incresing order\n");
    printf("[index : count]\n");
    while (i < stacka.size)
    {
        counter[i] = markup_head_count(stacka, indices, i);
        printf("[%d : %d]\n", i, counter[i]);
        i++;
    }
    head = find_max(counter, stacka.size);
    m_indeces = multiple_max(counter, head, stacka.max_size);

    return (head);
}
