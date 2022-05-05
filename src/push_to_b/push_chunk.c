/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_hold find_top_num(t_stack stacka, int border)
{
    int i;
    t_hold hold_one;

    i = 0;
    while (i < stacka.size)
    {
        if (stacka.array[i] <= border)
            {
                hold_one.number = stacka.array[i];
                hold_one.moves = i;
                break;
            }
        i++;
    }
    return (hold_one);
}

t_hold find_lower_num(t_stack stacka, int border)
{
    int i;
    int j;
    t_hold hold_two;

    i = stacka.size - 1;
    j = 1;
    while (i >= 0)
    {
        if (stacka.array[i] <= border)
        {
            hold_two.number = stacka.array[i];
            hold_two.moves = j;
            break;
        }
        i--;
        j++;
    }
    return (hold_two);
}

int choose_push(t_stack *stacka, t_stack *stackb, t_info *printer, int *chunks)
{
    t_hold  hold_one;
    t_hold  hold_two;
    int     count;
    int     i;

    count = 0;
    i = 0;
    hold_one = find_top_num(*stacka, chunks[0]);
	hold_two = find_lower_num(*stacka, chunks[0]);
    if (hold_one.moves <= hold_two.moves)
    {
        if (hold_one.moves == 0)
            count = count + ft_pb(stacka, stackb, printer);
        else if (hold_one.moves == 1)
        {
            count = count + ft_sa(stacka, stackb, printer);
            count = count + ft_pb(stacka, stackb, printer);
        }
        else
        {
            while (i < hold_one.moves)
            {
                count = count + ft_ra(stacka, stackb, printer);
                i++;
            }
            count = count + ft_pb(stacka, stackb, printer);
        }

    } 
    else if (hold_two.moves < hold_one.moves)
    {
        i = 0;
        while (i < hold_two.moves)
        {
            count = count + ft_rra(stacka, stackb, printer);
            i++;
        }
        count = count + ft_pb(stacka, stackb, printer);
    }
}

int    solve_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{ 
    int     *arr;
    int     count;
    int     i;
    int     j;
    t_chunk chunking;
    int     stackb_size;

    i = 0;
    arr = indexing(stacka);
	chunking = split_choice(*stacka, arr);
    chunking.current_chunk = i;
    count = first_chunk(stacka, stackb, printer, chunking);
    stackb_size = expected_stackbsize(chunking);
    while (i < chunking.splits)
    {
        chunking.current_chunk = i;
        count = count + chunk_solver(stacka, stackb, printer, &chunking);
        i++;
    }
    free(arr);
    free(chunking.chunks);
    free(chunking.chunk_size);
    return (count);
}
