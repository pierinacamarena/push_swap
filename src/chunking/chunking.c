/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int    *split_choice(t_stack stacka, int *arr)
{
    int *chunks;

    if(stacka.size < 10)
        chunks = splitter(stacka, 2, arr);
    else if (stacka.size < 50)
        chunks = splitter(stacka, 3, arr);
    else if (stacka.size < 100)
        chunks = splitter(stacka, 4, arr);
    else if (stacka.size < 150)
        chunks = splitter(stacka, 5, arr);
    else if (stacka.size < 200)
        chunks = splitter(stacka, 5, arr);
    else if (stacka.size < 250)
        chunks = splitter(stacka, 6, arr);
    else if (stacka.size < 300)
        chunks = splitter(stacka, 7, arr);
    else if (stacka.size < 350)
        chunks = splitter(stacka, 8, arr);
    else if (stacka.size < 400)
        chunks = splitter(stacka, 9, arr);
    else if (stacka.size < 450)
        chunks = splitter(stacka, 10, arr);
    else if (stacka.size < 500)
        chunks = splitter(stacka, 10, arr);
    else if (stacka.size < 550)
        chunks = splitter(stacka, 11, arr);
    return (chunks);
}

int     *splitter(t_stack stacka, int n, int *arr)
{
    int *chunks;
    int i;
    int location;

    i = 0;
    chunks = (int *)malloc(sizeof(int) * n);
    if (!chunks)
        return (NULL);
    location = floor(stacka.size/n) -1;
    while (i < n)
    {
        chunks[i] = arr[location];
        if (i < (n - 2))
            location = location + floor(stacka.size/n);
        else if (i == n - 2)
            location = stacka.size - 1;
        i++;
    }
    return (chunks);
}