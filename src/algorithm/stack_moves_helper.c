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

void	ft_pa_helper(t_program *p)
{
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 1;
	end = p->stackb.size - 1;
	while (i < end)
	{
		p->stackb.array[i] = p->stackb.array[j];
		i++;
		j++;
	}
}

void	ft_pb_helper(t_program *p)
{
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 1;
	end = p->stacka.size - 1;
	while (i < end)
	{
		p->stacka.array[i] = p->stacka.array[j];
		i++;
		j++;
	}
}
