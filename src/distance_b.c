/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:11:21 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:17:32 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_distance_reverse(t_stack *stackA, t_stack *stackB)
{
	ft_da(stackA, stackB);
	ft_db(stackA, stackB);
	ft_dc(stackA, stackB);
}

void	ft_rda(t_stack *stackA, t_stack *stackB)
{
	int	d;
	int	i;

	i = 0;
	if (stackB->a < stackA->midpoint)
	{
		while (stackB->a > stackB->array[i])
			i++;
		stackB->d_a = i;
	}
	else
	{
		i = 0;
		d = stackA->size - 1;
		while (stackB->a > stackA->array[d])
		{
			i++;
			d--;
		}
		stackB->d_a = i;
	}
}
void	ft_rdb(t_stack *stackA, t_stack *stackB)
{
	int	d;
	int	i;

	i = 0;
	if (stackB->b < stackA->midpoint)
	{
		while (stackB->b > stackA->array[i])
			i++;
		stackB->d_b = i;
	}
	else
	{
		i = 0;
		d = stackA->size - 1;
		while (stackA->b < stackB->array[d])
		{
			d--;
			i++;
		}
		stackB->d_b = i;
	}
}

void	ft_rdc(t_stack *stackA, t_stack *stackB)
{
	int	d;
	int	i;

	i = 0;
	if (stackB->c < stackA->midpoint)
	{
		while (stackB->c > stackA->array[i])
			i++;
		stackB->d_c = i;
	}
	else
	{
		i = 0;
		d = stackA->size - 1;
		while (stackB->c < stackA->array[d])
		{
			d--;
			i++;
		}
		stackB->d_c = i;
	}
}
