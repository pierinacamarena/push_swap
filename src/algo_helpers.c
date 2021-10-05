/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/05 19:14:34 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_top_stack_a(t_stack *stackA, t_stack *stackB)
{
	int	a;
	int	x;
	int	y;
	int	count;

	a = stackA->a;
	x = stackB->x;
	y = stackB->y;
	count = 0;
	if (a > x)
	{
		count = count + ft_pb(stackA, stackB);
		return (count);
	}
	else if (a < y)
	{
		count = count + ft_pb(stackA, stackB);
		count = count + ft_rb(stackB);
		return (count);
	}
	return (count);
}

int	ft_top_stack_b(t_stack *stackA, t_stack *stackB)
{
	int	b;
	int	x;
	int	y;
	int	count;

	b = stackA->b;
	x = stackB->x;
	y = stackB->y;
	count = 0;
	if (b > x)
	{
		count = count + ft_sa(stackA);
		count = count + ft_pb(stackA, stackB);
		return (count);
	}
	else if (b < y)
	{
		count = count + ft_sa(stackA);
		count = count + ft_pb(stackA, stackB);
		count = count + ft_rb(stackB);
		return(count);
	}
	return(count);
}

int	ft_top_stack_c(t_stack *stackA, t_stack *stackB)
{
	int	c;
	int	x;
	int	y;
	int	count;

	c = stackA->c;
	x = stackB->x;
	y = stackB->y;
	count = 0;
	if (c > x)
	{
		count = count + ft_rra(stackA);
		count = count + ft_pb(stackA, stackB);
		return (count);
	}
	else if (c < y)
	{
		count = count + ft_rra(stackA);
		count = count + ft_pb(stackA, stackB);
		count = count + ft_rb(stackB);
		return (count);
	}
	return(count);
}

int	ft_db_smaller(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	count;

	i = 0;
	if (stackA->b > stackB->midpoint)
	{
		count = ft_sa(stackA);
		while (i < stackA->d_b)
		{
			count = count + ft_rb(stackB);
			i++;
		}
		count = count + ft_pb(stackA, stackB);
		i = 0;
		while (i < stackA->d_b)
		{
			count = count + ft_rrb(stackB);
			i++;
		}
		return (count);
	}
	else
	{
		count = ft_sa(stackA);
		while (i < stackA->d_b)
		{
			count = count + ft_rrb(stackB);
			i++;
		}
		count = count + ft_pb(stackA, stackB);
		i = 0;
		while (i <= stackA->d_b)
		{
			count = count + ft_rb(stackB);
			i++;
		}
		return (count);
	}
}

int	ft_dc_smaller(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	count;

	i = 0;
	if (stackA->c > stackB->midpoint)
	{
		count = ft_rra(stackA);
		while (i < stackA->d_c)
		{
			count = count + ft_rb(stackB);
			i++;
		}
		count = count + ft_pb(stackA, stackB);
		i = 0;
		while (i < stackA->d_c)
		{
			count = count + ft_rrb(stackB);
			i++;
		}
		return (count);
	}
	else
	{
		count = ft_rra(stackA);
		while (i < stackA->d_c)
		{
			count = count + ft_rrb(stackB);
			i++;
		}
		count = count + ft_pb(stackA, stackB);
		i = 0;
		while (i <= stackA->d_c)
		{
			count = count + ft_rb(stackB);
			i++;
		}
		return (count);
	}
}

int	ft_da_smaller(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (stackA->a > stackB->midpoint)
	{
		while (i < stackA->d_a)
		{
			count = count + ft_rb(stackB);
			i++;
		}
		count = count + ft_pb(stackA, stackB);
		i = 0;
		while (i < stackA->d_a)
		{
			count = count + ft_rrb(stackB);
			i++;
		}
		return (count);
	}
	else
	{
		while (i < stackA->d_a)
		{
			count = count + ft_rrb(stackB);
			i++;
		}
		count = count + ft_pb(stackA, stackB);
		i = 0;
		while (i <= stackA->d_a)
		{
			count = count +ft_rb(stackB);
			i++;
		}
		return (count);
	}
}
