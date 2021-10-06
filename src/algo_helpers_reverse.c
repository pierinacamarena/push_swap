/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:10:22 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:17:11 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		reverse_top_stack_a(t_stack *stackA, t_stack *stackB)
{
	int	a;
	int	x;
	int	y;
	int	count;

	a = stackB->a;
	x = stackA->x;
	y = stackA->y;
	count = 0;
	if (a < x)
	{
		count = count + ft_pa(stackA, stackB);
		return (count);
	}
	else if (a > y)
	{
		count = count + ft_pa(stackA, stackB);
		count = count + ft_ra(stackB);
		return (count);
	}
	return (count);
}

int	reverse_top_stack_b(t_stack *stackA, t_stack *stackB)
{
	int	b;
	int	x;
	int	y;
	int	count;

	b = stackB->b;
	x = stackA->x;
	y = stackA->y;
	count = 0;
	if (b < x)
	{
		count = count + ft_sb(stackA);
		count = count + ft_pa(stackA, stackB);
		return (count);
	}
	else if (b > y)
	{
		count = count + ft_sb(stackB);
		count = count + ft_pa(stackA, stackB);
		count = count + ft_ra(stackA);
		return(count);
	}
	return(count);
}

int	reverse_top_stack_c(t_stack *stackA, t_stack *stackB)
{
	int	c;
	int	x;
	int	y;
	int	count;

	c = stackB->c;
	x = stackA->x;
	y = stackA->y;
	count = 0;
	if (c < x)
	{
		count = count + ft_rrb(stackB);
		count = count + ft_pa(stackA, stackB);
		return (count);
	}
	else if (c > y)
	{
		count = count + ft_rrb(stackB);
		count = count + ft_pa(stackA, stackB);
		count = count + ft_ra(stackA);
		return (count);
	}
	return(count);
}

int	rdb_smaller(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	count;

	i = 0;
	if (stackB->b < stackA->midpoint)
	{
		count = ft_sb(stackB);
		while (i < stackB->d_b)
		{
			count = count + ft_ra(stackA);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		i = 0;
		while (i < stackB->d_b)
		{
			count = count + ft_rra(stackA);
			i++;
		}
		return (count);
	}
	else
	{
		count = ft_sb(stackB);
		while (i < stackB->d_b)
		{
			count = count + ft_rra(stackA);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		i = 0;
		while (i <= stackB->d_b)
		{
			count = count + ft_ra(stackA);
			i++;
		}
		return (count);
	}
}

int rdc_smaller(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	count;

	i = 0;
	if (stackB->c < stackA->midpoint)
	{
		count = ft_rra(stackA);
		while (i < stackB->d_c)
		{
			count = count + ft_ra(stackA);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		i = 0;
		while (i < stackB->d_c)
		{
			count = count + ft_rra(stackA);
			i++;
		}
		return (count);
	}
	else
	{
		count = ft_rra(stackA);
		while (i < stackB->d_c)
		{
			count = count + ft_rra(stackA);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		i = 0;
		while (i <= stackB->d_c)
		{
			count = count + ft_ra(stackA);
			i++;
		}
		return (count);
	}
}

int	rda_smaller(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (stackB->a < stackA->midpoint)
	{
		while (i < stackB->d_a)
		{
			count = count + ft_ra(stackA);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		i = 0;
		while (i < stackB->d_a)
		{
			count = count + ft_rra(stackA);
			i++;
		}
		return (count);
	}
	else
	{
		while (i < stackB->d_a)
		{
			count = count + ft_rra(stackA);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		i = 0;
		while (i <= stackB->d_a)
		{
			count = count +ft_ra(stackA);
			i++;
		}
		return (count);
	}
}
