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

int	rda_less_midpoint(t_program *p)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < p->stackb.d_a)
	{
		count = count + ft_ra(p);
		i++;
	}
	count = count + ft_pa(p);
	i = 0;
	while (i < p->stackb.d_a)
	{
		count = count + r_optim(p);
		count = count + ft_rra(p);
		i++;
	}
	return (count);
}

int	rdb_less_midpoint(t_program *p)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = ft_sb(p);
	while (i < p->stackb.d_b)
	{
		count = count + ft_ra(p);
		i++;
	}
	count = count + ft_pa(p);
	i = 0;
	while (i < p->stackb.d_b)
	{
		count = count + r_optim(p);
		count = count + ft_rra(p);
		i++;
	}
	return (count);
}

int	rdc_less_midpoint(t_program *p)
{
	int	i;
	int	count;

	i = 0;
	count = ft_rrb(p);
	while (i < p->stackb.d_c)
	{
		count = count + ft_ra(p);
		i++;
	}
	count = count + ft_pa(p);
	i = 0;
	while (i < p->stackb.d_c)
	{
		count = count + r_optim(p);
		count = count + ft_rra(p);
		i++;
	}
	return (count);
}
