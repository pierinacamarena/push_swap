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

void	support(t_program *p, t_hold num)
{
	int	j;
	int	d;

	j = 0;
	d = distance(*p, num);
	while (j < d)
	{
		ft_rrb(p);
		j++;
	}
	ft_pb(p);
	j = 0;
	while (j <= d)
	{
		ft_rb(p);
		j++;
	}
}

void	middle_helper(t_program *p, t_hold num)
{
	int	j;
	int	d;

	j = 0;
	d = distance(*p, num);
	if (num.number < p->stackb.midpoint)
		support(p, num);
	else if (num.number > p->stackb.midpoint)
	{
		while (j < d)
		{
			ft_rb(p);
			j++;
		}
		ft_pb(p);
		j = 0;
		while (j < d)
		{
			ft_rrb(p);
			j++;
		}
	}
}
