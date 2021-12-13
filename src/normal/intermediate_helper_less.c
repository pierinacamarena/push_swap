/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_helper_less.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/30 17:00:44 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	da_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;
	//int		new_ra;
	//int		rr0000000a;

	i = 0;
	printf("---inside da_less_midpoint---\n instruction number is %d\n", printer->count);
	while (i < stacka->d_a)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i <= stacka->d_a)
	{
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	printf("---exiting da_less_midpoint---\n, count is %d\n", count);
	printf("the number of instruction is %d\n", printer->count);
	return (count);
}

int	db_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;
	//int		new_ra;
	//int		rra;

	i = 0;
	printf("---inside db_less_midpoint---\n instruction number is %d\n", printer->count);
	count = ft_sa(stacka, stackb, printer);
	while (i < stacka->d_b)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i <= stacka->d_b)
	{
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	printf("---exiting db_less_midpoint---\n, count is %d\n", count);
	printf("the number of instruction is %d\n", printer->count);
	return (count);
}

int	dc_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int		i;
	int		count;
	int		new_ra;
	int		rra;

	i = 0;
	printf("---inside dc_less_midpoint---\n instruction number is %d\n", printer->count);
	count = ft_rra(stacka, stackb, printer);
	while (i < stacka->d_c)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		i++;
	}
	count = count + ft_pb(stacka, stackb, printer);
	i = 0;
	while (i <= stacka->d_c)
	{
		count = count + ft_rb(stackb, stacka, printer);
		i++;
	}
	printf("---exiting dc_more_midpoint---\n, count is %d\n", count);
	printf("the number of instruction is %d\n", printer->count);
	return (count);
}
