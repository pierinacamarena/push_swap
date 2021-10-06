/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:09:56 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:20:48 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sort_inverse(t_stack *stackA, t_stack *stackB, int n)
{
	int	j;
	int count;

	count = 0;
	while (n > 3)
	{
	    count = count + ft_pb(stackA, stackB);
	    n--;
	}
	count = count + ft_sort_three(stackA);
	j = 3;
	while (j < stackA->max_size && stackB->size >= 3)
	{
		if ((stackB->a < stackA->x || stackB->a > stackA->y) \
				|| (stackB->b < stackA->x || stackB->b > stackA->y) \
				|| (stackB->c < stackA->x || stackB->c > stackA->y))
		{
			if (stackB->a < stackA->x || stackB->a > stackA->y)
				count = count + reverse_top_stack_a(stackA, stackB);
			else if (stackB->b < stackA->x || stackB->b > stackA->y)
				count = count + reverse_top_stack_b(stackA, stackB);
			else if (stackB->c < stackA->x || stackB->c > stackA->y)
				count = count + reverse_top_stack_c(stackA, stackB);
			j++;
		}
		else if ((stackB->a > stackA->x && stackB->a < stackA->y) \
				&& (stackB->b > stackA->x && stackB->b < stackA->y) \
				&& (stackB->c > stackA->x && stackB->c < stackA->y))
		{
			ft_distance_reverse(stackA, stackB);
			if ((stackB->d_a - 1 <= stackB->d_b)\
					&& (stackB->d_a - 1 <= stackB->d_c))
			{
				count = count + rda_smaller(stackA, stackB);
				j++;
			}
			else
			{
				if (stackB->d_b < stackB->d_a - 1)
					count = count + rdb_smaller(stackA, stackB);
				else if (stackB->d_c < stackB->d_a - 1)
					count = count + rdc_smaller(stackA, stackB);
				j++;
			}
		}
	}
	if (stackB->size == 2)
		count = count + ft_rbase_case_two(stackA, stackB);
	if (stackB->size == 1)
		count = count + ft_rbase_case_one(stackA, stackB);
	return (count);
}
