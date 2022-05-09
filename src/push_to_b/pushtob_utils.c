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

int	distance(t_program p, t_hold num)
{
	int	distance;
	int	i;
	int	j;

	i = 0;
	j = p.stackb.size - 1;
	distance = 0;
	if (num.number > p.stackb.midpoint)
	{
		while (num.number < p.stackb.array[i])
			i++;
		distance = i;
	}
	else if (num.number < p.stackb.midpoint)
	{
		while (num.number > p.stackb.array[j])
		{
			i++;
			j--;
		}
		distance = i;
	}
	return (distance);
}

int	optim_distance(t_program p, t_hold num)
{
	int	distance;
	int	i;

	i = 0;
	while (num.number < p.stackb.array[i] && i < p.stackb.size)
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

void	rrb_helper_extra(t_program *p, int *complete_distance)
{
	while (*complete_distance > 0)
	{
		ft_rrb(p);
		*complete_distance = *complete_distance - 1;
	}
}
