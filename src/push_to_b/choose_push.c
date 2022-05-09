/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_hold	find_top_num(t_program *p, int border)
{
	int		i;
	t_hold	hold_one;

	i = 0;
	hold_one = init_hold();
	while (i < p->stacka.size)
	{
		if (p->stacka.array[i] <= border)
		{
			hold_one.number = p->stacka.array[i];
			hold_one.moves = i;
			break ;
		}
		i++;
	}
	return (hold_one);
}

t_hold	find_lower_num(t_program *p, int border)
{
	int		i;
	int		j;
	t_hold	hold_two;

	hold_two = init_hold();
	i = p->stacka.size - 1;
	j = 1;
	while (i >= 0)
	{
		if (p->stacka.array[i] <= border)
		{
			hold_two.number = p->stacka.array[i];
			hold_two.moves = j;
			break ;
		}
		i--;
		j++;
	}
	return (hold_two);
}

void	choose_push_helper(t_program *p, t_hold one, t_hold two)
{
	int	i;

	i = 0;
	if (one.moves <= two.moves)
	{
		if (one.moves == 0)
			ft_pb(p);
		else if (one.moves == 1)
		{
			ft_sa(p);
			ft_pb(p);
		}
		else
		{
			while (i < one.moves)
			{
				ft_ra(p);
				i++;
			}
			ft_pb(p);
		}
	}
}

void	choose_push(t_program *p, int *chunks)
{
	t_hold	hold_one;
	t_hold	hold_two;
	int		i;

	i = 0;
	hold_one = find_top_num(p, chunks[0]);
	hold_two = find_lower_num(p, chunks[0]);
	if (hold_one.moves <= hold_two.moves)
		choose_push_helper(p, hold_one, hold_two);
	else if (hold_two.moves < hold_one.moves)
	{
		i = 0;
		while (i < hold_two.moves)
		{
			ft_rra(p);
			i++;
		}
		ft_pb(p);
	}
}
