/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_hold choose_number(t_stack *stacka, t_stack *stackb, t_info *printer, int chunk)
{
    t_hold  hold_one;
    t_hold  hold_two;
    int     count;
    int     i;

    count = 0;
    i = 0;
    hold_one = find_top_num(*stacka, chunk);
	hold_two = find_lower_num(*stacka, chunk);
    if (hold_one.moves < hold_two.moves)
    {
        hold_one.location = 't';
        return (hold_one);
    }
    else if (hold_two.moves < hold_one.moves)
    {
        hold_two.location = 'b';
        return (hold_two);
    }
    else
    {
        if (hold_one.number < hold_two.number)
        {
            hold_one.location = 't';
            return (hold_one);
        }
        else if (hold_two.number < hold_one.number)
        {
            hold_two.location = 'b';
            return (hold_two);
        }
    }
}

int    solve_other_chunk(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking)
{
    int     i;
    int     j;
    int     count;
    t_hold  num;
    int     d;
    int     k;
    char    c;

    i = 0;
    c = chunk_checker(*stacka, *chunking);
    chunking->push_nums = 0;
    while (c = chunk_checker(*stacka, *chunking) == 'y')
	//while (chunking->push_nums < chunking->chunk_size[chunking->current_chunk])
	{
        //c = chunk_checker(*stacka, *chunking);
        num = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
        printf("num is %d\n", num.number);
        if (num.number > stackb->x)
        {
            printf("------------------------------------------------\n");
            printf("I am at 'num.number > stackb->x'\n");
            printf("i am at instruction %d\n", printer->count);
            printf("stackb->x is %d\n", stackb->x);
            printf("the chosen number is  %d\n", num.number);
            k = 0;
            while (k < num.moves)
            {
                if (num.location == 't')
                    count = count + ft_ra(stacka, stackb, printer);
                else if (num.location = 'b')
                    count = count + ft_rra(stacka, stackb, printer);
                k++;
            }
            count = count + ft_pb(stacka, stackb, printer);
        }
        else if (num.number < stackb->x && num.number > stackb->y)
        {
            printf("------------------------------------------------\n");
            printf("I am at num.number < stackb->x && num.number > stackb->y\n");
            printf("i am at instruction %d\n", printer->count);
            printf("stackb->x is %d, stackb->y is %d\n", stackb->x, stackb->y);
            printf("the chosen number is  %d\n", num.number);
            d = distance(*stacka, *stackb, num);
            k = 0;
            while (k < num.moves)
            {
                if (num.location == 't')
                    count = count + ft_ra(stacka, stackb, printer);
                else if (num.location = 'b')
                    count = count + ft_rra(stacka, stackb, printer);
                k++;
            }
            j = 0;
            if (num.number < stackb->midpoint)
            {
                while (j < d)
                {
                    count = count + ft_rrb(stackb, stacka, printer);
                    j++;
                }
                count = count + ft_pb(stacka, stackb, printer);
                j = 0;
                while (j <= d)
                {
                    count = count + ft_rb(stackb, stacka, printer);
                    j++;
                }
            }
            else if (num.number > stackb->midpoint)
            {
                while (j < d)
                {
                    count = count + ft_rb(stackb, stacka, printer);
                    j++;
                }
                count = count + ft_pb(stacka, stackb, printer);
                j = 0;
                while (j < d)
                {
                    count = count + optim_higher_midpoint(stacka, stackb, printer, chunking);
                    count = count + ft_rrb(stackb, stacka, printer);
                    j++;
                }
            }            
        }
        chunking->push_nums++;
        c = chunk_checker(*stacka, *chunking);
	}                
    return (count);
}

char    chunk_checker(t_stack stacka, t_chunk chunking)
{
    int i;

    i = 0;
    while (i < stacka.size)
    {
        if (stacka.array[i] < chunking.chunks[chunking.current_chunk])
            return ('y');
        i++;
    }
    return ('n');
}

int    solve_other_chunk_v2(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking)
{
    int     i;
    int     j;
    int     count;
    t_hold  num;
    int     k;
    char    c;
    t_hold  next_num;
    int     exp_stackbsize;

    i = 0;
    c = chunk_checker(*stacka, *chunking);
    chunking->push_nums = 0;
    exp_stackbsize = (expected_stackbsize(*chunking));
	while (chunk_checker(*stacka, *chunking) == 'y' && stackb->size < exp_stackbsize)
    {
        num = choose_number(stacka, stackb, printer, chunking->chunks[chunking->current_chunk]);
        if (num.number > stackb->x)
        {
            count = count + smallest_push(stacka, stackb, printer, num);
        }
        else if (num.number < stackb->x && num.number > stackb->y)
        {
            //count = count + mid_push(stacka, stackb, printer, &num, chunking);
            num.distance = distance(*stacka, *stackb, num);
            k = 0;
            while (k < num.moves)
            {
                if (num.location == 't')
                    count = count + ft_ra(stacka, stackb, printer);
                else if (num.location = 'b')
                    count = count + ft_rra(stacka, stackb, printer);
                k++;
            }
            if (num.number > stackb->midpoint)
            {
                chunking->rrbs = 0;
                while (j < num.distance)
                {
                    count = count + ft_rb(stackb, stacka, printer);
                    j++;
                    chunking->rrbs++;
                }
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
        if (chunking->push_nums >= chunking->chunk_size[chunking->current_chunk])
            break;
        c = chunk_checker(*stacka, *chunking);
	}                
    return (count);
}