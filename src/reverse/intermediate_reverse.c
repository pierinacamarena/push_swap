/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:36:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rda_smaller(t_program *p)
{
	int	i;
	int	count;

	i = 0;
	if (p->stackb.a < p->stacka.midpoint)
		count = rda_less_midpoint(p);
	else
		count = rda_more_midpoint(p);
	return (count);
}

int	rdb_smaller(t_program *p)
{
	int	i;
	int	count;

	i = 0;
	if (p->stackb.b < p->stacka.midpoint)
		count = rdb_less_midpoint(p);
	else
		count = rdb_more_midpoint(p);
	return (count);
}

int	rdc_smaller(t_program *p)
{
	int	i;
	int	count;

	if (p->stackb.c < p->stacka.midpoint)
		count = rdc_less_midpoint(p);
	else
		count = rdc_more_midpoint(p);
	return (count);
}
