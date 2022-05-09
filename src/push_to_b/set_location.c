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

void	loc_helper(t_program *p, t_hold *num)
{
	int	k;
	int	i;
	int	moves_left;

	k = 0;
	i = 0;
	if (num->distance == num->moves)
	{
		while (k++ < num->moves)
			ft_rr(p);
	}
	else if (num->distance < num->moves)
	{
		while (k++ < num->distance)
			ft_rr(p);
		moves_left = num->moves - num->distance;
		while (i++ < moves_left)
			ft_ra(p);
	}
}

void	second_help(t_program *p, t_hold *num)
{
	int	i;
	int	k;
	int	moves_left;

	i = 0;
	k = 0;
	while (k++ < num->moves)
		ft_rra(p);
	while (i++ < num->distance)
		ft_rb(p);
}

void	loc_b_helper(t_program *p, t_hold *num)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (k++ < num->moves)
		ft_rra(p);
	while (i++ < num->distance)
		ft_rb(p);
}

void	set_chunk_location(t_program *p, t_hold *num)
{
	int	i;
	int	k;
	int	moves_left;

	i = 0;
	k = 0;
	num->distance = distance(*p, *num);
	if (num->location == 't')
	{
		if (num->distance > num->moves)
		{
			while (k++ < num->moves)
				ft_rr(p);
			moves_left = num->distance - num->moves;
			while (i++ < moves_left)
				ft_rb(p);
		}
		else
			loc_helper(p, num);
	}
	else if (num->location == 'b')
		loc_b_helper(p, num);
}

void	set_location_simple(t_program *p, t_hold num)
{
	int	k;

	k = 0;
	if (num.location == 't')
	{
		while (k++ < num.moves)
			ft_ra(p);
	}
	else if (num.location == 'b')
	{
		while (k++ < num.moves)
			ft_rra(p);
	}
}
