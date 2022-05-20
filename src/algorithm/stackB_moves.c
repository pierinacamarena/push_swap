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
void	ft_sb(t_program *p)
{
	int	temp;

	temp = p->stackb.array[0];
	p->stackb.array[0] = p->stackb.array[1];
	p->stackb.array[1] = temp;
	ft_val_updtb(p);
	p->printer.count = p->printer.count + 1;
	update_printer(p, "sb");
	insert_end(p->moves, "sb", p->printer.count);

}

/**
 * 	Rotates down, the top number of stackB becomes the last number and all the
 *	rest move one position upwards
 **/

void	ft_rb(t_program *p)
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
	p->printer.count = p->printer.count + 1;
	update_printer(p, "rb");
	insert_end(p->moves, "rb", p->printer.count);

}

/**
 * Reverse rotates stackB, the last number becomes first, and all other numbers
 * move one position downwards
 **/

void	ft_rrb(t_program *p)
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
	p->printer.count = p->printer.count + 1;
	update_printer(p, "rrb");
	insert_end(p->moves, "rrb", p->printer.count);
}

/**
 *Function that pushes the top element of stackA to the top of stackB
 **/

void	ft_pb(t_program *p)
{
	int	i;
	int	temp;
	int	increase;

	i = 0;
	temp = p->stacka.array[0];
	ft_pb_helper(p);
	p->stacka.size--;
	increase = p->stacka.max_size - p->stacka.size;
	i = p->stackb.size;
	while (i > 0 && i < increase)
	{
		p->stackb.array[i] = p->stackb.array[i - 1];
		i--;
	}
	p->stackb.array[0] = temp;
	p->stackb.size++;
	ft_val_updta(p);
	ft_val_updtb(p);
	p->printer.count = p->printer.count + 1;
	update_printer(p, "pb");
	insert_end(p->moves, "pb", p->printer.count);

}
