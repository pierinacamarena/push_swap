/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stackb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:36:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb_stackb(t_program *p)
{
	ft_pb(p);
	ft_pb(p);
	ft_pb(p);
	ft_sort_three_reverse(p);
	if (p->stacka.a > p->stackb.midpoint)
	{
		ft_pb(p);
	}
	else if (p->stacka.a < p->stackb.midpoint)
	{
		ft_pb(p);
		ft_rb(p);
	}
}
