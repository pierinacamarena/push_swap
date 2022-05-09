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

void	rda_smaller(t_program *p)
{
	int	i;

	i = 0;
	if (p->stackb.a < p->stacka.midpoint)
		rda_less_midpoint(p);
	else
		rda_more_midpoint(p);
}

void	rdb_smaller(t_program *p)
{
	int	i;

	i = 0;
	if (p->stackb.b < p->stacka.midpoint)
		rdb_less_midpoint(p);
	else
		rdb_more_midpoint(p);
}

void	rdc_smaller(t_program *p)
{
	int	i;

	if (p->stackb.c < p->stacka.midpoint)
		rdc_less_midpoint(p);
	else
		rdc_more_midpoint(p);
}
