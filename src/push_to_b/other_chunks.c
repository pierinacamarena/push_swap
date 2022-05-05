/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/12/01 18:04:22 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	smallest_push(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num)
{
	int	count;
	int	k;

	k = 0;
	count = 0;
	while (k < num.moves)
	{
		if (num.location == 't')
			count = count + ft_ra(stacka, stackb, printer);
		else if (num.location == 'b')
			count = count + ft_rra(stacka, stackb, printer);
		k++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	return (count);
}
