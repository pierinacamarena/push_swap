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

int	rda_more_midpoint(t_program *p)
{
	int	count;
	int	i;
	int	new_ra;
	int	rra;

	i = 0;
	count = 0;
	new_ra = 0;
	rra = 0;
	while (i < p->stackb.d_a)
	{
		count = count + ft_rra(p);
		i++;
	}
	count = count + ft_pa(p);
	i = 0;
	while (i <= p->stackb.d_a)
	{
		count = count + r_optim_less(p, &new_ra);
		rra = rra + new_ra;
		count = count + ft_ra(p);
		i++;
	}
	i = 0;
	while (i < rra)
	{
		ft_ra(p);
		i++;
	}
	return (count);
}

int	rdb_more_midpoint(t_program *p)
{
	int	i;
	int	count;
	int	new_ra;
	int	rra;

	i = 0;
	new_ra = 0;
	rra = 0;
	count = ft_sb(p);
	while (i < p->stackb.d_b)
	{
		count = count + ft_rra(p);
		i++;
	}
	count = count + ft_pa(p);
	i = 0;
	while (i <= (p->stackb.d_b))
	{
		count = count + ft_ra(p);
		count = count + r_optim_less(p, &new_ra);
		rra = rra + new_ra;
		i++;
	}
	i = 0;
	while (i < rra)
	{
		ft_ra(p);
		i++;
	}
	return (count);
}

int	rdc_more_midpoint(t_program *p)
{
	int	i;
	int	count;
	int	new_ra;
	int	rra;

	i = 0;
	new_ra = 0;
	rra = 0;
	count = ft_rrb(p);
	while (i < p->stackb.d_c)
	{
		count = count + ft_rra(p);
		i++;
	}
	count = count + ft_pa(p);
	i = 0;
	while (i <= (p->stackb.d_c))
	{
		count = count + r_optim_less(p, &new_ra);
		rra = rra + new_ra;
		count = count + ft_ra(p);
		i++;
	}
	i = 0;
	while (i < rra)
	{
		ft_ra(p);
		i++;
	}
	return (count);
}
