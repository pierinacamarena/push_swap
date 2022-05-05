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

int	support(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num)
{
	int	count;
	int	j;
	int	d;

	j = 0;
	d = distance(*stacka, *stackb, num);
	count = 0;
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
	return (count);
}

int	middle_helper(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num)
{
	int	j;
	int	d;
	int	count;

	j = 0;
	d = distance(*stacka, *stackb, num);
	count = 0;
	if (num.number < stackb->midpoint)
		count = support(stacka, stackb, printer, num);
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
	return (count);
}
