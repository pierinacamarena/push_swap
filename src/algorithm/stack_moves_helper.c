/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:56:51 by pcamaren          #+#    #+#             */
/*   Updated: 2021/12/01 18:00:10 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pa_helper(t_stack *stacka, t_stack *stackb)
{
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 1;
	end = stackb->size - 1;
	while (i < end)
	{
		stackb->array[i][0] = stackb->array[j][0];
		stackb->array[i][1] = stackb->array[j][1];
		stackb->array[i][2] = stackb->array[j][2];
		i++;
		j++;
	}
}

void	ft_pb_helper(t_stack *stacka, t_stack *stackb)
{
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 1;
	end = stacka->size - 1;
	while (i < end)
	{
		stacka->array[i][0] = stacka->array[j][0];
		stacka->array[i][1] = stacka->array[j][1];
		stacka->array[i][2] = stacka->array[j][2];
		i++;
		j++;
	}
}
