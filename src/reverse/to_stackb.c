/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stackb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:36:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int pb_stackb(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    count = 0;
    count += ft_pb(stacka, stackb, printer);
    count += ft_pb(stacka, stackb, printer);
    count += ft_pb(stacka, stackb, printer);
    ft_sort_three_reverse(stackb, stacka, printer);
    if (stacka->a > stackb->midpoint)
    { 
        count += ft_pb(stacka, stackb, printer);
    }
    else if (stacka->a < stackb->midpoint)
    {
        count += ft_pb(stacka, stackb, printer);
        count += ft_rb(stackb, stacka, printer);
    }
    return (count);
}