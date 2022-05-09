/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/12/01 18:04:22 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	opt(t_program *p, t_hold *num, t_hold *next_hold, int *complete_distance)
{
	int	exp_stackbsize;

	exp_stackbsize = expected_stackbsize(p->chunking);
	if (next_hold->number > p->stackb.x && (p->stackb.size < exp_stackbsize))
	{
		set_location_simple(p, *next_hold);
		ft_pb(p);
	}
	else if (next_hold->number < p->stackb.x \
			&& (p->stackb.size < exp_stackbsize))
	{
		set_chunk_location(p, next_hold);
		ft_pb(p);
		*complete_distance = *complete_distance + next_hold->distance;
	}
	else if (p->stackb.size == exp_stackbsize)
		return (1);
	return (1);
}

void	rrb_helper(t_program *p, t_hold *num, int *complete_distance)
{
	t_hold	next_hold;
	int		exp_stackbsize;

	exp_stackbsize = expected_stackbsize(p->chunking);
	next_hold = choose_number(p, p->chunking.chunks[p->chunking.current_chunk]);
	next_hold.distance = optim_distance(*p, next_hold);
	while (next_hold.number < p->stackb.y)
	{
		opt(p, num, &next_hold, complete_distance);
		if (p->stackb.size < exp_stackbsize)
		{
			next_hold = choose_number(p, \
					p->chunking.chunks[p->chunking.current_chunk]);
			next_hold.distance = optim_distance(*p, next_hold);
		}
		else if (p->stackb.size == exp_stackbsize)
			break ;
	}
}

int	rrb_chunk(t_program *p, t_hold *num, int *complete_distance)
{
	t_hold	next_hold;
	int		exp_stackbsize;

	exp_stackbsize = expected_stackbsize(p->chunking);
	next_hold = choose_number(p, p->chunking.chunks[p->chunking.current_chunk]);
	next_hold.distance = optim_distance(*p, next_hold);
	if ((next_hold.number < p->stackb.y) && (p->stackb.size < exp_stackbsize))
		rrb_helper(p, num, complete_distance);
	else if (p->stackb.size == exp_stackbsize && *complete_distance > 0)
	{
		rrb_helper_extra(p, complete_distance);
		return (1);
	}
	else if (p->stackb.size == exp_stackbsize && *complete_distance == 0)
		return (1);
	else
	{
		ft_rrb(p);
		*complete_distance = *complete_distance - 1;
	}
	return (1);
}

void	solve_intermediate(t_program *p, t_hold *num)
{
	int	j;
	int	distance_complete;

	j = 0;
	distance_complete = num->distance;
	while (distance_complete > 0)
	{
		set_chunk_location(p, num);
		ft_pb(p);
		while (distance_complete > 0)
		{
			rrb_chunk(p, num, &distance_complete);
			j++;
		}
	}
}

void	chunk_solver(t_program *p)
{
	int		i;
	int		exp_stackbsize;
	t_hold	num;

	i = 0;
	exp_stackbsize = expected_stackbsize(p->chunking);
	num = init_hold();
	while (p->stackb.size < exp_stackbsize)
	{
		num = choose_number(p, p->chunking.chunks[p->chunking.current_chunk]);
		num.distance = distance(*p, num);
		if (num.number > p->stackb.x)
			smallest_push(p, num);
		else if (num.number < p->stackb.x && num.number > p->stackb.y)
		{
			solve_intermediate(p, &num);
		}
	}
}
