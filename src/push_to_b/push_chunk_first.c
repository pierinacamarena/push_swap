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

int	first_three(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 3)
	{	
		count = count + choose_push(stacka, stackb, printer, c.chunks);
		i++;
	}
	count = count + ft_sort_three_reverse(stackb, stacka, printer);
	return (count);
}

int	top_push(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (k < num.moves)
	{
		if (num.location == 't')
			count = count + ft_ra(stacka, stackb, printer);
		else if (num.location == 'b')
			count = count + ft_rra(stacka, stackb, printer);
		k++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	return (count);
}

int	border_push(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num)
{
	int	k;
	int	count;

	count = 0;
	if (num.number > stackb->x)
		count = top_push(stacka, stackb, printer, num);
	else if (num.number < stackb->y)
	{
		k = 0;
		while (k < num.moves)
		{
			if (num.location == 't')
				count = count + ft_ra(stacka, stackb, printer);
			else if (num.location == 'b')
				count = count + ft_rra(stacka, stackb, printer);
			k++;
		}
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_rb(stackb, stacka, printer);
	}
	return (count);
}

int	middle_push(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num)
{
	int	d;
	int	k;
	int	j;
	int	count;

	d = distance(*stacka, *stackb, num);
	k = 0;
	while (k < num.moves)
	{
		if (num.location == 't')
			count = count + ft_ra(stacka, stackb, printer);
		else if (num.location == 'b')
			count = count + ft_rra(stacka, stackb, printer);
		k++;
	}
	count = middle_helper(stacka, stackb, printer, num);
	return (count);
}

int	first_chunk(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk c)
{
	t_hold	num;
	int		i;
	int		count;

	count = first_three(stacka, stackb, printer, c);
	i = 0;
	while (i < (c.chunk_size[0] - 3))
	{
		num = choose_number(stacka, stackb, printer, c.chunks[0]);
		if (num.number > stackb->x || num.number < stackb->y)
			border_push(stacka, stackb, printer, num);
		else if (num.number < stackb->x && num.number > stackb->y)
			middle_push(stacka, stackb, printer, num);
		i++;
	}
	return (count);
}
