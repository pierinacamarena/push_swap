/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:52:53 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/05 18:42:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**	Switches the top two number of stackB
 **/
int	ft_sb(t_stack *stackb, t_stack *stacka, t_info *printer)
{
	int	temp;

	temp = stackb->array[0];
	stackb->array[0] = stackb->array[1];
	stackb->array[1] = temp;
	ft_val_updtb(stackb);
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "sb");
	return (1);
}

/**
 * 	Rotates down, the top number of stackB becomes the last number and all the
 *	rest move one position upwards
 **/

int	ft_rb(t_stack *stackb, t_stack *stacka, t_info *printer)
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
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "rb");
	return (1);
}

/**
 * Reverse rotates stackB, the last number becomes first, and all other numbers
 * move one position downwards
 **/

int	ft_rrb(t_stack *stackb, t_stack *stacka, t_info *printer)
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
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "rrb");
	return (1);
}

/**
 *Function that pushes the top element of stackA to the top of stackB
 **/

int	ft_pb(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	temp;
	int	increase;

	i = 0;
	temp = stacka->array[0];
	ft_pb_helper(stacka, stackb);
	stacka->size--;
	increase = stacka->max_size - stacka->size;
	i = stackb->size;
	while (i > 0 && i < increase)
	{
		stackb->array[i] = stackb->array[i - 1];
		i--;
	}
	stackb->array[0] = temp;
	stackb->size++;
	ft_val_updta(stacka);
	ft_val_updtb(stackb);
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "pb");
	return (1);
}
