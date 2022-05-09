/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_optimization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	r_optim_checker(t_program *p)
{
	int	checker;

	checker = 0;
	if ((p->stackb.a < p->stacka.a && p->stackb.a > p->stacka.c) || \
			(p->stackb.a > p->stacka.a && p->stackb.a < p->stacka.b))
		checker++;
	if ((p->stackb.b < p->stacka.a && p->stackb.b > p->stacka.c) || \
			(p->stackb.b > p->stacka.a && p->stackb.b < p->stacka.b))
		checker++;
	if ((p->stackb.a < p->stacka.a && p->stackb.a > p->stacka.c) || \
			(p->stackb.a > p->stacka.a && p->stackb.a < p->stacka.b))
		checker++;
	return (checker);
}

void	r_optim(t_program *p)
{
	if ((p->stackb.a < p->stacka.a && p->stackb.a > p->stacka.c) || \
			(p->stackb.a > p->stacka.a && p->stackb.a < p->stacka.b))
		r_optim_a(p);
	if ((p->stackb.b < p->stacka.a && p->stackb.b > p->stacka.c) || \
			(p->stackb.b > p->stacka.a && p->stackb.b < p->stacka.b))
		r_optim_b(p);
	if ((p->stackb.a < p->stacka.a && p->stackb.a > p->stacka.c) || \
			(p->stackb.a > p->stacka.a && p->stackb.a < p->stacka.b))
		r_optim_c(p);
}

void	r_optim_a(t_program *p)
{
	if (p->stackb.a < p->stacka.a && p->stackb.a > p->stacka.c)
	{
		ft_pa(p);
	}
	else if (p->stackb.a > p->stacka.a && p->stackb.a < p->stacka.b)
	{
		ft_pa(p);
		ft_sa(p);
	}
}

void	r_optim_b(t_program *p)
{
	if (p->stackb.b < p->stacka.a && p->stackb.b > p->stacka.c)
	{
		ft_sb(p);
		ft_pa(p);
	}
	else if (p->stackb.b > p->stacka.a && p->stackb.b < p->stacka.b)
	{
		ft_sb(p);
		ft_pa(p);
		ft_sa(p);
	}
}

void	r_optim_c(t_program *p)
{
	if (p->stackb.c < p->stacka.a && p->stackb.c > p->stacka.c)
	{
		ft_rrb(p);
		ft_pa(p);
	}
	else if (p->stackb.c > p->stacka.a && p->stackb.c < p->stacka.b)
	{
		ft_rrb(p);
		ft_pa(p);
		ft_sa(p);
	}
}
