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

/**
 *	Switches the top two numbers of stackA
 **/

int	ft_sa(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	temp[3];

	temp[0] = stacka->array[0][0];
	temp[1] = stacka->array[0][1];
	temp[2] = stacka->array[0][2];
	stacka->array[0][0] = stacka->array[1][0];
	stacka->array[0][1] = stacka->array[1][1];
	stacka->array[0][2] = stacka->array[1][2];
	stacka->array[1][0] = temp[0];
	stacka->array[1][1] = temp[1];
	stacka->array[1][2] = temp[2];

	ft_val_updta(stacka);
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "sa");
	return (1);
}

/**
temp sa
**/

int	ft_temp_sa(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	temp[3];

	temp[0] = stacka->array[0][0];
	temp[1] = stacka->array[0][1];
	temp[2] = stacka->array[0][2];
	stacka->array[0][0] = stacka->array[1][0];
	stacka->array[0][1] = stacka->array[1][1];
	stacka->array[0][2] = stacka->array[1][2];
	stacka->array[1][0] = temp[0];
	stacka->array[1][1] = temp[1];
	stacka->array[1][2] = temp[2];

	ft_val_updta(stacka);
	update_printer(*stacka, *stackb, printer, "ts");
	return (1);
}
/**
 *	Rotates down, the top number of stackA becomes the last number and all the
 *	rest move one position upwards
 **/

int	ft_ra(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	temp[3];
	int	i;
	int	j;
	int	len;
	int	end;

	i = 0;
	j = 1;
	len = stacka->size;
	end = len - 1;
	temp[0] = stacka->array[0][0];
	temp[1] = stacka->array[0][1];
	temp[2] = stacka->array[0][2];
	
	while (i < (len - 1))
	{
		stacka->array[i][0] = stacka->array[j][0];
		stacka->array[i][1] = stacka->array[j][1];
		stacka->array[i][2] = stacka->array[j][2];
		i++;
		j++;
	}
	stacka->array[end][0] = temp[0];
	stacka->array[end][1] = temp[1];
	stacka->array[end][2] = temp[2];
	ft_val_updta(stacka);
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "ra");
	return (1);
}

/**
 * Reverse rotates stackA, the last number becomes first, and all other numbers
 * move one position downwards
 **/
int	ft_rra(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	temp[3];
	int	i;
	int	j;
	int	len;
	int	end;

	len = stacka->size;
	end = len - 1;
	i = end;
	j = end - 1;
	temp[0] = stacka->array[end][0];
	temp[1] = stacka->array[end][1];
	temp[2] = stacka->array[end][2];
	while (i > 0)
	{
		stacka->array[i][0]= stacka->array[j][0];
		stacka->array[i][1]= stacka->array[j][1];
		stacka->array[i][2]= stacka->array[j][2];
		i--;
		j--;
	}
	stacka->array[0][0] = temp[0];
	stacka->array[0][1] = temp[1];
	stacka->array[0][2] = temp[2];
	ft_val_updta(stacka);
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "rra");
	return (1);
}

int	ft_pa(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	temp[3];
	int	increase;

	temp[0] = stackb->array[0][0];
	temp[1] = stackb->array[0][1];
	temp[2] = stackb->array[0][2];
	ft_pa_helper(stacka, stackb);
	stackb->size--;
	increase = stackb->max_size - stackb->size;
	i = stacka->size;
	while (i > 0 && i < increase)
	{
		stacka->array[i][0] = stacka->array[i - 1][0];
		stacka->array[i][1] = stacka->array[i - 1][1];
		stacka->array[i][2] = stacka->array[i - 1][2];
		i--;
	}
	stacka->array[0][0] = temp[0];
	stacka->array[0][1] = temp[1];
	stacka->array[0][2] = temp[2];
	stacka->size++;
	ft_val_updta(stacka);
	ft_val_updtb(stackb);
	printer->count = printer->count + 1;
	update_printer(*stacka, *stackb, printer, "pa");
	return (1);
}
