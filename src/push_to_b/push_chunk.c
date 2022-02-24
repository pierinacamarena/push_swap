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
    //printf("hold one is %d\nhold two is %d\n", hold_one.number, hold_two.number);
    if (hold_one.moves <= hold_two.moves)
    {
        //printf("the number is %d, and it needs %d ra\n", hold_one.number, hold_one.moves);
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
        //printf("the number is %d, and it needs %d rra\n", hold_two.number, hold_two.moves);
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
    t_chunk chunking;
    int     stackb_size;

    i = 0;
    arr = indexing(stacka);
	chunking = split_choice(*stacka, arr);
    chunking.current_chunk = i;
    count = solve_first_chunk_original(stacka, stackb, printer, chunking);
    stackb_size = expected_stackbsize(chunking);
    printf("the expected size of stack b for the first chunk is %d\n", stackb_size);
    //chunking.current_chunk++;
    //count = count + solve_other_chunk_v2(stacka, stackb, printer, &chunking);
    //stackb_size = expected_stackbsize(chunking);
    //printf("the expected size of stack b for the second chunk is %d\n", stackb_size);
    //count = count + solve_other_chunk_v2(stacka, stackb, printer, &chunking);
    while (i < chunking.splits)
    {
        chunking.current_chunk = i;
        count = count + solve_other_chunk_v2(stacka, stackb, printer, &chunking);
        i++;
    }
    return (count);
}

int    solve_first_chunk(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk chunking)
{
    int     i;
    int     j;
    int     count;
    t_hold  num;
    int     d;
    int     k;

    i = 0;
    count = 0;
	while (i < 3)
	{	
		count = count + choose_push(stacka, stackb, printer, chunking.chunks);
		i++;
	}
	count = count + ft_sort_three_reverse(stackb, stacka, printer);
	i = 0;
	while (i < (chunking.chunk_size[0] - 3))
	{
        num = choose_number(stacka, stackb, printer, chunking.chunks[0]);
        printf("num is %d\n", num.number);
        if (num.number > stackb->x)
        {
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
        else if (num.number < stackb->y)
        {
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
            count = count + ft_rb(stackb, stacka, printer);
        }
        else if (num.number < stackb->x && num.number > stackb->y)
        {
            d = distance(*stacka, *stackb, num);
            k = 0;
            while (k < num.moves)
            {
                if (num.location == 't')
                {
                    if (num.number > stackb->midpoint)
                    {
                        if (num.moves > d)
                        {
                            while (k < d)
                            {
                                count = count + ft_rr(stacka, stackb, printer);
                                k++;
                            }
                            d = 0;
                            while (k < num.moves)
                            {
                                count = count + ft_ra(stacka, stackb, printer);
                                k++;
                            }
                        }
                        else if (d > num.moves)
                        {
                            while (k < num.moves)
                            {
                                count = count + ft_rr(stacka, stackb, printer);
                                k++;
                            }
                            d = d - num.moves;
                        }
                        else
                        {
                            while (k < num.moves)
                            {
                                count = count + ft_rr(stacka, stackb, printer);
                                k++;
                            }
                            d = 0;
                        }   
                    }
                    else
                    {
                        count = count + ft_ra(stacka, stackb, printer);
                        k++;
                    }
                }
                else if (num.location = 'b')
                {
                    count = count + ft_rra(stacka, stackb, printer);
                    k++;
                }
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
                    
                    count = count + ft_rrb(stackb, stacka, printer);
                    j++;
                }
            }            
        }
        i++;
	}                
    return (count);
}