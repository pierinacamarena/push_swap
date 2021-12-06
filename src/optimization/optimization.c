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

int optim_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    if (stacka->a > stackb->a && stacka->a < stackb->c)
        count = ft_pb(stacka, stackb, printer);
    else if (stacka->a < stackb->a && stacka->a > stackb->b)
    {
        count = ft_pb(stacka, stackb, printer);
        count = count + ft_sb(stackb, stacka, printer);
    }
    return (count);
}

int optim_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    if (stacka->b > stackb->a && stacka->b < stackb->c)
    {
        count = ft_sa(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
    }
    else if (stacka->b < stackb->a && stacka->b > stackb->b)
    {
        count = ft_sa(stacka, stackb, printer);
        count = count + ft_pb(stacka, stackb, printer);
        count = count + ft_sb(stackb, stacka, printer);
    }
    return (count);
}

int optim_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    if (stacka->c > stackb->a && stacka->c < stackb->c)
    {
        count = ft_rrb(stackb, stacka, printer);
        count = count + ft_pb(stacka, stackb, printer);
    }
    else if (stacka->c < stackb->a && stacka->c > stackb->b)
    {
        count = ft_rrb(stackb, stacka, printer);
        count = count + ft_pb(stacka, stackb, printer);
        count = count + ft_sb(stackb, stacka, printer);
    }
    return (count);
}