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

int smallest_push(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num)
{
    int count;
    int k;

    k = 0;
    count = 0;
    while (k < num.moves)
    {
        if (num.location == 't')
            count = count + ft_ra(stacka, stackb, printer);
        else if (num.location = 'b')
            count = count + ft_rra(stacka, stackb, printer);
        k++;
    }
    count = count + ft_pb(stacka, stackb, printer);
    return (count);
}

int mid_push(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num, t_chunk *chunking)
{
    int k;
    int j;
    int count;
    int exp_stackbsize;
    t_hold  next_num;

    count = 0;
    exp_stackbsize = expected_stackbsize(*chunking);
    num->distance = distance(*stacka, *stackb, *num);
    k = 0;
    count = count + set_chunk_location(stacka, stackb, printer, num);
    if (num->number > stackb->midpoint)
    {
        count = count + ft_pb(stacka, stackb, printer);
        chunking->push_nums++;
        j = 0;
        while (chunking->rrbs > 0)
        {
            count = count + optim_higher_midpoint(stacka, stackb, printer, chunking);
            if (stackb->size < exp_stackbsize)
                next_num = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
            while (next_num.number < stackb->x && stackb->size < exp_stackbsize)
            {
                count = count + optim_smaller(stacka, stackb, printer, chunking);
                next_num = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
                if (chunking->push_nums >= chunking->chunk_size[chunking->current_chunk])
                    break;
                if (stackb->size == exp_stackbsize)
                    break;
            }
            count = count + ft_rrb(stackb, stacka, printer);
            chunking->rrbs--;
            if (chunking->push_nums >= chunking->chunk_size[chunking->current_chunk])
                break;
            if (stackb->size == exp_stackbsize)
                break;
        }
        if (chunking->rrbs > 0)
        {
            while (chunking->rrbs > 0)
            {
                count = count + ft_rrb(stackb, stacka, printer);
                chunking->rrbs--;
            }
        }    
    }          
}
