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

int	loc_helper(t_program *p, t_hold *num)
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
			count = count + ft_rr(p);
	}
	else if (num->distance < num->moves)
	{
		while (k++ < num->distance)
			count = count + ft_rr(p);
		moves_left = num->moves - num->distance;
		while (i++ < moves_left)
			count = count + ft_ra(p);
	}
	return (count);
}

int	second_help(t_program *p, t_hold *num)
{
	int	i;
	int	k;
	int	count;
	int	moves_left;

	i = 0;
	k = 0;
	count = 0;
	while (k++ < num->moves)
		count = count + ft_rra(p);
	while (i++ < num->distance)
		count = count + ft_rb(p);
	return (count);
}

int	loc_b_helper(t_program *p, t_hold *num)
{
	int	k;
	int	i;
	int	count;

	i = 0;
	k = 0;
	count = 0;
	while (k++ < num->moves)
		count = count + ft_rra(p);
	while (i++ < num->distance)
		count = count + ft_rb(p);
	return (count);
}

int	set_chunk_location(t_program *p, t_hold *num)
{
	int	i;
	int	k;
	int	count;
	int	moves_left;

	i = 0;
	k = 0;
	count = 0;
	num->distance = distance(*p, *num);
	if (num->location == 't')
	{
		if (num->distance > num->moves)
		{
			while (k++ < num->moves)
				count = count + ft_rr(p);
			moves_left = num->distance - num->moves;
			while (i++ < moves_left)
				count = count + ft_rb(p);
		}
		else
			count = loc_helper(p, num);
	}
	else if (num->location == 'b')
		count = count + loc_b_helper(p, num);
	return (count);
}

int	set_location_simple(t_program *p, t_hold num)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	if (num.location == 't')
	{
		while (k++ < num.moves)
			count = count + ft_ra(p);
	}
	else if (num.location == 'b')
	{
		while (k++ < num.moves)
			count = count + ft_rra(p);
	}
}
