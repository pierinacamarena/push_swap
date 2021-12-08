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

int	rda_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < stackb->d_a)
	{
		count = count + ft_rra(stacka, stackb, printer);
		i++;
	}
	count = count + ft_pa(stacka, stackb, printer);
	i = 0;
	while (i <= stackb->d_a)
	{
		count = count + r_optim_less(stacka, stackb, printer);
		count = count + ft_ra(stacka, stackb, printer);
		i++;
	}
	return (count);
}

int	rdb_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	count = ft_sb(stackb, stacka, printer);
	while (i < stackb->d_b)
	{
		count = count + ft_rra(stacka, stackb, printer);
		i++;
	}
	count = count + ft_pa(stacka, stackb, printer);
	i = 0;
	while (i <= stackb->d_b)
	{
		count = count + r_optim_less(stacka, stackb, printer);
		count = count + ft_ra(stacka, stackb, printer);
		i++;
	}
	return (count);
}

int	rdc_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	count = ft_rrb(stackb, stacka, printer);
	while (i < stackb->d_c)
	{
		count = count + ft_rra(stacka, stackb, printer);
		i++;
	}
	count = count + ft_pa(stacka, stackb, printer);
	i = 0;
	while (i <= stackb->d_c)
	{
		count = count + r_optim_less(stacka, stackb, printer);
		count = count + ft_ra(stacka, stackb, printer);
		i++;
	}
	return (count);
}
