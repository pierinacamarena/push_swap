/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:36:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_top_stack_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	a;
	int	x;
	int	y;
	int	count;

	a = stacka->a;
	x = stacka->x;
	y = stackb->y;
	count = 0;
	if (a > x)
	{
		count = count + ft_pb(stacka, stackb, printer);
		return (count);
	}
	else if (a < y)
	{
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_rb(stackb, stacka, printer);
		return (count);
	}
	return (count);
}

int	ft_top_stack_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	b;
	int	x;
	int	y;
	int	count;

	b = stacka->b;
	x = stackb->x;
	y = stackb->y;
	count = 0;
	if (b > x)
	{
		count = count + ft_sa(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		return (count);
	}
	else if (b < y)
	{
		count = count + ft_sa(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_rb(stackb, stacka, printer);
		return (count);
	}
	return (count);
}

int	ft_top_stack_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	c;
	int	x;
	int	y;
	int	count;

	c = stacka->c;
	x = stackb->x;
	y = stackb->y;
	count = 0;
	if (c > x)
	{
		count = count + ft_rra(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		return (count);
	}
	else if (c < y)
	{
		count = count + ft_rra(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_rb(stackb, stacka, printer);
		return (count);
	}
	return (count);
}

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
		count = ft_sa(stacka, stackb, printer);
		while (i < stacka->d_b)
		{
			count = count + ft_rrb(stackb, stacka, printer);
			i++;
		}
		count = count + ft_pb(stacka, stackb, printer);
		i = 0;
		while (i <= stackb->d_b)
		{
			count = count + ft_rb(stackb, stacka, printer);
			i++;
		}
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
		while (i < stacka->d_a)
		{
			count = count + ft_rrb(stackb, stacka, printer);
			i++;
		}
		count = count + ft_pb(stacka, stackb, printer);
		i = 0;
		while (i <= stacka->d_a)
		{
			count = count + ft_rb(stackb, stackb, printer);
			i++;
		}
		return (count);
	}
}
