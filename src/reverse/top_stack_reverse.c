/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_stack_reverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	reverse_top_stack_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->a < stacka->x)
	{
		count = count + ft_pa(stacka, stackb, printer);
		return (count);
	}
	else if (stackb->a > stacka->y)
	{
		count = count + ft_pa(stacka, stackb, printer);
		count = count + ft_ra(stacka, stackb, printer);
		return (count);
	}
	return (count);
}

int	reverse_top_stack_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->b < stacka->x)
	{
		count = count + ft_sb(stackb, stacka, printer);
		count = count + ft_pa(stacka, stackb, printer);
		return (count);
	}
	else if (stackb->b > stacka->y)
	{
		count = count + ft_sb(stackb, stacka, printer);
		count = count + ft_pa(stacka, stackb, printer);
		count = count + ft_ra(stacka, stackb, printer);
		return (count);
	}
	return (count);
}

int	reverse_top_stack_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->c < stacka->x)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		count = count + ft_pa(stacka, stackb, printer);
		return (count);
	}
	else if (stackb->c > stacka->y)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		count = count + ft_pa(stacka, stackb, printer);
		count = count + ft_ra(stacka, stackb, printer);
		return (count);
	}
	return (count);
}
