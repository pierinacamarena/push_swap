/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_bigger_reverse.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rda_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;
	int	i;
	int	new_ra;
	int	rra;

	i = 0;
	count = 0;
	new_ra = 0;
	rra = 0;
	printf("---inside rda_more_midpoint---\n instruction number is %d\n", printer->count);
	while (i < stackb->d_a)
	{
		count = count + ft_rra(stacka, stackb, printer);
		i++;
	}
	count = count + ft_pa(stacka, stackb, printer);
	i = 0;
	while (i <= stackb->d_a)
	{
		count = count + r_optim_less(stacka, stackb, printer, &new_ra);
		rra = rra + new_ra;
		printf("the next function will be ra inside original loop \n");
		printf("the instruction before the ra is %d\n", printer->count);
		count = count + ft_ra(stacka, stackb, printer);
		i++;
	}
	i = 0;
	while (i < rra)
	{
		printf("the next function will be ra of the optimization \n");
		printf("the instruction before the optimized ra is %d\n", printer->count);
		ft_ra(stacka, stackb, printer);
		i++;
	}
	printf("---exiting rda_more_midpoint---\n, count is %d\n rra is %d\n", count, rra);
	printf("the number of instruction is %d\n", printer->count);
	return (count);
}

int	rdb_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;
	int	new_ra;
	int	rra;

	i = 0;
	new_ra = 0;
	rra = 0;
	printf("---inside rdb_more_midpoint---\n instruction number is %d\n", printer->count);
	count = ft_sb(stackb, stacka, printer);
	while (i < stackb->d_b)
	{
		count = count + ft_rra(stacka, stackb, printer);
		i++;
	}
	count = count + ft_pa(stacka, stackb, printer);
	i = 0;
	while (i <= (stackb->d_b))
	{
		count = count + ft_ra(stacka, stackb, printer);
		count = count + r_optim_less(stacka, stackb, printer, &new_ra);
		rra = rra + new_ra;
		i++;
	}
	i = 0;
	while (i < rra)
	{
		ft_ra(stacka, stackb, printer);
		i++;
	}
	printf("---exiting rdb_more_midpoint---\n, count is %d\n rra is %d\n", count, rra);
	printf("the number of instruction is %d\n", printer->count);
	return (count);
}

int	rdc_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	i;
	int	count;
	int	new_ra;
	int	rra;

	i = 0;
	new_ra = 0;
	rra = 0;
	printf("---inside rdc_more_midpoint---\n instruction number is %d\n", printer->count);
	count = ft_rrb(stackb, stacka, printer);
	while (i < stackb->d_c)
	{
		count = count + ft_rra(stacka, stackb, printer);
		i++;
	}
	count = count + ft_pa(stacka, stackb, printer);
	i = 0;
	while (i <= (stackb->d_c))
	{
		count = count + r_optim_less(stacka, stackb, printer, &new_ra);
		rra = rra + new_ra;
		count = count + ft_ra(stacka, stackb, printer);
		i++;
	}
	i = 0;
	while (i < rra)
	{
		ft_ra(stacka, stackb, printer);
		i++;
	}
	printf("---exiting rdc_more_midpoint---\n, count is %d\n rra is %d\n", count, rra);
	printf("the number of instruction is %d\n", printer->count);
	return (count);
}
