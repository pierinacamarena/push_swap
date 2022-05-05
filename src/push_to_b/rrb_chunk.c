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
    int exp_stackbsize;

    exp_stackbsize = expected_stackbsize(*chunking);
    count = 0;
    if (next_hold->number > stackb->x && (stackb->size < exp_stackbsize))
    {
        count = count + set_location_simple(stacka, stackb, printer, *next_hold);
        count = count + ft_pb(stacka, stackb, printer);
    }
    else if (next_hold->number < stackb->x && (stackb->size < exp_stackbsize))
    {
        count = count + set_chunk_location(stacka, stackb, printer, next_hold);
        count = count + ft_pb(stacka, stackb, printer);
        *complete_distance = *complete_distance + next_hold->distance;
        //printf("complete_distance is: %d at instruction %d\n", *complete_distance, printer->count);
    }
    else if (stackb->size == exp_stackbsize)
        return (count);
    return (count);
}

int rrb_chunk(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num, t_chunk *chunking, int *complete_distance)
{
    t_hold next_hold;
    int count;
    int exp_stackbsize;

    count = 0;
    exp_stackbsize = expected_stackbsize(*chunking);
    next_hold = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
    //printf("next_hold is %d\n at instruction %d", next_hold.number, printer->count);
    next_hold.distance = optim_distance(*stacka, *stackb, next_hold);
    if ((next_hold.number < stackb->y) && (stackb->size < exp_stackbsize))
    {
        while (next_hold.number < stackb->y)
        {
            count = count + optimization(stacka, stackb, printer, num, &next_hold, chunking, complete_distance);
            if (stackb->size < exp_stackbsize)
            {
                next_hold = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
                next_hold.distance = optim_distance(*stacka, *stackb, next_hold);
            }
            else if (stackb->size == exp_stackbsize)
                break;
        }
    }
    else if (stackb->size == exp_stackbsize && *complete_distance > 0)
    {
        while (*complete_distance > 0)
        {
            count = count + ft_rrb(stackb, stacka, printer);
            *complete_distance = *complete_distance - 1;
        }
        return (count);
    }
    else if (stackb->size == exp_stackbsize && *complete_distance == 0)
        return (count);
    else
    {
        count = count + ft_rrb(stackb, stacka, printer);
        *complete_distance = *complete_distance - 1;
        //printf("INSIDE RRB ----- complete_distance is: %d at instruction %d\n", *complete_distance, printer->count);
    }
    return (count);
}

int solve_intermediate(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking, t_hold *num)
{
    //int i;
    int j;
    int count;
    int distance_complete;

    //i = 0;
    j = 0;
    count = 0;
    distance_complete = num->distance;
    //printf("complete_distance is: %d at instruction %d\n", distance_complete, printer->count);
    while (distance_complete > 0)
    {
        //printf("I AM INSIDE THE BIG DISTANCE_COMPLETE > 0 LOOP, instruction %d\n", printer->count);
        count = count + set_chunk_location(stacka, stackb, printer, num);
        count = count + ft_pb(stacka, stackb, printer);
        while (distance_complete > 0)
        {
            //printf("I AM INSIDE THE SMALL DISTANCE_COMPLETE > 0 LOOP, instruction %d\n", printer->count);
            count = count + rrb_chunk(stacka, stackb, printer, num, chunking, &distance_complete);
            j++;
        }
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
        num.distance = distance(*stacka, *stackb, num);
        if (num.number > stackb->x)
            count = count + smallest_push(stacka, stackb, printer,num);
        else if (num.number < stackb->x && num.number > stackb->y)
        {
            count = count + solve_intermediate(stacka, stackb, printer, chunking, &num);
        }
    }
    return (count);
}


    