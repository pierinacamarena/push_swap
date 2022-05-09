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

int	first_three(t_program *p)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 3)
	{	
		count = count + choose_push(p, p->chunking.chunks);
		i++;
	}
	count = count + ft_sort_three_reverse(p);
	return (count);
}

int	top_push(t_program *p, t_hold num)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (k < num.moves)
	{
		if (num.location == 't')
			count = count + ft_ra(p);
		else if (num.location == 'b')
			count = count + ft_rra(p);
		k++;
	}
	count = count + ft_pb(p);
	return (count);
}

int	border_push(t_program *p, t_hold num)
{
	int	k;
	int	count;

	count = 0;
	if (num.number > p->stackb.x)
		count = top_push(p, num);
	else if (num.number < p->stackb.y)
	{
		k = 0;
		while (k < num.moves)
		{
			if (num.location == 't')
				count = count + ft_ra(p);
			else if (num.location == 'b')
				count = count + ft_rra(p);
			k++;
		}
		count = count + ft_pb(p);
		count = count + ft_rb(p);
	}
	return (count);
}

int	middle_push(t_program *p, t_hold num)
{
	int	d;
	int	k;
	int	j;
	int	count;

	d = distance(*p, num);
	k = 0;
	while (k < num.moves)
	{
		if (num.location == 't')
			count = count + ft_ra(p);
		else if (num.location == 'b')
			count = count + ft_rra(p);
		k++;
	}
	count = middle_helper(p, num);
	return (count);
}

int	first_chunk(t_program *p)
{
	t_hold	num;
	int		i;
	int		count;

	count = first_three(p);
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
	return (count);
}
