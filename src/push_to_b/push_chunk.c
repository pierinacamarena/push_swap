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

int	solve_a(t_program *p)
{
	int	*arr;
	int	count;
	int	i;

	i = 0;
	count = 0;
	arr = indexing(*p);
	p->chunking = split_choice(p->stacka, arr);
	p->chunking.current_chunk = i;
	count = count + first_chunk(p);
	while (i < p->chunking.splits)
	{
		p->chunking.current_chunk = i;
		count = count + chunk_solver(p);
		i++;
	}
	free(arr);
	free(p->chunking.chunks);
	free(p->chunking.chunk_size);
	return (count);
}
