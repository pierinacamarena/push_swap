/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:47:01 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:14:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_sort_three(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	a;
	int	b;
	int	c;
	int	count;

	a = stacka->array[0];
	b = stacka->array[1];
	c = stacka->array[2];
	if ((a < c) && (c < b))
		count = ft_sort_three_helper(stacka, stackb, printer);
	else if ((b < a) && (a < c))
		count = ft_sa(stacka, stackb, printer);
	else if ((c < a) && (a < b))
		count = ft_rra(stacka, stackb, printer);
	else if ((b < c) && (c < a))
		count = ft_ra(stacka, stackb, printer);
	else if ((c < b) && (b < a))
	{
		count = ft_ra(stacka, stackb, printer);
		count = count + ft_sa(stacka, stackb, printer);
	}
	return (count);
}

int	ft_sort_three_helper(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = ft_rra(stacka, stackb, printer);
	count = count + ft_sa(stacka, stackb, printer);
	return (count);	
}

int	ft_base_case_two(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if ((stacka->a > stackb->x || stacka->a < stackb->y) \
			|| (stacka->b > stackb->x || stacka->b < stackb->y))
	{
		if (stacka->a > stackb->x || stacka->a < stackb->y)
			count = ft_top_stack_a(stacka, stackb, printer);
		else if (stacka->b > stackb->x || stacka->b < stackb->y)
			count = ft_top_stack_b(stacka, stackb, printer);
	}
	else if ((stacka->a < stackb->x && stacka->a > stackb->y) \
			&& (stacka->b < stackb->x) && (stacka->b > stackb->y))
	{
		ft_distance(stacka, stackb);
		if (stacka->d_a - 1 <= stacka->d_b)
			count = ft_da_smaller(stacka, stackb, printer);
		else if (stacka->d_b < stacka->d_a -1)
			count = ft_db_smaller(stacka, stackb, printer);
	}
	return (count);
}

int	ft_base_case_one(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stacka->a > stackb->x || stacka->a < stackb->y)
		count = ft_top_stack_a(stacka, stackb, printer);
	else if (stacka->a < stackb->x && stacka->a > stackb->y)
	{
		ft_distance(stacka, stackb);
		count = ft_da_smaller(stacka, stackb, printer);
	}
	return (count);
}
