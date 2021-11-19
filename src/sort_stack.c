/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sort_stack(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	count;

	count = 0;
	if (stackA->size == 2)
		count = count + ft_sa(stackA, stackB, printer);
	if(stackA->size == 3)
		count = count + ft_sort_three(stackA, stackB, printer);
	else if ((stackB->size == 3) && (!ft_check_sorted_reverse(*stackB)))
		count = count + ft_sort_three_reverse(stackB, stackA, printer);
	else if (stackA->size > 3 && stackA->size <= 45)
	    count = count + ft_sort_inverse(stackA, stackB, printer);
	else if (stackA->size > 45)
	    count = count + ft_sort_main_algo(stackA, stackB, printer);
	return (count);
}

int	ft_sort_main_algo(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	j;
	int	i;
	int count;

	count = 0;
	count = count + ft_pb(stackA, stackB, printer);
	count = count + ft_pb(stackA, stackB, printer);
	count= count + ft_pb(stackA, stackB, printer);
	count = count + ft_sort_three_reverse(stackB, stackA, printer);
	j = 3;
	while (j < stackB->max_size && stackA->size >= 3)
	{
		if ((stackA->a > stackB->x || stackA->a < stackB->y) \
				|| (stackA->b > stackB->x || stackA->b < stackB->y) \
				|| (stackA->c > stackB->x || stackA->c < stackB->y))
		{
			if (stackA->a > stackB->x || stackA->a < stackB->y)
				count = count + ft_top_stack_a(stackA, stackB, printer);
			else if (stackA->b > stackB->x || stackA->b < stackB->y)
				count = count + ft_top_stack_b(stackA, stackB, printer);
			else if (stackA->c > stackB->x || stackA->c < stackB->y)
				count = count + ft_top_stack_c(stackA, stackB, printer);
			j++;
		}
		else if ((stackA->a < stackB->x && stackA->a > stackB->y) \
				&& (stackA->b < stackB->x && stackA->b > stackB->y) \
				&& (stackA->c <stackB->x && stackA->c > stackB->y))
		{
			ft_distance(stackA, stackB);
			if ((stackA->d_a - 1 <= stackA->d_b)\
					&& (stackA->d_a - 1 <= stackA->d_c))
			{
				count = count + ft_da_smaller(stackA, stackB, printer);
				j++;
			}
			else
			{
				if (stackA->d_b < stackA->d_a - 1)
					count = count + ft_db_smaller(stackA, stackB, printer);
				else if (stackA->d_c < stackA->d_a - 1)
					count = count + ft_dc_smaller(stackA, stackB, printer);
				j++;
			}
		}
	}
	if (stackA->size == 2)
		count = count + ft_base_case_two(stackA, stackB, printer);
	if (stackA->size == 1)
		count = count + ft_base_case_one(stackA, stackB, printer);
	if (stackB->size == stackB->max_size)
	{
		i = 0;
		while (i < stackB->max_size)
		{
			count = count + ft_pa(stackA, stackB, printer);
			i++;
		}
	}
	return (count);
}

int	ft_sort_three(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int a;
	int b;
	int c;
	int	count;

	a = stackA->array[0];
	b = stackA->array[1];
	c = stackA->array[2];
	count = 0;
	if ((a < c) && (c < b))
	{
		count = count + ft_rra(stackA, stackA, printer);
		count = count + ft_sa(stackA, stackB, printer);
	}
	else if ((b < a) && (a < c))
    	count = count + ft_sa(stackA, stackB, printer);
	else if ((c < a) && (a < b))
		count = count + ft_rra(stackA, stackB, printer);
	else if ((b < c) && (c < a))
		count = count + ft_ra(stackA, stackB, printer);
	else if ((c < b) && (b < a))
	{
		count = count + ft_ra(stackA, stackB, printer);
		count = count + ft_sa(stackA, stackB, printer);
	}
	return (count);
}

int	ft_sort_three_reverse(t_stack *stackB, t_stack *stackA, t_info *printer)
{
	int a;
	int b;
	int c;
	int	count;

	a = stackB->array[0];
	b = stackB->array[1];
	c = stackB->array[2];
	count = 0;
	if ((a < b) && (b < c))
	{
		count = count + ft_rb(stackB, stackA, printer);
		count = count + ft_sb(stackB, stackA, printer);
	}
	else if ((a < c) && (c < b))
		count = count + ft_rb(stackB, stackA, printer);
	else if ((b < a) && (a < c))
		count = count + ft_rrb(stackB, stackA, printer);
	else if ((c < a) && (a < b))
		count = count + ft_sb(stackB, stackA, printer);
	else if ((b < c) && (c < a))
	{
		count = count + ft_rrb(stackB, stackA, printer);
		count = count + ft_sb(stackB, stackA, printer);
	}
	return (count);
}
