/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:36:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rdb_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	if (stackb->b < stacka->midpoint)
	{
		count = ft_sb(stackb, stacka, printer);
		while (i < stackb->d_b)
		{
			count = count + ft_ra(stacka, stackb, printer);
			i++;
		}
		count = count + ft_pa(stacka, stackb, printer);
		i = 0;
		while (i < stackb->d_b)
		{
			count = count + ft_rra(stacka, stackb, printer);
			i++;
		}
		return (count);
	}
	else
	{
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
			count = count + ft_ra(stacka, stackb, printer);
			i++;
		}
		return (count);
	}
}

int	rdc_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	if (stackb->c < stacka->midpoint)
	{
		i = 0;
		count = ft_rrb(stackb, stacka, printer);
		while (i < stackb->d_c)
		{
			count = count + ft_ra(stacka, stackb, printer);
			i++;
		}
		count = count + ft_pa(stacka, stackb, printer);
		i = 0;
		while (i < stackb->d_c)
		{
			count = count + ft_rra(stacka, stackb, printer);
			i++;
		}
		return (count);
	}
	else
	{
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
			count = count + ft_ra(stacka, stackb, printer);
			i++;
		}
		return (count);
	}
}

int	rda_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (stackb->a < stacka->midpoint)
	{
		while (i < stackb->d_a)
		{
			count = count + ft_ra(stacka, stackb, printer);
			i++;
		}
		count = count + ft_pa(stacka, stackb, printer);
		i = 0;
		while (i < stackb->d_a)
		{
			count = count + ft_rra(stacka, stackb, printer);
			i++;
		}
		return (count);
	}
	else
	{
		while (i < stackb->d_a)
		{
			count = count + ft_rra(stacka, stackb, printer);
			i++;
		}
		count = count + ft_pa(stacka, stackb, printer);
		i = 0;
		while (i <= stackb->d_a)
		{
			count = count + ft_ra(stacka, stackb, printer);
			i++;
		}
		return (count);
	}
}
