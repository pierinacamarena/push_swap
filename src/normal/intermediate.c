/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_db_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	if (stacka->b > stackb->midpoint)
	{
		count = ft_sa(stacka, stackb, printer);
		while (i < stacka->d_b)
		{
			count = count + ft_rb(stackb, stacka, printer);
			i++;
		}
		count = count + ft_pb(stacka, stackb, printer);
		i = 0;
		while (i < stacka->d_b)
		{
			count = count + ft_rrb(stackb, stacka, printer);
			i++;
		}
		return (count);
	}
	else
	{
		count = db_less_midpoint(stacka, stackb, printer);
		return (count);
	}
}

int	ft_dc_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	if (stacka->c > stackb->midpoint)
	{
		count = ft_rra(stacka, stackb, printer);
		while (i < stacka->d_c)
		{
			count = count + ft_rb(stackb, stacka, printer);
			i++;
		}
		count = count + ft_pb(stacka, stackb, printer);
		i = 0;
		while (i < stacka->d_c)
		{
			count = count + ft_rrb(stackb, stacka, printer);
			i++;
		}
		return (count);
	}
	else
	{
		count = dc_less_midpoint(stacka, stackb, printer);
		return (count);
	}
}

int	ft_da_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (stacka->a > stackb->midpoint)
	{
		while (i < stacka->d_a)
		{
			count = count + ft_rb(stackb, stacka, printer);
			i++;
		}
		count = count + ft_pb(stacka, stackb, printer);
		i = 0;
		while (i < stacka->d_a)
		{
			count = count + ft_rrb(stackb, stacka, printer);
			i++;
		}
		return (count);
	}
	else
	{
		count = dc_less_midpoint(stacka, stackb, printer);
		return (count);
	}
}
