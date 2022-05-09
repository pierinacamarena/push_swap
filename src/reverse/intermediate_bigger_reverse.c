/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_bigger_reverse.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rda_more_midpoint(t_program *p)
{
	int	i;
	int	new_ra;
	int	rra;

	i = 0;
	new_ra = 0;
	rra = 0;
	while (i < p->stackb.d_a)
	{
		ft_rra(p);
		i++;
	}
	ft_pa(p);
	i = 0;
	while (i <= p->stackb.d_a)
	{
		r_optim_less(p, &new_ra);
		rra = rra + new_ra;
		ft_ra(p);
		i++;
	}
	i = 0;
	while (i < rra)
	{
		ft_ra(p);
		i++;
	}
}

void	rdb_more_midpoint(t_program *p)
{
	int	i;
	int	new_ra;
	int	rra;

	i = 0;
	new_ra = 0;
	rra = 0;
	ft_sb(p);
	while (i < p->stackb.d_b)
	{
		ft_rra(p);
		i++;
	}
	ft_pa(p);
	i = 0;
	while (i <= (p->stackb.d_b))
	{
		ft_ra(p);
		r_optim_less(p, &new_ra);
		rra = rra + new_ra;
		i++;
	}
	i = 0;
	while (i < rra)
	{
		ft_ra(p);
		i++;
	}
}

void	rdc_more_midpoint(t_program *p)
{
	int	i;
	int	new_ra;
	int	rra;

	i = 0;
	new_ra = 0;
	rra = 0;
	ft_rrb(p);
	while (i < p->stackb.d_c)
	{
		ft_rra(p);
		i++;
	}
	ft_pa(p);
	i = 0;
	while (i <= (p->stackb.d_c))
	{
		r_optim_less(p, &new_ra);
		rra = rra + new_ra;
		ft_ra(p);
		i++;
	}
	i = 0;
	while (i < rra)
	{
		ft_ra(p);
		i++;
	}
}
