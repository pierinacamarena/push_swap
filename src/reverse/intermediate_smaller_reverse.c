/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_smaller_reverse.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:36:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rda_less_midpoint(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->stackb.d_a)
	{
		ft_ra(p);
		i++;
	}
	ft_pa(p);
	i = 0;
	while (i < p->stackb.d_a)
	{
		r_optim(p);
		ft_rra(p);
		i++;
	}
}

void	rdb_less_midpoint(t_program *p)
{
	int	i;

	i = 0;
	ft_sb(p);
	while (i < p->stackb.d_b)
	{
		ft_ra(p);
		i++;
	}
	ft_pa(p);
	i = 0;
	while (i < p->stackb.d_b)
	{
		r_optim(p);
		ft_rra(p);
		i++;
	}
}

void	rdc_less_midpoint(t_program *p)
{
	int	i;

	i = 0;
	ft_rrb(p);
	while (i < p->stackb.d_c)
	{
		ft_ra(p);
		i++;
	}
	ft_pa(p);
	i = 0;
	while (i < p->stackb.d_c)
	{
		r_optim(p);
		ft_rra(p);
		i++;
	}
}
