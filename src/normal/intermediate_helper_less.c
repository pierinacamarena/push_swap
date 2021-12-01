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

int	da_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;

	i = 0;
	while (i < stacka->d_a)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i <= stacka->d_a)
	{
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	return (count);
}

int	db_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;

	i = 0;
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
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	return (count);
}

int	dc_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;

	i = 0;
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
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	return (count);
}
