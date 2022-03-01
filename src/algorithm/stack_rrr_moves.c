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

int ft_rrr(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	count = count + ft_rra_rrr(stacka, stackb, printer);
	count = count + ft_rrb_rrr(stackb, stacka, printer);
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "rrr");
}

int	ft_rra_rrr(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	len = stacka->size;
	end = len - 1;
	i = end;
	j = end - 1;
	temp = stacka->array[end];
	while (i > 0)
	{
		stacka->array[i] = stacka->array[j];
		i--;
		j--;
	}
	stacka->array[0] = temp;
	ft_val_updta(stacka);
	return (1);
}

int	ft_rrb_rrr(t_stack *stackb, t_stack *stacka, t_info *printer)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	len = stackb->size;
	end = len - 1;
	i = end;
	j = end - 1;
	temp = stackb->array[end];
	while (i > 0)
	{
		stackb->array[i] = stackb->array[j];
		i--;
		j--;
	}
	stackb->array[0] = temp;
	ft_val_updtb(stackb);
	return (1);
}