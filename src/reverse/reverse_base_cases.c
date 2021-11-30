/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_base_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:47:01 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:14:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_rbase_case_two(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	ft_val_updta(stacka);
	ft_val_updta(stackb);
	if (((stackb->a < stacka->x) || (stackb->a > stacka->y)) || \
			((stackb->b < stacka->x) || (stackb->b > stacka->y)))
	{
		if (stackb->a < stacka->x || stackb->a > stacka->y)
			count = reverse_top_stack_a(stacka, stackb, printer);
		else if (stackb->b < stacka->x || stackb->b > stacka->y)
			count = reverse_top_stack_b(stacka, stackb, printer);
	}
	else if ((stackb->a > stacka->x && stackb->a < stacka->y) \
			&& (stackb->b > stacka->x) && (stackb->b < stacka->y))
	{
		ft_distance_reverse(stacka, stackb);
		if (stackb->d_a - 1 <= stackb->d_b)
			count = rda_smaller(stacka, stackb, printer);
		else if (stackb->d_b < stackb->d_a -1)
			count = rdb_smaller(stacka, stackb, printer);
	}
	return (count);
}

int	ft_rbase_case_one(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->a < stacka->x || stackb->a > stacka->y)
		count += reverse_top_stack_a(stacka, stackb, printer);
	else if (stackb->a > stacka->x && stackb->a < stacka->y)
	{
		ft_distance_reverse(stacka, stackb);
		count = count + rda_smaller(stacka, stackb, printer);
	}
	return (count);
}
