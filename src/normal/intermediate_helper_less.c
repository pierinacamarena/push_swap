/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_helper_less.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/30 17:00:44 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
/*
int	rb_complement(t_stack *stacka, t_stack *stackb, t_info *printer, int rrb)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < rrb)
	{
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	return (count);
}

int	da_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;
	int		new_rb;
	int		rrb;

	i = 0;
	new_rb = 0;
	rrb = 0;
	while (i < stacka->d_a)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i <= stacka->d_a)
	{
		count = count + optim_less(stacka, stackb, printer, &new_rb);
		rrb = rrb + new_rb;
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	count = count + rb_complement(stacka, stackb, printer, rrb);
	return (count);
}

int	db_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;
	int		new_rb;
	int		rrb;

	i = 0;
	new_rb = 0;
	rrb = 0;
	count = ft_sa(stacka, stackb, printer);
	while (i < stacka->d_b)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i <= stacka->d_b)
	{
		count = count + optim_less(stacka, stackb, printer, &new_rb);
		rrb = rrb + new_rb;
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	count = count + rb_complement(stacka, stackb, printer, rrb);
	return (count);
}

int	dc_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;
	int		new_rb;
	int		rrb;

	i = 0;
	new_rb = 0;
	rrb = 0;
	count = ft_rra(stacka, stackb, printer);
	while (i < stacka->d_c)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i <= stacka->d_c)
	{
		count = count + optim_less(stacka, stackb, printer, &new_rb);
		rrb = rrb + new_rb;
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	count = count + rb_complement(stacka, stackb, printer, rrb);
	return (count);
}
*/