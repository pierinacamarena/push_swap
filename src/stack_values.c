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

void	ft_val_updta(t_stack *stacka)
{
	int	end_a;
	int	midpoint;

	end_a = stacka->size - 1;
	if (stacka->size % 2 == 0)
		midpoint = stacka->size / 2;
	else
		midpoint = end_a / 2;
	stacka->a = stacka->array[0];
	stacka->b = stacka->array[1];
	stacka->c = stacka->array[end_a];
	stacka->x = stacka->array[0];
	stacka->y = stacka->array[end_a];
	stacka->midpoint = stacka->array[midpoint];
}

void	ft_val_updtb(t_stack *stackb)
{
	int	end_b;
	int	midpoint;

	end_b = stackb->size - 1;
	if (stackb->size % 2 == 0)
		midpoint = stackb->size / 2;
	else
		midpoint = end_b / 2;
	stackb->a = stackb->array[0];
	stackb->b = stackb->array[1];
	stackb->c = stackb->array[end_b];
	stackb->x = stackb->array[0];
	stackb->y = stackb->array[end_b];
	stackb->midpoint = stackb->array[midpoint];
}

void	ft_distance(t_stack *stacka, t_stack *stackb)
{
	ft_da(stacka, stackb);
	ft_db(stacka, stackb);
	ft_dc(stacka, stackb);
}

void	ft_da(t_stack *stacka, t_stack *stackb)
{
	int	d;
	int	i;

	i = 0;
	if (stacka->a > stackb->midpoint)
	{
		while (stacka->a < stackb->array[i])
			i++;
		stacka->d_a = i;
	}
	else
	{
		i = 0;
		d = stackb->size - 1;
		while (stacka->a > stackb->array[d])
		{
			i++;
			d--;
		}
		stacka->d_a = i;
	}
}

void	ft_db(t_stack *stacka, t_stack *stackb)
{
	int	d;
	int	i;

	i = 0;
	if (stacka->b > stackb->midpoint)
	{
		while (stacka->b < stackb->array[i])
			i++;
		stacka->d_b = i;
	}
	else
	{
		i = 0;
		d = stackb->size - 1;
		while (stacka->b > stackb->array[d])
		{
			d--;
			i++;
		}
		stacka->d_b = i;
	}
}

void	ft_dc(t_stack *stacka, t_stack *stackb)
{
	int	d;
	int	i;

	i = 0;
	if (stacka->c > stackb->midpoint)
	{
		while (stacka->c < stackb->array[i])
			i++;
		stacka->d_c = i;
	}
	else
	{
		i = 0;
		d = stackb->size - 1;
		while (stacka->c > stackb->array[d])
		{
			d--;
			i++;
		}
		stacka->d_c = i;
	}
}
