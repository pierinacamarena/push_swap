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

int    solve_first_chunk_original(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk chunking)
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
        else if (num.number < stackb->y)
        {
            printf("------------------------------------------------\n");
            printf("I am at num.number < stackb->y\n");
            printf("i am at instruction %d\n", printer->count);
            printf("stackb->y is %d\n", stackb->y);
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
            count = count + ft_rb(stackb, stacka, printer);
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
                    
                    count = count + ft_rrb(stackb, stacka, printer);
                    j++;
                }
            }            
        }
        i++;
	}                
    return (count);
}