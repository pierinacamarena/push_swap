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

void	smallest_push(t_program *p, t_hold num)
{
	int	k;

	k = 0;
	while (k < num.moves)
	{
		if (num.location == 't')
			ft_ra(p);
		else if (num.location == 'b')
			ft_rra(p);
		k++;
	}
	ft_pb(p);
}
