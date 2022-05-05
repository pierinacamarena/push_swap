/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_location.c            v                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	loc_helper(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num)
{
	int	k;
	int	i;
	int	count;
	int	moves_left;

	count = 0;
	k = 0;
	i = 0;
	if (num->distance == num->moves)
	{
		while (k++ < num->moves)
			count = count + ft_rr(stacka, stackb, printer);
	}
	else if (num->distance < num->moves)
	{
		while (k++ < num->distance)
			count = count + ft_rr(stacka, stackb, printer);
		moves_left = num->moves - num->distance;
		while (i++ < moves_left)
			count = count + ft_ra(stacka, stackb, printer);
	}
	return (count);
}
int	second_help(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num)
{
	int	i;
	int	k;
	int	count;
	int	moves_left;

	i = 0;
	k = 0;
	count = 0;
	while (k++ < num->moves)
		count = count + ft_rra(stacka, stackb, printer);
	while (i++ < num->distance)
		count = count + ft_rb(stackb, stacka, printer);
	return (count);
}

int	set_chunk_location(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num)
{
	int	i;
	int	k;
	int	count;
	int	moves_left;

	i = 0;
	k = 0;
	count = 0;
	num->distance = distance(*stacka, *stackb, *num);
	if (num->location == 't')
	{
		if (num->distance > num->moves)
		{
			while (k++ < num->moves)
				count = count + ft_rr(stacka, stackb, printer);
			moves_left = num->distance - num->moves;
			while (i++ < moves_left)
				count = count + ft_rb(stackb, stacka, printer);
		}
		else
			count = loc_helper(stacka, stackb, printer, num);
	}
	else if (num->location == 'b')
	{
		while (k++ < num->moves)
			count = count + ft_rra(stacka, stackb, printer);
		while (i++ < num->distance)
			count = count + ft_rb(stackb, stacka, printer);
	}
	return (count);
}

int	set_location_simple(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	if (num.location == 't')
	{
		while (k++ < num.moves)
			count = count + ft_ra(stacka, stackb, printer);
	}
	else if (num.location == 'b')
	{
		while (k++ < num.moves)
			count = count + ft_rra(stacka, stackb, printer);
	}
}
