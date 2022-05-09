/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:38:16 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/04 19:45:33 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
/*

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
}*/
