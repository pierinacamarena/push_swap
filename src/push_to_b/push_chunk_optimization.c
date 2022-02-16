/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_optimization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int optim_higher_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking)
{
    int     count;
    int     k;
    t_hold  new_hold;

    count = 0;
    k = 0;
    new_hold = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
    if (new_hold.number > stackb->x && new_hold.number < stackb->y)
    {
        while (k < new_hold.moves)
        {
            if (new_hold.location == 't')
                count = count + ft_ra(stacka, stackb, printer);
            else if (new_hold.location = 'b')
                count = count + ft_rra(stacka, stackb, printer);
            k++;
        }
        count = count + ft_pb(stacka, stackb, printer);
        chunking->push_nums++;
    }
    return (count);
}

int optim_smaller(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking)
{
    t_hold  next_hold;
    int     new_distance;
    int     i;
    int     count;

    i = 0;
    count = 0;
    next_hold = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
    while (i < next_hold.moves)
    {
        if (next_hold.location == 't')
            count = count + ft_ra(stacka, stackb, printer);
        else if (next_hold.location = 'b')
            count = count + ft_rra(stacka, stackb, printer);
        i++;
    }
    next_hold.distance = optim_distance(*stacka, *stackb, next_hold);
    i = 0;
    while (i < next_hold.distance)
    {
        count = count + ft_rb(stackb, stacka, printer);
        chunking->rrbs++;
        i++;
    }
    count = count + ft_pb(stacka, stackb, printer);
    chunking->push_nums++;
    return (count);
}