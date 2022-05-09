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

int	sort_inverse_top(t_program *p)
{
	int	count;

	if (p->stackb.a < p->stacka.x || p->stackb.a > p->stacka.y)
		count = count + reverse_top_stack_a(p);
	else if (p->stackb.b < p->stacka.x || p->stackb.b > p->stacka.y)
		count = count + reverse_top_stack_b(p);
	else if (p->stackb.c < p->stacka.x || p->stackb.c > p->stacka.y)
		count = count + reverse_top_stack_c(p);
	return (count);
}

int	sort_inverse_inter(t_program *p)
{
	int	count;

	count = 0;
	ft_distance_reverse(p);
	if ((p->stackb.d_a - 1 <= p->stackb.d_b) \
			&& (p->stackb.d_a - 1 <= p->stackb.d_c))
		count = count + rda_smaller(p);
	else
	{
		if (p->stackb.d_b < p->stackb.d_c)
			count = count + rdb_smaller(p);
		else if (p->stackb.d_c < p->stackb.d_b)
			count = count + rdc_smaller(p);
		else if (p->stackb.d_b == p->stackb.d_c)
			count = count + rdb_smaller(p);
	}
	return (count);
}

int	sort_inverse_end(t_program *p)
{
	int	count;

	count = 0;
	if (p->stackb.size == 2)
	{
		ft_val_updta(p);
		ft_val_updtb(p);
		count = count + ft_rbase_case_two(p);
	}
	if (p->stackb.size == 1)
	{
		count = count + ft_rbase_case_one(p);
	}
	return (0);
}

int	sort_inverse_initial(t_program *p)
{
	int	count;
	int	n;

	count = 0;
	n = p->stacka.size;
	while (n > 3)
	{
		count = count + ft_pb(p);
		n--;
	}
	return (count);
}

int	ft_sort_inverse(t_program *p)
{
	int	j;
	int	count;

	count = 0;
	sort_inverse_initial(p);
	count = count + ft_sort_three(p);
	j = 3;
	while (j < p->stacka.max_size && p->stackb.size >= 3)
	{
		if ((p->stackb.a < p->stacka.x || p->stackb.a > p->stacka.y) \
				|| (p->stackb.b < p->stacka.x || p->stackb.b > p->stacka.y) \
				|| (p->stackb.c < p->stacka.x || p->stackb.c > p->stacka.y))
				count = count + sort_inverse_top(p);
		else if ((p->stackb.a > p->stacka.x && p->stackb.a < p->stacka.y) \
				&& (p->stackb.b > p->stacka.x && p->stackb.b < p->stacka.y) \
				&& (p->stackb.c > p->stacka.x && p->stackb.c < p->stacka.y))
				count = count + sort_inverse_inter(p);
		j++;
	}
	count = count + sort_inverse_end(p);
	return (count);
}
