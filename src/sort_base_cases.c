/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:47:01 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:14:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

int	ft_base_case_two(t_stack *stackA, t_stack *stackB)
{
	int	count;

	count = 0;
	if ((stackA->a > stackB->x || stackA->a < stackB->y) \
			|| (stackA->b > stackB->x || stackA->b < stackB->y))
	{
		if (stackA->a > stackB->x || stackA->a < stackB->y)
		{
			 count = ft_top_stack_a(stackA, stackB);
		}
		else if (stackA->b > stackB->x || stackA->b < stackB->y)
		{
			count = ft_top_stack_b(stackA, stackB);
		}
	}
	else if ((stackA->a < stackB->x && stackA->a > stackB->y) \
			&& (stackA->b < stackB->x) && (stackA->b > stackA->y))
	{
		ft_distance(stackA, stackB);
		if (stackA->d_a - 1 <= stackA->d_b)
		{
			count = ft_da_smaller(stackA, stackB);
		}
		else if (stackA->d_b < stackA->d_a -1)
		{
			count = ft_db_smaller(stackA, stackB);
		}
	}
	return (count);
}

int	ft_base_case_one(t_stack *stackA, t_stack *stackB)
{
	int	count;

	count = 0;
	if (stackA->a > stackB->x || stackA->a < stackB->y)
	{
		count= ft_top_stack_a(stackA, stackB);
	}
	else if (stackA->a < stackB->x && stackA->a > stackB->y)
	{
		ft_distance(stackA, stackB);
		count =ft_da_smaller(stackA, stackB);
	}
	return (count);
}

int	ft_rbase_case_two(t_stack *stackA, t_stack *stackB)
{
	int	count;

	count = 0;
	if ((stackB->a < stackA->x || stackB->a > stackA->y) \
			|| (stackB->b > stackA->x || stackB->b < stackA->y))
	{
		if (stackB->a < stackA->x || stackB->a > stackA->y)
		{
			 count = reverse_top_stack_a(stackA, stackB);
		}
		else if (stackB->b < stackA->x || stackB->b > stackA->y)
		{
			count = reverse_top_stack_b(stackA, stackB);
		}
	}
	else if ((stackB->a > stackA->x && stackB->a < stackA->y) \
			&& (stackB->b > stackA->x) && (stackB->b < stackA->y))
	{
		ft_distance_reverse(stackA, stackB);
		printf("the value of the distances are da:%d and db:%d\n", stackB->d_a, stackB->d_b);
		if (stackB->d_a - 1 <= stackB->d_b)
		{
			count = rda_smaller(stackA, stackB);
		}
		else if (stackB->d_b < stackB->d_a -1)
		{
			count = rdb_smaller(stackA, stackB);
		}
	}
	return (count);
}

int	ft_rbase_case_one(t_stack *stackA, t_stack *stackB)
{
	int	count;

	count = 0;
	if (stackB->a < stackA->x || stackB->a > stackA->y)
	{
		count = + reverse_top_stack_a(stackA, stackB);
	}
	else if (stackB->a > stackA->x && stackB->a < stackA->y)
	{
		ft_distance_reverse(stackA, stackB);
		printf("the value of the distances are da:%d\n", stackB->d_a);
		count = count + rda_smaller(stackA, stackB);
	}
	return (count);
}
