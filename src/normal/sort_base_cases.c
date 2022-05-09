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

int	ft_sort_three(t_program *p)
{
	int	a;
	int	b;
	int	c;
	int	count;

	a = p->stacka.array[0];
	b = p->stacka.array[1];
	c = p->stacka.array[2];
	if ((a < c) && (c < b))
		count = ft_sort_three_helper(p);
	else if ((b < a) && (a < c))
		count = ft_sa(p);
	else if ((c < a) && (a < b))
		count = ft_rra(p);
	else if ((b < c) && (c < a))
		count = ft_ra(p);
	else if ((c < b) && (b < a))
	{
		count = ft_ra(p);
		count = count + ft_sa(p);
	}
	return (count);
}

int	ft_sort_three_helper(t_program *p)
{
	int	count;

	count = ft_rra(p);
	count = count + ft_sa(p);
	return (count);
}
/*
int	ft_base_case_two(t_program *p)
{
	int	count;

	count = 0;
	if ((p->stacka.a > p->stackb.x || p->stacka.a < p->stackb.y) \
			|| (p->stacka.b > p->stackb.x || p->stacka.b < p->stackb.y))
	{
		if (p->stacka.a > p->stackb.x || p->stacka.a < p->stackb.y)
			count = ft_top_stack_a(p);
		else if (p->stacka.b > p->stackb.x || p->stacka.b < p->stackb.y)
			count = ft_top_stack_b(p);
	}
	else if ((p->stacka.a < p->stackb.x && p->stacka.a > p->stackb.y) \
			&& (p->stacka.b < p->stackb.x) && (p->stacka.b > p->stackb.y))
	{
		ft_distance(p);
		if (p->stacka.d_a - 1 <= p->stacka.d_b)
			count = ft_da_smaller(p);
		else if (p->stacka.d_b < p->stacka.d_a -1)
			count = ft_db_smaller(p);
	}
	return (count);
}

int	ft_base_case_one(t_program *p)
{
	int	count;

	count = 0;
	if (p->stacka.a > p->stackb.x || p->stacka.a < p->stackb.y)
		count = ft_top_stack_a(p);
	else if (p->stacka.a < p->stackb.x && p->stacka.a > p->stackb.y)
	{
		ft_distance(p);
		count = ft_da_smaller(p);
	}
	return (count);
}
*/