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

void	ft_rr(t_program *p)
{
	ft_ra_rr(p);
	ft_rb_rr(p);
	p->printer.count = p->printer.count + 1;
	update_printer(p, "rr");
}

void	ft_ra_rr(t_program *p)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	i = 0;
	j = 1;
	len = p->stacka.size;
	end = len - 1;
	temp = p->stacka.array[0];
	while (i < (len - 1))
	{
		p->stacka.array[i] = p->stacka.array[j];
		i++;
		j++;
	}
	p->stacka.array[end] = temp;
	ft_val_updta(p);
}

void	ft_rb_rr(t_program *p)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	i = 0;
	j = 1;
	len = p->stackb.size;
	end = len - 1;
	temp = p->stackb.array[0];
	while (i < (len - 1))
	{
		p->stackb.array[i] = p->stackb.array[j];
		i++;
		j++;
	}
	p->stackb.array[end] = temp;
	ft_val_updtb(p);
}
