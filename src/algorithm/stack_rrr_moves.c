/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackA_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:56:51 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/05 18:40:40 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rrr(t_program *p)
{
	ft_rra_rrr(p);
	ft_rrb_rrr(p);
	p->printer.count = p->printer.count + 1;
	update_printer(p, "rrr");
	insert_end(p->moves, "rrr", p->printer.count);
}

void	ft_rra_rrr(t_program *p)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	len = p->stacka.size;
	end = len - 1;
	i = end;
	j = end - 1;
	temp = p->stacka.array[end];
	while (i > 0)
	{
		p->stacka.array[i] = p->stacka.array[j];
		i--;
		j--;
	}
	p->stacka.array[0] = temp;
	ft_val_updta(p);
}

void	ft_rrb_rrr(t_program *p)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	len = p->stackb.size;
	end = len - 1;
	i = end;
	j = end - 1;
	temp = p->stackb.array[end];
	while (i > 0)
	{
		p->stackb.array[i] = p->stackb.array[j];
		i--;
		j--;
	}
	p->stackb.array[0] = temp;
	ft_val_updtb(p);
}
