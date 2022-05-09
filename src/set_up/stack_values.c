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

#include "../../includes/push_swap.h"

void	ft_val_updta(t_program *p)
{
	int	end_a;
	int	midpoint;

	if (p->stacka.size > 0)
		end_a = p->stacka.size - 1;
	if (p->stacka.size % 2 == 0)
		midpoint = p->stacka.size / 2;
	else
		midpoint = end_a / 2;
	p->stacka.a = p->stacka.array[0];
	p->stacka.b = p->stacka.array[1];
	if (p->stacka.size > 0)
		p->stacka.c = p->stacka.array[end_a];
	p->stacka.x = p->stacka.array[0];
	if (p->stacka.size > 0)
		p->stacka.y = p->stacka.array[end_a];
	p->stacka.midpoint = p->stacka.array[midpoint];
}

void	ft_val_updtb(t_program *p)
{
	int	end_b;
	int	midpoint;

	if (p->stackb.size > 0)
		end_b = p->stackb.size - 1;
	if (p->stackb.size % 2 == 0)
		midpoint = p->stackb.size / 2;
	else
		midpoint = end_b / 2;
	p->stackb.a = p->stackb.array[0];
	p->stackb.b = p->stackb.array[1];
	if (p->stackb.size > 0)
		p->stackb.c = p->stackb.array[end_b];
	p->stackb.x = p->stackb.array[0];
	if (p->stackb.size > 0)
		p->stackb.y = p->stackb.array[end_b];
	p->stackb.midpoint = p->stackb.array[midpoint];
}
