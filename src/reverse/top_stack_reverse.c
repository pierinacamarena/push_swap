/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_stack_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	reverse_top_stack_a(t_program *p)
{
	int	count;

	count = 0;
	if (p->stackb.a < p->stacka.x)
	{
		count = count + ft_pa(p);
		return (count);
	}
	else if (p->stackb.a > p->stacka.y)
	{
		count = count + ft_pa(p);
		count = count + ft_ra(p);
		return (count);
	}
	return (count);
}

int	reverse_top_stack_b(t_program *p)
{
	int	count;

	count = 0;
	if (p->stackb.b < p->stacka.x)
	{
		count = count + ft_sb(p);
		count = count + ft_pa(p);
		return (count);
	}
	else if (p->stackb.b > p->stacka.y)
	{
		count = count + ft_sb(p);
		count = count + ft_pa(p);
		count = count + ft_ra(p);
		return (count);
	}
	return (count);
}

int	reverse_top_stack_c(t_program *p)
{
	int	count;

	count = 0;
	if (p->stackb.c < p->stacka.x)
	{
		count = count + ft_rrb(p);
		count = count + ft_pa(p);
		return (count);
	}
	else if (p->stackb.c > p->stacka.y)
	{
		count = count + ft_rrb(p);
		count = count + ft_pa(p);
		count = count + ft_ra(p);
		return (count);
	}
	return (count);
}
