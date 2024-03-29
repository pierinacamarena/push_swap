/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
/*
int	ft_top_stack_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	a;
	int	x;
	int	y;
	int	count;

	a = stacka->a;
	x = stackb->x;
	y = stackb->y;
	count = 0;
	if (a > x)
	{
		count = count + ft_pb(stacka, stackb, printer);
		return (count);
	}
	else if (a < y)
	{
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_rb(stackb, stacka, printer);
		return (count);
	}
	return (count);
}

int	ft_top_stack_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	b;
	int	x;
	int	y;
	int	count;

	b = stacka->b;
	x = stackb->x;
	y = stackb->y;
	count = 0;
	if (b > x)
	{
		count = count + ft_sa(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		return (count);
	}
	else if (b < y)
	{
		count = count + ft_sa(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_rb(stackb, stacka, printer);
		return (count);
	}
	return (count);
}

int	ft_top_stack_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	c;
	int	x;
	int	y;
	int	count;

	c = stacka->c;
	x = stackb->x;
	y = stackb->y;
	count = 0;
	if (c > x)
	{
		count = count + ft_rra(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		return (count);
	}
	else if (c < y)
	{
		count = count + ft_rra(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_rb(stackb, stacka, printer);
		return (count);
	}
	return (count);
}
*/