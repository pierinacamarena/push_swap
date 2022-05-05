/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int optim_checker(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int checker;

    checker = 0;
    if ((stacka->a > stackb->a && stacka->a < stackb->c) || \
        (stacka->a < stackb->a && stacka->a > stackb->b))
        checker++;
    if ((stacka->b > stackb->a && stacka->b < stackb->c) || \
        (stacka->b < stackb->a && stacka->b > stackb->b))
        checker++;
    if ((stacka->c > stackb->a && stacka->c < stackb->c) || \
        (stacka->c < stackb->a && stacka->c > stackb->b))
        checker++;
    return (checker);
}

int optim(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    //printf("inside optimization main function\n");
    //printf("number of instruction is %d\n", printer->count);
    int count;
    int checker;
    int ind_check;

    count = 0;
    while ((checker = optim_checker(stacka, stackb, printer)) > 0)
    {
        while ((ind_check = optima_checker(stacka, stackb, printer)) == 1)
        {
            if ((stacka->a > stackb->a && stacka->a < stackb->c) || \
                (stacka->a < stackb->a && stacka->a > stackb->b))
                count = count + optim_a(stacka, stackb, printer);
        }
        while ((ind_check = optimb_checker(stacka, stackb, printer)) == 1)
        {
            if ((stacka->b > stackb->a && stacka->b < stackb->c) || \
                (stacka->b < stackb->a && stacka->b > stackb->b))
                count = count + optim_b(stacka, stackb, printer);
        }
        while ((ind_check = optimc_checker(stacka, stackb, printer)) == 1)
        {
            if ((stacka->c > stackb->a && stacka->c < stackb->c) || \
                (stacka->c < stackb->a && stacka->c > stackb->b))
                count = count + optim_c(stacka, stackb, printer);
        }
    }
    return (count);
}

int optim_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    //printf("inside optimization a\n");
    //printf("number of instruction is %d\n", printer->count);
    int count;
    
    count = 0;
    if (stacka->a > stackb->a && stacka->a < stackb->c)
    {
        //printf("inside optimization a_a\n");
        //printf("number of instruction is %d\n", printer->count);
        count = count + ft_pb(stacka, stackb, printer);
    }
    else if (stacka->a < stackb->a && stacka->a > stackb->b)
    {
        //printf("inside optimization a_b\n");
        //printf("number of instruction is %d\n", printer->count);
        count = count + ft_pb(stacka, stackb, printer);
        count = count + ft_sb(stackb, stacka, printer);
    }
    return (count);
}

int optim_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    //printf("inside optimization b\n");
    //printf("number of instruction is %d\n", printer->count);
    int count;

    count = 0;
    if (stacka->b > stackb->a && stacka->b < stackb->c)
    {
        //printf("inside optimization b_a\n");
        //printf("number of instruction is %d\n", printer->count);
        count = count + ft_sa(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
    }
    else if (stacka->b < stackb->a && stacka->b > stackb->b)
    {
        //printf("inside optimization b_b\n");
        //printf("number of instruction is %d\n", printer->count);
        count = count + ft_sa(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
        count = count + ft_sb(stackb, stacka, printer);
    }
    return (count);
}

int optim_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    //printf("inside optimization c\n");
    //printf("number of instruction is %d\n", printer->count);
    int count;

    count = 0;
    if (stacka->c > stackb->a && stacka->c < stackb->c)
    {
        //printf("inside optimization c_a\n");
        //printf("number of instruction is %d\n", printer->count);
        count = count + ft_rra(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
    }
    else if (stacka->c < stackb->a && stacka->c > stackb->b)
    {
        //printf("inside optimization c_b\n");
        //printf("number of instruction is %d\n", printer->count);
        count = count + ft_rra(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
        count = count + ft_sb(stackb, stacka, printer);
    }
    return (count);
}