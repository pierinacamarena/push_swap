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

void	reverse_top_stack_a(t_program *p)
{
	if (p->stackb.a < p->stacka.x)
		ft_pa(p);
	else if (p->stackb.a > p->stacka.y)
	{
		ft_pa(p);
		ft_ra(p);
	}
	
}

void	reverse_top_stack_b(t_program *p)
{
	if (p->stackb.b < p->stacka.x)
	{
		ft_sb(p);
		ft_pa(p);
	}
	else if (p->stackb.b > p->stacka.y)
	{
		ft_sb(p);
		ft_pa(p);
		ft_ra(p);
	}
	
}

void	reverse_top_stack_c(t_program *p)
{
	if (p->stackb.c < p->stacka.x)
	{
		ft_rrb(p);
		ft_pa(p);
	}
	else if (p->stackb.c > p->stacka.y)
	{
		ft_rrb(p);
		ft_pa(p);
		ft_ra(p);
	}
	
}
