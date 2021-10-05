/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:38:16 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/04 19:45:33 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_val_updtA(t_stack *stackA)
{
	int	endA;

	endA = stackA->size - 1;
	stackA->a = stackA->array[0];
	stackA->b = stackA->array[1];
	stackA->c = stackA->array[endA];
}

void	ft_val_updtB(t_stack *stackB)
{
	int	endB;
	int	midpoint;

	endB= stackB->size - 1;
	if (stackB->size % 2 == 0)
		midpoint = stackB->size / 2;
	else
		midpoint = endB / 2;
	stackB->x = stackB->array[0];
	stackB->y = stackB->array[endB];
	stackB->midpoint = stackB->array[midpoint];
}

void	ft_distance(t_stack *stackA, t_stack *stackB)
{
	ft_da(stackA, stackB);
	ft_db(stackA, stackB);
	ft_dc(stackA, stackB);
}

void	ft_da(t_stack *stackA, t_stack *stackB)
{
	int	d;
	int	i;

	i = 0;
	if (stackA->a > stackB->midpoint)
	{
		while (stackA->a < stackB->array[i])
			i++;
		stackA->d_a = i;
	}
	else
	{
		i = 0;
		d = stackB->size - 1;
		while (stackA->a > stackB->array[d])
		{
			i++;
			d--;
		}
		stackA->d_a = i;
	}
}
void	ft_db(t_stack *stackA, t_stack *stackB)
{
	int	d;
	int	i;

	i = 0;
	if (stackA->b > stackB->midpoint)
	{
		while (stackA->b < stackB->array[i])
			i++;
		stackA->d_b = i;
	}
	else
	{
		i = 0;
		d = stackB->size - 1;
		while (stackA->b > stackB->array[d])
		{
			d--;
			i++;
		}
		stackA->d_b = i;
	}
}

void	ft_dc(t_stack *stackA, t_stack *stackB)
{
	int	d;
	int	i;

	i = 0;
	if (stackA->c > stackB->midpoint)
	{
		while (stackA->c < stackB->array[i])
			i++;
		stackA->d_c = i;
	}
	else
	{
		i = 0;
		d = stackB->size - 1;
		while (stackA->c > stackB->array[d])
		{
			d--;
			i++;
		}
		stackA->d_c = i;
	}
}
