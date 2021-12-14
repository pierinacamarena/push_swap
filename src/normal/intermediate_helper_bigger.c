/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_helper_bigger.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	da_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;
	int		check;

	i = 0;
	count = 0;
	printf("---inside da_more_midpoint---\n instruction number is %d\n", printer->count);
	while (i < stacka->d_a)
	{
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i < stacka->d_a)
	{
		while ((check = optim_checker(stacka, stackb, printer)) > 0)
			count = count + optim(stacka, stackb, printer);
		printf("after optmization in rda, before rrb\n");
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	printf("---exiting da_more_midpoint---\n, count is %d\n", count);
	printf("the number of instruction is %d\n", printer->count);
	return (count);
}

int	db_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;
	int		check;

	i = 0;
	printf("---inside db_more_midpoint---\n instruction number is %d\n", printer->count);
	count = ft_sa(stacka, stackb, printer);
	while (i < stacka->d_b)
	{
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i < stacka->d_b)
	{
		while ((check = optim_checker(stacka, stackb, printer)) > 0)
			count = count + optim(stacka, stackb, printer);
		printf("after optmization in rdb, before rrb\n");
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	printf("---exiting db_more_midpoint---\n, count is %d\n", count);
	printf("the number of instruction is %d\n", printer->count);
	return (count);
}

int	dc_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;
	int		check;

	i = 0;
	printf("---inside db_more_midpoint---\n instruction number is %d\n", printer->count);
	count = ft_rra(stacka, stackb, printer);
	while (i < stacka->d_c)
	{
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i < stacka->d_c)
	{
		while ((check = optim_checker(stacka, stackb, printer)) > 0)
			count = count + optim(stacka, stackb, printer);
		printf("after optmization in rdc, before rrb\n");
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	printf("---exiting da_more_midpoint---\n, count is %d\n", count);
	printf("the number of instruction is %d\n", printer->count);
	return (count);
}
