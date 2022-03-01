/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/12/01 18:04:22 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int optimization(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num, t_hold *next_hold, t_chunk *chunking, int *complete_distance)
{
    int count;

    count = 0;
    if (next_hold->number > stackb->x)
    {
        count = count + set_location_simple(stacka, stackb, printer, *next_hold);
        count = count + ft_pb(stacka, stackb, printer);
    }
    else if (next_hold->number < stackb->x)
    {
        count = count + set_chunk_location(stacka, stackb, printer, next_hold);
        count = count + ft_pb(stacka, stackb, printer);
        complete_distance = complete_distance + next_hold->distance;        
    }
    return (count);
}

int rrb_chunk(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num, t_chunk *chunking, int *complete_distance)
{
    t_hold next_hold;
    int count;

    count = 0;
    next_hold = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
    if (next_hold.number < stackb->y)
    {
        while (next_hold.number < stackb->y)
        {
            count = count + optimization(stacka, stackb, printer, num, &next_hold, chunking, complete_distance);
            next_hold = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
        }
    }
    else
    {
        count = count + ft_rrb(stackb, stacka, printer);
        complete_distance--;
    }
    return (count);
}

int solve_intermediate(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking, t_hold *num)
{
    int i;
    int count;
    int distance_complete;

    i = 0;
    count = 0;
    while (i < distance_complete)
    {
        count = count + set_chunk_location(stacka, stackb, printer, num);
        count = count + ft_pb(stacka, stackb, printer);
        distance_complete = num->distance;
        while (distance_complete > 0)
            count = count + rrb_chunk(stacka, stackb, printer, num, chunking, &distance_complete);
    }
    return (count);
}

int chunk_solver(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking)
{
    int i;
    int count;
    int exp_stackbsize;
    t_hold num;

    i = 0;
    count = 0;
    exp_stackbsize = expected_stackbsize(*chunking);
    while (stackb->size < exp_stackbsize)
    {
        num = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
        if (num.number > stackb->x)
            count = count + smallest_push(stacka, stackb, printer,num);
        else if (num.number < stackb->x && num.number > stackb->y)
        {
            count = count + solve_intermediate(stacka, stackb, printer, chunking, &num);
        }
    }
    return (count);
}


    