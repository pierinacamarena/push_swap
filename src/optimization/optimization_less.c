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

int optim_less(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    count = 0;
    if ((stacka->a > stackb->a && stacka->a < stackb->c) || \
        (stacka->a < stackb->a && stacka->a > stackb->b))
        count = count + optim_less_a(stacka, stackb, printer);
    if ((stacka->b > stackb->a && stacka->b < stackb->c) || \
        (stacka->b < stackb->a && stacka->b > stackb->b))
        count = count + optim_less_b(stacka, stackb, printer);
    if ((stacka->c > stackb->a && stacka->c < stackb->c) || \
        (stacka->c < stackb->a && stacka->c > stackb->b))
        count = count + optim_less_c(stacka, stackb, printer);
    return (count); 
}

int optim_less_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    count = 0;
    if (stacka->a > stackb->a && stacka->a < stackb->c)
        count = count + ft_pb(stacka, stackb, printer);
    else if (stacka->a < stackb->a && stacka->a > stackb->b)
    {
        count = count + ft_pb(stacka, stackb, printer);
        count = count + ft_sb(stackb, stacka, printer);
    }
    return (count);
}

int optim_less_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    count = 0;
    if (stacka->b > stackb->a && stacka->b < stackb->c)
    {
        count = count + ft_sa(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
    }
    else if (stacka->b < stackb->a && stacka->b > stackb->b)
    {
        count = count + ft_sa(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
        count = count + ft_sb(stackb, stacka, printer);
    }
    return (count);
}

int optim_less_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    count = 0;
    if (stacka->c > stackb->a && stacka->c < stackb->c)
    {
        count = count + ft_rra(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
    }
    else if (stacka->c < stackb->a && stacka->c > stackb->b)
    {
        count = count + ft_rra(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
        count = count + ft_sb(stackb, stacka, printer);
    }
    return (count);
}