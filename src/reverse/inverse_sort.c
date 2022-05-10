/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:36:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_inverse_top(t_program *p)
{
	if (p->stackb.a < p->stacka.x || p->stackb.a > p->stacka.y)
		reverse_top_stack_a(p);
	else if (p->stackb.b < p->stacka.x || p->stackb.b > p->stacka.y)
		reverse_top_stack_b(p);
	else if (p->stackb.c < p->stacka.x || p->stackb.c > p->stacka.y)
		reverse_top_stack_c(p);
}

void	sort_inverse_inter(t_program *p)
{
	ft_distance_reverse(p);
	if ((p->stackb.d_a - 1 <= p->stackb.d_b) \
			&& (p->stackb.d_a - 1 <= p->stackb.d_c))
		rda_smaller(p);
	else
	{
		if (p->stackb.d_b < p->stackb.d_c)
			rdb_smaller(p);
		else if (p->stackb.d_c < p->stackb.d_b)
			rdc_smaller(p);
		else if (p->stackb.d_b == p->stackb.d_c)
			rdb_smaller(p);
	}
}

void	sort_inverse_end(t_program *p)
{
	if (p->stackb.size == 2)
	{
		ft_val_updta(p);
		ft_val_updtb(p);
		ft_rbase_case_two(p);
	}
	if (p->stackb.size == 1)
	{
		ft_rbase_case_one(p);
	}
}

void	sort_inverse_initial(t_program *p)
{
	int	n;

	n = p->stacka.size;
	while (n > 3)
	{
		ft_pb(p);
		n--;
	}
}

void	ft_sort_inverse(t_program *p)
{
	int	j;

	sort_inverse_initial(p);
	ft_sort_three(p);
	j = 3;
	while (j < p->stacka.max_size && p->stackb.size >= 3)
	{
		if ((p->stackb.a < p->stacka.x || p->stackb.a > p->stacka.y) \
				|| (p->stackb.b < p->stacka.x || p->stackb.b > p->stacka.y) \
				|| (p->stackb.c < p->stacka.x || p->stackb.c > p->stacka.y))
			sort_inverse_top(p);
		else if ((p->stackb.a > p->stacka.x && p->stackb.a < p->stacka.y) \
				&& (p->stackb.b > p->stacka.x && p->stackb.b < p->stacka.y) \
				&& (p->stackb.c > p->stacka.x && p->stackb.c < p->stacka.y))
			sort_inverse_inter(p);
		j++;
	}
	sort_inverse_end(p);
}
