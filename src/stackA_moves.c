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

#include "../includes/push_swap.h"

/**
 *	Switches the top two numbers of stackA
 **/

int	ft_sa(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	temp;

	temp = stacka->array[0];
	stacka->array[0] = stacka->array[1];
	stacka->array[1] = temp;
	ft_val_updta(stacka);
	update_printer(*stacka, *stackb, printer, "sa");
	return (1);
}
/**
 *	Rotates down, the top number of stackA becomes the last number and all the
 *	rest move one position upwards
 **/

int	ft_ra(t_stack *stacka, t_stack *stackb, t_info *printer)
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
	update_printer(*stacka, *stackb, printer, "ra");
	return (1);
}

/**
 * Reverse rotates stackA, the last number becomes first, and all other numbers
 * move one position downwards
 **/
int	ft_rra(t_stack *stacka, t_stack *stackb, t_info *printer)
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
	update_printer(*stacka, *stackb, printer, "rra");
	return (1);
}

int	ft_pa(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	j;
	int	temp;
	int	end;
	int	increase;

	i = 0;
	j = 1;
	end = stackb->size - 1;
	temp = stackb->array[0];
	while (i < end)
	{
		stackb->array[i] = stackb->array[j];
		i++;
		j++;
	}
	stackb->size--;
	increase = stackb->max_size - stackb->size;
	i = stacka->size;
	while (i > 0 && i < increase)
	{
		stacka->array[i] = stacka->array[i - 1];
		i--;
	}
	stacka->array[0] = temp;
	stacka->size++;
	ft_val_updta(stacka);
	ft_val_updtb(stackb);
	update_printer(*stacka, *stackb, printer, "pa");
	return (1);
}