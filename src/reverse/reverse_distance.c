/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:11:21 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:17:32 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_distance_reverse(t_program *p)
{
	ft_rda(p);
	ft_rdb(p);
	ft_rdc(p);
}

void	ft_rda(t_program *p)
{
	int	d;
	int	i;

	i = 0;
	if (p->stackb.a < p->stacka.midpoint)
	{
		while (p->stackb.a > p->stacka.array[i] && \
				p->stacka.array[i] != p->stacka.midpoint)
			i++;
		p->stackb.d_a = i;
	}
	else if (p->stackb.a > p->stacka.midpoint)
	{
		i = 0;
		d = p->stacka.size - 1;
		while (p->stackb.a < p->stacka.array[d])
		{
			i++;
			d--;
		}
		p->stackb.d_a = i;
	}
}

void	ft_rdb(t_program *p)
{
	int	d;
	int	i;

	i = 0;
	if (p->stackb.b < p->stacka.midpoint)
	{
		while (p->stackb.b > p->stacka.array[i])
			i++;
		p->stackb.d_b = i;
	}
	else if (p->stackb.b > p->stacka.midpoint)
	{
		i = 0;
		d = p->stacka.size - 1;
		while (p->stackb.b < p->stacka.array[d])
		{
			d--;
			i++;
		}
		p->stackb.d_b = i;
	}
}

void	ft_rdc(t_program *p)
{
	int	d;
	int	i;

	i = 0;
	if (p->stackb.c < p->stacka.midpoint)
	{
		while (p->stackb.c > p->stacka.array[i])
			i++;
		p->stackb.d_c = i;
	}
	else if (p->stackb.c > p->stacka.midpoint)
	{
		i = 0;
		d = p->stacka.size - 1;
		while (p->stackb.c < p->stacka.array[d])
		{
			d--;
			i++;
		}
		p->stackb.d_c = i;
	}
}
