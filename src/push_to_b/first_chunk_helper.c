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

int	support(t_program *p, t_hold num)
{
	int	count;
	int	j;
	int	d;

	j = 0;
	d = distance(*p, num);
	count = 0;
	while (j < d)
	{
		count = count + ft_rrb(p);
		j++;
	}
	count = count + ft_pb(p);
	j = 0;
	while (j <= d)
	{
		count = count + ft_rb(p);
		j++;
	}
	return (count);
}

int	middle_helper(t_program *p, t_hold num)
{
	int	j;
	int	d;
	int	count;

	j = 0;
	d = distance(*p, num);
	count = 0;
	if (num.number < p->stackb.midpoint)
		count = support(p, num);
	else if (num.number > p->stackb.midpoint)
	{
		while (j < d)
		{
			count = count + ft_rb(p);
			j++;
		}
		count = count + ft_pb(p);
		j = 0;
		while (j < d)
		{
			count = count + ft_rrb(p);
			j++;
		}
	}
	return (count);
}
