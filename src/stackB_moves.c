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

#include "../includes/push_swap.h"

/**
 *	Switches the top two number of stackB
 **/
int	ft_sb(t_stack *stackB)
{
	int	temp;

	temp = stackB->array[0];
	stackB->array[0] = stackB->array[1];
	stackB->array[1] = temp;
	ft_val_updtB(stackB);
	ft_putstr("sb\n");
	return (1);
}

/**
 * 	Rotates down, the top number of stackB becomes the last number and all the
 *	rest move one position upwards
 **/

int	ft_rb(t_stack *stackB)
{
	int	temp;
	int	i;
	int	j;
	int	len;
	int	end;

	i = 0;
	j = 1;
	len = stackB->size;
	end = len - 1;
	temp = stackB->array[0];
	while(i < (len - 1))
	{
	stackB->array[i] = stackB->array[j];
	i++;
	j++;
	}
	stackB->array[end] = temp;
	ft_val_updtB(stackB);
	ft_putstr("rb\n");
	return (1);
}

/**
 * Reverse rotates stackB, the last number becomes first, and all other numbers
 * move one position downwards
 **/

int	ft_rrb(t_stack *stackB)
{
	int	temp;
	int i;
	int j;
	int	len;
	int	end;

	len = stackB->size;
	end = len - 1;
	i = end;
	j = end - 1;
	temp = stackB->array[end];
	while(i > 0)
	{
		stackB->array[i] = stackB->array[j];
		i--;
		j--;
	}
	stackB->array[0] = temp;
	ft_val_updtB(stackB);
	ft_putstr("rrb\n");
	return (1);
}

/**
 *Function that pushes the top element of stackA to the top of stackB
 **/

int	ft_pb(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	j;
	int	temp;
	int	end;
	int	increase;

	i = 0;
	j = 1;
	end = stackA->size - 1;
	temp = stackA->array[0];
	while (i < end)
	{
		stackA->array[i] = stackA->array[j];
		i++;
		j++;
	}
	stackA->size--;
	increase = stackA->max_size - stackA->size;
	i = stackB->size;
	while (i > 0 && i < increase)
	{
		stackB->array[i] = stackB->array[i-1];
		i--;
	}
	stackB->array[0] = temp;
	stackB->size++;
	ft_val_updtA(stackA);
	ft_val_updtB(stackB);
	ft_putstr("pb\n");
	return (1);
}
