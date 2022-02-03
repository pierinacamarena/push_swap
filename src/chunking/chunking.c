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

t_chunk    split_choice(t_stack stacka, int *arr)
{
    t_chunk chunking;

    if(stacka.size < 10)
        chunking = splitter(stacka, 2, arr);
    else if (stacka.size < 50)
        chunking = splitter(stacka, 3, arr);
    else if (stacka.size < 100)
        chunking = splitter(stacka, 4, arr);
    else if (stacka.size < 150)
        chunking = splitter(stacka, 5, arr);
    else if (stacka.size < 200)
        chunking = splitter(stacka, 5, arr);
    else if (stacka.size < 250)
        chunking = splitter(stacka, 6, arr);
    else if (stacka.size < 300)
        chunking = splitter(stacka, 7, arr);
    else if (stacka.size < 350)
        chunking = splitter(stacka, 8, arr);
    else if (stacka.size < 400)
        chunking = splitter(stacka, 9, arr);
    else if (stacka.size < 450)
        chunking = splitter(stacka, 10, arr);
    else if (stacka.size < 500)
        chunking = splitter(stacka, 10, arr);
    else if (stacka.size < 550)
        chunking = splitter(stacka, 11, arr);
    return (chunking);
}

t_chunk     splitter(t_stack stacka, int n, int *arr)
{
    t_chunk chunking;
    int     *chunks;
    int     *chunk_size;
    int     i;
    int     location;
    int     size_temp;

    i = 0;
    chunks = (int *)malloc(sizeof(int) * n);
    chunk_size = (int *)malloc(sizeof(int) * n);
    chunking.chunks = chunks;
    chunking.chunk_size = chunk_size;
    chunking.splits = n;
    location = floor(stacka.size/n) -1;
    size_temp = 0;
    set_size_chunks(&chunking, stacka, n);
    while (i < n)
    {
        printf("location is %d\n", location);
        chunks[i] = arr[location];
        if (i < (n - 2))
            location = location + floor(stacka.size/n);
        else if (i == n - 2)
            location = stacka.size - 1;
        i++;
    }
    return (chunking);
}

void    set_size_chunks(t_chunk *chunking, t_stack stacka, int n)
{
    int i;
    int size;

    if (stacka.size % n == 0)
    {
        size = stacka.size / n;
        i = 0;
        while (i < n)
            chunking->chunk_size[i++] = size;
    }
    else if (stacka.size % n != 0)
    {
        size = floor(stacka.size/n);
        i = 0;
        while (i < (n - 1))
            chunking->chunk_size[i++] = size;
        size = size * (n - 1);
        size = stacka.size - size;
        chunking->chunk_size[i++] = size;
    }
}