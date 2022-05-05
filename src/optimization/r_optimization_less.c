/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	r_optim_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	checker;

	checker = 0;
	if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
			(stackb->a > stacka->a && stackb->a < stacka->b))
		checker++;
	if ((stackb->b < stacka->a && stackb->b > stacka->c) || \
			(stackb->b > stacka->a && stackb->b < stacka->b))
		checker++;
	if ((stackb->c < stacka->a && stackb->c > stacka->c) || \
			(stackb->c > stacka->a && stackb->c < stacka->b))
		checker++;
	return (checker);
}

int	r_optim_less(t_stack *stacka, t_stack *stackb, t_info *printer, int *new_ra)
{
	int	count;
	int	check;

	count = 0;
	check = 0;
	if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
			(stackb->a > stacka->a && stackb->a < stacka->b))
	{
		count = count + r_optim_less_a(stacka, stackb, printer);
		check++;
	}
	if ((stackb->b < stacka->a && stackb->b > stacka->c) || \
			(stackb->b > stacka->a && stackb->b < stacka->b))
	{
		count = count + r_optim_less_b(stacka, stackb, printer);
		check++;
	}
	if ((stackb->c < stacka->a && stackb->c > stacka->c) || \
			(stackb->c > stacka->a && stackb->c < stacka->b))
	{
		count = count + r_optim_less_c(stacka, stackb, printer);
		check++;
	}
	*new_ra = check;
	return (count);
}

int	r_optim_less_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->a < stacka->a && stackb->a > stacka->c)
	{
		ft_pa(stacka, stackb, printer);
	}
	else if (stackb->a > stacka->a && stackb->a < stacka->b)
	{
		ft_pa(stacka, stackb, printer);
		ft_sa(stacka, stackb, printer);
	}
	return (count);
}

int	r_optim_less_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->b < stacka->a && stackb->b > stacka->c)
	{
		ft_sb(stackb, stacka, printer);
		ft_pa(stacka, stackb, printer);
	}
	else if (stackb->b > stacka->a && stackb->b < stacka->b)
	{
		ft_sb(stackb, stacka, printer);
		ft_pa(stacka, stackb, printer);
		ft_sa(stacka, stackb, printer);
	}
	return (count);
}

int	r_optim_less_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->c < stacka->a && stackb->c > stacka->c)
	{
		ft_rrb(stackb, stacka, printer);
		ft_pa(stacka, stackb, printer);
	}
	else if (stackb->c > stacka->a && stackb->c < stacka->b)
	{
		ft_rrb(stackb, stacka, printer);
		ft_pa(stacka, stackb, printer);
		ft_sa(stacka, stackb, printer);
	}
	return (count);
}
