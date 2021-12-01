/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_da_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	if (stacka->a > stackb->midpoint)
	{
		count = da_more_midpoint(stacka, stackb, printer);
		return (count);
	}
	else
	{
		count = dc_less_midpoint(stacka, stackb, printer);
		return (count);
	}
}

int	ft_db_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	if (stacka->b > stackb->midpoint)
	{
		count = db_more_midpoint(stacka, stackb, printer);
		return (count);
	}
	else
	{
		count = db_less_midpoint(stacka, stackb, printer);
		return (count);
	}
}

int	ft_dc_smaller(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	if (stacka->c > stackb->midpoint)
	{
		count = dc_more_midpoint(stacka, stackb, printer);
		return (count);
	}
	else
	{
		count = dc_less_midpoint(stacka, stackb, printer);
		return (count);
	}
}
