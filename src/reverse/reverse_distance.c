/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:11:21 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:17:32 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_distance_reverse(t_stack *stacka, t_stack *stackb)
{
	ft_rda(stacka, stackb);
	ft_rdb(stacka, stackb);
	ft_rdc(stacka, stackb);
}

void	ft_rda(t_stack *stacka, t_stack *stackb)
{
	int	d;
	int	i;

	i = 0;
	if (stackb->a < stacka->midpoint)
	{
		while (stackb->a > stacka->array[i][0] && \
				stacka->array[i][0] != stacka->midpoint)
			i++;
		stackb->d_a = i;
	}
	else if (stackb->a > stacka->midpoint)
	{
		i = 0;
		d = stacka->size - 1;
		while (stackb->a < stacka->array[d][0])
		{
			i++;
			d--;
		}
		stackb->d_a = i;
	}
}

void	ft_rdb(t_stack *stacka, t_stack *stackb)
{
	int	d;
	int	i;

	i = 0;
	if (stackb->b < stacka->midpoint)
	{
		while (stackb->b > stacka->array[i][0])
			i++;
		stackb->d_b = i;
	}
	else if (stackb->b > stacka->midpoint)
	{
		i = 0;
		d = stacka->size - 1;
		while (stackb->b < stacka->array[d][0])
		{
			d--;
			i++;
		}
		stackb->d_b = i;
	}
}

void	ft_rdc(t_stack *stacka, t_stack *stackb)
{
	int	d;
	int	i;

	i = 0;
	if (stackb->c < stacka->midpoint)
	{
		while (stackb->c > stacka->array[i][0])
			i++;
		stackb->d_c = i;
	}
	else if (stackb->c > stacka->midpoint)
	{
		i = 0;
		d = stacka->size - 1;
		while (stackb->c < stacka->array[d][0])
		{
			d--;
			i++;
		}
		stackb->d_c = i;
	}
}
