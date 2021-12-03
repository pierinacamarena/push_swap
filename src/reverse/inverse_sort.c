/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:36:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	sort_inverse_top(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	if (stackb->a < stacka->x || stackb->a > stacka->y)
		count = count + reverse_top_stack_a(stacka, stackb, printer);
	else if (stackb->b < stacka->x || stackb->b > stacka->y)
		count = count + reverse_top_stack_b(stacka, stackb, printer);
	else if (stackb->c < stacka->x || stackb->c > stacka->y)
		count = count + reverse_top_stack_c(stacka, stackb, printer);
	return (count);
}

int	sort_inverse_inter(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	ft_distance_reverse(stacka, stackb);
	if ((stackb->d_a - 1 <= stackb->d_b) \
			&& (stackb->d_a - 1 <= stackb->d_c))
		count = count + rda_smaller(stacka, stackb, printer);
	else
	{
		if (stackb->d_b < stackb->d_c)
			count = count + rdb_smaller(stacka, stackb, printer);
		else if (stackb->d_c < stackb->d_b)
			count = count + rdc_smaller(stacka, stackb, printer);
		else if (stackb->d_b == stackb->d_c)
			count = count + rdb_smaller(stacka, stackb, printer);
	}
	return (count);
}

int	sort_inverse_end(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->size == 2)
	{
		ft_val_updta(stacka);
		ft_val_updtb(stackb);
		count = count + ft_rbase_case_two(stacka, stackb, printer);
	}
	if (stackb->size == 1)
	{
		count = count + ft_rbase_case_one(stacka, stackb, printer);
	}
	return (0);
}

int	sort_inverse_initial(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;
	int	n;

	count = 0;
	n = stacka->size;
	while (n > 3)
	{
		count = count + ft_pb(stacka, stackb, printer);
		n--;
	}
	return (count);
}

int	ft_sort_inverse(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	j;
	int	count;

	count = 0;
	sort_inverse_initial(stacka, stackb, printer);
	count = count + ft_sort_three(stacka, stackb, printer);
	j = 3;
	while (j < stacka->max_size && stackb->size >= 3)
	{
		if ((stackb->a < stacka->x || stackb->a > stacka->y) \
				|| (stackb->b < stacka->x || stackb->b > stacka->y) \
				|| (stackb->c < stacka->x || stackb->c > stacka->y))
				count = count + sort_inverse_top(stacka, stackb, printer);
		else if ((stackb->a > stacka->x && stackb->a < stacka->y) \
				&& (stackb->b > stacka->x && stackb->b < stacka->y) \
				&& (stackb->c > stacka->x && stackb->c < stacka->y))
				count = count + sort_inverse_inter(stacka, stackb, printer);
		j++;
	}
	count = count + sort_inverse_end(stacka, stackb, printer);
	return (count);
}
