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

static void	first_three(t_program *p)
{
	int	i;

	i = 0;
	while (i < 3)
	{	
		choose_push(p, p->chunking.chunks);
		i++;
	}
	ft_sort_three_reverse(p);
}

static int	top_push(t_program *p, t_hold num)
{
	int	k;

	k = 0;
	while (k < num.moves)
	{
		if (num.location == 't')
			ft_ra(p);
		else if (num.location == 'b')
			ft_rra(p);
		k++;
	}
	ft_pb(p);
}

static int	border_push(t_program *p, t_hold num)
{
	int	k;

	if (num.number > p->stackb.x)
		top_push(p, num);
	else if (num.number < p->stackb.y)
	{
		k = 0;
		while (k < num.moves)
		{
			if (num.location == 't')
				ft_ra(p);
			else if (num.location == 'b')
				ft_rra(p);
			k++;
		}
		ft_pb(p);
		ft_rb(p);
	}
}

static void	middle_push(t_program *p, t_hold num)
{
	int	d;
	int	k;
	int	j;

	d = distance(*p, num);
	k = 0;
	while (k < num.moves)
	{
		if (num.location == 't')
			ft_ra(p);
		else if (num.location == 'b')
			ft_rra(p);
		k++;
	}
	middle_helper(p, num);
}

void	first_chunk(t_program *p)
{
	t_hold	num;
	int		i;

	first_three(p);
	i = 0;
	while (i < (p->chunking.chunk_size[0] - 3))
	{
		num = choose_number(p, p->chunking.chunks[0]);
		if (num.number > p->stackb.x || num.number < p->stackb.y)
			border_push(p, num);
		else if (num.number < p->stackb.x && num.number > p->stackb.y)
			middle_push(p, num);
		i++;
	}
}
