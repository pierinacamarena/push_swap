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

int	rda_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	if (stackb->a < stacka->midpoint)
		count = rda_less_midpoint(stacka, stackb, printer);
	else
		count = rda_more_midpoint(stacka, stackb, printer);
	return (count);
}

int	rdb_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	if (stackb->b < stacka->midpoint)
		count = rdb_less_midpoint(stacka, stackb, printer);
	else
		count = rdb_more_midpoint(stacka, stackb, printer);
	return (count);
}

int	rdc_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;

	if (stackb->c < stacka->midpoint)
		count = rdc_less_midpoint(stacka, stackb, printer);
	else
		count = rdc_more_midpoint(stacka, stackb, printer);
	return (count);
}
