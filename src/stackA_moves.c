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

int	ft_sa(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	temp;
	temp = stackA->array[0];
	stackA->array[0] = stackA->array[1];
	stackA->array[1] = temp;
	ft_val_updtA(stackA);
	update_printer(*stackA, *stackB, printer, "sa");
	return (1);
}
/**
 *	Rotates down, the top number of stackA becomes the last number and all the
 *	rest move one position upwards
 **/

int	ft_ra(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	i = 0;
	j = 1;
	len = stackA->size;
	end = len - 1;
	temp = stackA->array[0];
	while(i < (len - 1))
	{
		stackA->array[i] = stackA->array[j];
		i++;
		j++;
	}
	stackA->array[end] = temp;
	ft_val_updtA(stackA);
	update_printer(*stackA, *stackB, printer, "ra");
	return (1);
}

/**
 * Reverse rotates stackA, the last number becomes first, and all other numbers
 * move one position downwards
 **/
int	ft_rra(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	temp;
	int i;
	int j;
	int	len;
	int	end;

	len = stackA->size;
	end = len - 1;
	i = end;
	j = end - 1;
	temp = stackA->array[end];
	while(i > 0)
	{
		stackA->array[i] = stackA->array[j];
		i--;
		j--;
	}
	stackA->array[0] = temp;
	ft_val_updtA(stackA);
	update_printer(*stackA, *stackB, printer, "rra");
	return (1);
}

int	ft_pa(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	i;
	int	j;
	int	temp;
	int	end;
	int	increase;

	i = 0;
	j = 1;
	end = stackB->size - 1;
	temp = stackB->array[0];
	while (i < end)
	{
		stackB->array[i] = stackB->array[j];
		i++;
		j++;
	}
	stackB->size--;
	increase = stackB->max_size - stackB->size;
	i = stackA->size;
	while(i > 0 && i < increase)
	{
		stackA->array[i] = stackA->array[i - 1];
		i--;
	}
	stackA->array[0] = temp;
	stackA->size++;
	ft_val_updtA(stackA);
	ft_val_updtB(stackB);
	update_printer(*stackA, *stackB, printer, "pa");
	return(1);
}
