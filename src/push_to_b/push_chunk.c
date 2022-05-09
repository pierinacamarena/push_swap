/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	solve_a(t_program *p)
{
	int	*arr;
	int	i;

	i = 0;
	arr = indexing(*p);
	p->chunking = split_choice(p->stacka, arr);
	p->chunking.current_chunk = i;
	first_chunk(p);
	while (i < p->chunking.splits)
	{
		p->chunking.current_chunk = i;
		chunk_solver(p);
		i++;
	}
	free(arr);
	free(p->chunking.chunks);
	free(p->chunking.chunk_size);
}
