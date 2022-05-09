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
	int	count;
	int	exp_stackbsize;

	exp_stackbsize = expected_stackbsize(p->chunking);
	count = 0;
	if (next_hold->number > p->stackb.x && (p->stackb.size < exp_stackbsize))
	{
		count = count + set_location_simple(p, *next_hold);
		count = count + ft_pb(p);
	}
	else if (next_hold->number < p->stackb.x \
			&& (p->stackb.size < exp_stackbsize))
	{
		count = count + set_chunk_location(p, next_hold);
		count = count + ft_pb(p);
		*complete_distance = *complete_distance + next_hold->distance;
	}
	else if (p->stackb.size == exp_stackbsize)
		return (count);
	return (count);
}

int	rrb_helper(t_program *p, t_hold *num, int *complete_distance)
{
	t_hold	next_hold;
	int		count;
	int		exp_stackbsize;

	count = 0;
	exp_stackbsize = expected_stackbsize(p->chunking);
	next_hold = choose_number(p, p->chunking.chunks[p->chunking.current_chunk]);
	next_hold.distance = optim_distance(*p, next_hold);
	while (next_hold.number < p->stackb.y)
	{
		count = count + opt(p, num, &next_hold, complete_distance);
		if (p->stackb.size < exp_stackbsize)
		{
			next_hold = choose_number(p, \
					p->chunking.chunks[p->chunking.current_chunk]);
			next_hold.distance = optim_distance(*p, next_hold);
		}
		else if (p->stackb.size == exp_stackbsize)
			break ;
	}
	return (count);
}

int	rrb_chunk(t_program *p, t_hold *num, int *complete_distance)
{
	t_hold	next_hold;
	int		count;
	int		exp_stackbsize;

	count = 0;
	exp_stackbsize = expected_stackbsize(p->chunking);
	next_hold = choose_number(p, p->chunking.chunks[p->chunking.current_chunk]);
	next_hold.distance = optim_distance(*p, next_hold);
	if ((next_hold.number < p->stackb.y) && (p->stackb.size < exp_stackbsize))
		count = count + rrb_helper(p, num, complete_distance);
	else if (p->stackb.size == exp_stackbsize && *complete_distance > 0)
	{
		count = count + rrb_helper_extra(p, complete_distance);
		return (count);
	}
	else if (p->stackb.size == exp_stackbsize && *complete_distance == 0)
		return (count);
	else
	{
		count = count + ft_rrb(p);
		*complete_distance = *complete_distance - 1;
	}
	return (count);
}

int	solve_intermediate(t_program *p, t_hold *num)
{
	int	j;
	int	count;
	int	distance_complete;

	j = 0;
	count = 0;
	distance_complete = num->distance;
	while (distance_complete > 0)
	{
		count = count + set_chunk_location(p, num);
		count = count + ft_pb(p);
		while (distance_complete > 0)
		{
			count = count + rrb_chunk(p, num, &distance_complete);
			j++;
		}
	}
	return (count);
}

int	chunk_solver(t_program *p)
{
	int		i;
	int		count;
	int		exp_stackbsize;
	t_hold	num;

	i = 0;
	count = 0;
	exp_stackbsize = expected_stackbsize(p->chunking);
	num = init_hold();
	while (p->stackb.size < exp_stackbsize)
	{
		num = choose_number(p, p->chunking.chunks[p->chunking.current_chunk]);
		num.distance = distance(*p, num);
		if (num.number > p->stackb.x)
			count = count + smallest_push(p, num);
		else if (num.number < p->stackb.x && num.number > p->stackb.y)
		{
			count = count + solve_intermediate(p, &num);
		}
	}
	return (count);
}
