/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtob_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	distance(t_stack stacka, t_stack stackb, t_hold num)
{
	int	distance;
	int	i;
	int	j;

	i = 0;
	j = stackb.size - 1;
	distance = 0;
	if (num.number > stackb.midpoint)
	{
		while (num.number < stackb.array[i])
			i++;
		distance = i;
	}
	else if (num.number < stackb.midpoint)
	{
		while (num.number > stackb.array[j])
		{
			i++;
			j--;
		}
		distance = i;
	}
	return (distance);
}

int	optim_distance(t_stack stacka, t_stack stackb, t_hold num)
{
	int	distance;
	int	i;
	int	j;

	i = 0;
	while (num.number < stackb.array[i])
		i++;
	distance = i;
	return (distance);
}

int	expected_stackbsize(t_chunk chunking)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (i <= chunking.current_chunk)
	{
		size = size + chunking.chunk_size[i];
		i++;
	}
	return (size);
}
