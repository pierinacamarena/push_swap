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

int	ft_sa(t_program *p)
{
	int	temp;

	temp = p->stacka.array[0];
	p->stacka.array[0] = p->stacka.array[1];
	p->stacka.array[1] = temp;
	ft_val_updta(p);
	p->printer.count = p->printer.count + 1;
	update_printer(p, "sa");
	return (1);
}

/**
 *	Rotates down, the top number of stackA becomes the last number and all the
 *	rest move one position upwards
 **/

int	ft_ra(t_program *p)
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
	p->printer.count = p->printer.count + 1;
	update_printer(p, "ra");
	return (1);
}

/**
 * Reverse rotates stackA, the last number becomes first, and all other numbers
 * move one position downwards
 **/
int	ft_rra(t_program *p)
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
	p->printer.count = p->printer.count + 1;
	update_printer(p, "rra");
	return (1);
}

int	ft_pa(t_program *p)
{
	int	i;
	int	temp;
	int	increase;

	temp = p->stackb.array[0];
	ft_pa_helper(p);
	p->stackb.size--;
	increase = p->stackb.max_size - p->stackb.size;
	i = p->stacka.size;
	while (i > 0 && i < increase)
	{
		p->stacka.array[i] = p->stacka.array[i -1];
		i--;
	}
	p->stacka.array[0] = temp;
	p->stacka.size++;
	ft_val_updta(p);
	ft_val_updtb(p);
	p->printer.count = p->printer.count + 1;
	update_printer(p, "pa");
	return (1);
}
