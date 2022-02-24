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

int optimization(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num, t_hold *next_hold, t_chunk *chunking, int complete_distance)
{
    int count;

    count = 0;
    if (next_hold.num > stackb->x)
    {
        count = count + ft_set_location_simple(stacka, stackb, printer, next_hold);
        count = count + ft_pb(stacka, stackb, printer);
}
    else if (next_hold.num < stackb->x)
    {
        count = count + ft_set_chunk_location(stacka, stackb, printer, next_hold);
        count = count + ft_pb(stacka, stackb, printer, next_hold);
        complete_distance = complete_distance + next_hold->distance        
    }
    return (count);
}

int rrb_chunk(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num, t_chunk *chunking, int *complete_distance)
{
    t_hold next_hold;
    int count;

    count = 0;
    next_hold = choose_number(*chunking);
    if (next_hold.num < stackb->y)
    {
        while (next_hold.num < stackb->y)
        {
            count = count + optimization(stacka, stackb, printer, num, next_hold, chunking, complete_distance);
            next_hold = choose_number(*chunking);
        }
    }
    else
    {
        count = count + ft_rrb(stacka, stackb, printer);
        complete_distance--;
    }
    return (count);
}

int solve_intermediate()
{
    int i;
    int count;
    int exp_stackbsize

    i = 0;
    count = 0;
    while (i < complete_distance)
    {
        count = count + set_chunk_location();
        count = count + ft_pb(stacka, stackb, printer);
        distance_complete = num.distance;
        while (complete_distance > 0)
            count = count + rrb_chunk();
    }
    return (count);
}

int chunk_solver()
{
    int i;
    t_hold num;

    i = 0;
    exp_stackbsize = expected_stackbsize(*chunking);
    while (stackb->size < exp_stackbsize)
    {
        num = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
        if (num.number > stackb->x)
            count = count + smallest_push(stacka, stackb, printer);
        else if (num.number < stackb->x && num.number > stackb->y)
        {
            count = count + solve_intermediate();
        }

    }
    return (count);
}


    