/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_optimization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int r_optim_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    if (stackb->a < stacka->a && stackb->a > stacka->c)
        count = ft_pa(stacka, stackb, printer);
    else if (stackb->a > stacka->a && stackb->a < stacka->b)
    {
        count = ft_pa(stacka, stackb, printer);
        count = count + ft_sa(stacka, stackb, printer);
    }
    return (count);
}

int r_optim_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    if (stackb->b < stacka->a && stackb->b > stacka->c)
    {
        count = ft_sb(stackb, stacka, printer);
        count = count + ft_pa(stacka, stackb, printer);
    }
    else if (stackb->b > stacka->a && stackb->b < stacka->b)
    {
        count = ft_sb(stackb, stacka, printer);
        count = count + ft_pa(stacka, stackb, printer);
        count = count + ft_sa(stacka, stackb, printer);
    }
    return (count);
}

int r_optim_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    if (stackb->a < stacka->a && stackb->a > stacka->c)
    {
        count = ft_rrb(stackb, stacka, printer);
        count = count + ft_pa(stacka, stackb, printer);
    }
    else if (stackb->a > stacka->a && stackb->a < stacka->b)
    {
        count = ft_rrb(stackb, stacka, printer);
        count = ft_pa(stacka, stackb, printer);
        count = count + ft_sa(stacka, stackb, printer);
    }
    return (count);
}