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

void	ft_sort_three_reverse(t_program *p)
{
	int	a;
	int	b;
	int	c;

	a = p->stackb.array[0];
	b = p->stackb.array[1];
	c = p->stackb.array[2];
	if ((a < b) && (b < c))
		sort_three_reverse_helper(p);
	else if ((a < c) && (c < b))
		ft_rb(p);
	else if ((b < a) && (a < c))
		ft_rrb(p);
	else if ((c < a) && (a < b))
		ft_sb(p);
	else if ((b < c) && (c < a))
	{
		ft_rrb(p);
		ft_sb(p);
	}
}

void	sort_three_reverse_helper(t_program *p)
{
	ft_rb(p);
	ft_sb(p);
}

void	ft_rbase_case_two(t_program *p)
{
	ft_val_updta(p);
	ft_val_updta(p);
	if (((p->stackb.a < p->stacka.x) || (p->stackb.a > p->stacka.y)) || \
			((p->stackb.b < p->stacka.x) || (p->stackb.b > p->stacka.y)))
	{
		if (p->stackb.a < p->stacka.x || p->stackb.a > p->stacka.y)
			reverse_top_stack_a(p);
		else if (p->stackb.b < p->stacka.x || p->stackb.b > p->stacka.y)
			reverse_top_stack_b(p);
	}
	else if ((p->stackb.a > p->stacka.x && p->stackb.a < p->stacka.y) \
			&& (p->stackb.b > p->stacka.x) && (p->stackb.b < p->stacka.y))
	{
		ft_distance_reverse(p);
		if (p->stackb.d_a - 1 <= p->stackb.d_b)
			rda_smaller(p);
		else if (p->stackb.d_b < p->stackb.d_a -1)
			rdb_smaller(p);
	}
}

void	ft_rbase_case_one(t_program *p)
{
	if (p->stackb.a < p->stacka.x || p->stackb.a > p->stacka.y)
		reverse_top_stack_a(p);
	else if (p->stackb.a > p->stacka.x && p->stackb.a < p->stacka.y)
	{
		ft_distance_reverse(p);
		rda_smaller(p);
	}
}
