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

int ft_rr(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	count = count + ft_ra_rr(stacka, stackb, printer);
	count = count + ft_rb_rr(stackb, stacka, printer);
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "rr");
}

int	ft_ra_rr(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	i = 0;
	j = 1;
	len = stacka->size;
	end = len - 1;
	temp = stacka->array[0];
	
	while (i < (len - 1))
	{
		stacka->array[i] = stacka->array[j];
		i++;
		j++;
	}
	stacka->array[end] = temp;
	ft_val_updta(stacka);
	return (1);
}

int	ft_rb_rr(t_stack *stackb, t_stack *stacka, t_info *printer)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	i = 0;
	j = 1;
	len = stackb->size;
	end = len - 1;
	temp = stackb->array[0];

	while (i < (len - 1))
	{
		stackb->array[i] = stackb->array[j];
		i++;
		j++;
	}
	stackb->array[end] = temp;
	ft_val_updtb(stackb);
	return (1);
}