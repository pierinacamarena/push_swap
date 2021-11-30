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

int	ft_sort_stack(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stacka->size == 2)
		count = count + ft_sa(stacka, stackb, printer);
	if (stacka->size == 3)
		count = count + ft_sort_three(stacka, stackb, printer);
	else if ((stackb->size == 3) && (!ft_check_sorted_reverse(*stackb)))
		count = count + ft_sort_three_reverse(stackb, stacka, printer);
	else if (stacka->size > 3 && stacka->size <= 5)
		count = count + ft_sort_inverse(stacka, stackb, printer);
	else if (stacka->size > 5)
		count = count + ft_sort_main_algo(stacka, stackb, printer);
	return (count);
}

int	ft_sort_main_algo(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	j;
	int	i;
	int	count;

	count = 0;
	count = count + ft_pb(stacka, stackb, printer);
	count = count + ft_pb(stacka, stackb, printer);
	count = count + ft_pb(stacka, stackb, printer);
	count = count + ft_sort_three_reverse(stackb, stacka, printer);
	j = 3;
	while (j < stackb->max_size && stacka->size >= 3)
	{
		if ((stacka->a > stackb->x || stacka->a < stackb->y) \
				|| (stacka->b > stackb->x || stacka->b < stackb->y) \
				|| (stacka->c > stackb->x || stacka->c < stackb->y))
		{
			if (stacka->a > stackb->x || stacka->a < stackb->y)
				count = count + ft_top_stack_a(stacka, stackb, printer);
			else if (stacka->b > stackb->x || stacka->b < stackb->y)
				count = count + ft_top_stack_b(stacka, stackb, printer);
			else if (stacka->c > stackb->x || stacka->c < stackb->y)
				count = count + ft_top_stack_c(stacka, stackb, printer);
			j++;
		}
		else if ((stacka->a < stackb->x && stacka->a > stackb->y) \
				&& (stacka->b < stackb->x && stacka->b > stackb->y) \
				&& (stacka->c < stackb->x && stacka->c > stackb->y))
		{
			ft_distance(stacka, stackb);
			if ((stacka->d_a - 1 <= stacka->d_b) \
					&& (stacka->d_a - 1 <= stacka->d_c))
			{
				count = count + ft_da_smaller(stacka, stackb, printer);
				j++;
			}
			else
			{
				if (stacka->d_b < stacka->d_c)
					count = count + ft_db_smaller(stacka, stackb, printer);
				else if (stacka->d_c < stacka->d_b)
					count = count + ft_dc_smaller(stacka, stackb, printer);
				else if (stacka->d_b == stacka->d_c)
					count = count + ft_db_smaller(stacka, stackb, printer);
				j++;
			}
		}
	}
	if (stacka->size == 2)
		count = count + ft_base_case_two(stacka, stackb, printer);
	if (stacka->size == 1)
		count = count + ft_base_case_one(stacka, stackb, printer);
	if (stackb->size == stackb->max_size)
	{
		i = 0;
		while (i < stackb->max_size)
		{
			count = count + ft_pa(stacka, stackb, printer);
			i++;
		}
	}
	return (count);
}

int	ft_sort_three(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	a;
	int	b;
	int	c;
	int	count;

	a = stacka->array[0];
	b = stacka->array[1];
	c = stacka->array[2];
	count = 0;
	if ((a < c) && (c < b))
	{
		count = count + ft_rra(stacka, stackb, printer);
		count = count + ft_sa(stacka, stackb, printer);
	}
	else if ((b < a) && (a < c))
		count = count + ft_sa(stacka, stackb, printer);
	else if ((c < a) && (a < b))
		count = count + ft_rra(stacka, stackb, printer);
	else if ((b < c) && (c < a))
		count = count + ft_ra(stacka, stackb, printer);
	else if ((c < b) && (b < a))
	{
		count = count + ft_ra(stacka, stackb, printer);
		count = count + ft_sa(stacka, stackb, printer);
	}
	return (count);
}

int	ft_sort_three_reverse(t_stack *stackb, t_stack *stacka, t_info *printer)
{
	int	a;
	int	b;
	int	c;
	int	count;

	a = stackb->array[0];
	b = stackb->array[1];
	c = stackb->array[2];
	count = 0;
	if ((a < b) && (b < c))
	{
		count = count + ft_rb(stackb, stacka, printer);
		count = count + ft_sb(stackb, stacka, printer);
	}
	else if ((a < c) && (c < b))
		count = count + ft_rb(stackb, stacka, printer);
	else if ((b < a) && (a < c))
		count = count + ft_rrb(stackb, stacka, printer);
	else if ((c < a) && (a < b))
		count = count + ft_sb(stackb, stacka, printer);
	else if ((b < c) && (c < a))
	{
		count = count + ft_rrb(stackb, stacka, printer);
		count = count + ft_sb(stackb, stacka, printer);
	}
	return (count);
}