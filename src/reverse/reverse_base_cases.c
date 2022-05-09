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

int	ft_sort_three_reverse(t_program *p)
{
	int	a;
	int	b;
	int	c;
	int	count;

	a = p->stackb.array[0];
	b = p->stackb.array[1];
	c = p->stackb.array[2];
	if ((a < b) && (b < c))
		count = sort_three_reverse_helper(p);
	else if ((a < c) && (c < b))
		count = count + ft_rb(p);
	else if ((b < a) && (a < c))
		count = count + ft_rrb(p);
	else if ((c < a) && (a < b))
		count = count + ft_sb(p);
	else if ((b < c) && (c < a))
	{
		count = count + ft_rrb(p);
		count = count + ft_sb(p);
	}
	return (count);
}

int	sort_three_reverse_helper(t_program *p)
{
	int	count;

	count = ft_rb(p);
	count = count + ft_sb(p);
	return (count);
}

int	ft_rbase_case_two(t_program *p)
{
	int	count;

	count = 0;
	ft_val_updta(p);
	ft_val_updta(p);
	if (((p->stackb.a < p->stacka.x) || (p->stackb.a > p->stacka.y)) || \
			((p->stackb.b < p->stacka.x) || (p->stackb.b > p->stacka.y)))
	{
		if (p->stackb.a < p->stacka.x || p->stackb.a > p->stacka.y)
			count = reverse_top_stack_a(p);
		else if (p->stackb.b < p->stacka.x || p->stackb.b > p->stacka.y)
			count = reverse_top_stack_b(p);
	}
	else if ((p->stackb.a > p->stacka.x && p->stackb.a < p->stacka.y) \
			&& (p->stackb.b > p->stacka.x) && (p->stackb.b < p->stacka.y))
	{
		ft_distance_reverse(p);
		if (p->stackb.d_a - 1 <= p->stackb.d_b)
			count = rda_smaller(p);
		else if (p->stackb.d_b < p->stackb.d_a -1)
			count = rdb_smaller(p);
	}
	return (count);
}

int	ft_rbase_case_one(t_program *p)
{
	int	count;

	count = 0;
	if (p->stackb.a < p->stacka.x || p->stackb.a > p->stacka.y)
		count += reverse_top_stack_a(p);
	else if (p->stackb.a > p->stacka.x && p->stackb.a < p->stacka.y)
	{
		ft_distance_reverse(p);
		count = count + rda_smaller(p);
	}
	return (count);
}
