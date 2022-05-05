/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_hold	same_moves(t_hold one, t_hold two)
{
	if (one.number < two.number)
	{
		one.location = 't';
		return (one);
	}
	else if (two.number < one.number)
	{
		two.location = 'b';
		return (two);
	}
}

t_hold	choose_number(t_stack *stacka, t_stack *stackb, t_info *printer, int chunk)
{
	t_hold	hold_one;
	t_hold	hold_two;
	t_hold	final_hold;
	int		count;

	hold_one = find_top_num(*stacka, chunk);
	hold_two = find_lower_num(*stacka, chunk);
	if (hold_one.moves < hold_two.moves)
	{
		hold_one.location = 't';
		return (hold_one);
	}
	else if (hold_two.moves < hold_one.moves)
	{
		hold_two.location = 'b';
		return (hold_two);
	}
	else
	{
		final_hold = same_moves(hold_one, hold_two);
		return (final_hold);
	}
}
