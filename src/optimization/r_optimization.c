/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_optimization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	r_optim_checker(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	checker;

	checker = 0;
	if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
			(stackb->a > stacka->a && stackb->a < stacka->b))
		checker++;
	if ((stackb->b < stacka->a && stackb->b > stacka->c) || \
			(stackb->b > stacka->a && stackb->b < stacka->b))
		checker++;
	if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
			(stackb->a > stacka->a && stackb->a < stacka->b))
		checker++;
	return (checker);
}

int	r_optim(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
			(stackb->a > stacka->a && stackb->a < stacka->b))
		count = count + r_optim_a(stacka, stackb, printer);
	if ((stackb->b < stacka->a && stackb->b > stacka->c) || \
			(stackb->b > stacka->a && stackb->b < stacka->b))
		count = count + r_optim_b(stacka, stackb, printer);
	if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
			(stackb->a > stacka->a && stackb->a < stacka->b))
		count = count + r_optim_c(stacka, stackb, printer);
	return (count);
}

int	r_optim_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->a < stacka->a && stackb->a > stacka->c)
	{
		count = count + ft_pa(stacka, stackb, printer);
	}
	else if (stackb->a > stacka->a && stackb->a < stacka->b)
	{
		count = count + ft_pa(stacka, stackb, printer);
		count = count + ft_sa(stacka, stackb, printer);
	}
	return (count);
}

int	r_optim_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->b < stacka->a && stackb->b > stacka->c)
	{
		count = count + ft_sb(stackb, stacka, printer);
		count = count + ft_pa(stacka, stackb, printer);
	}
	else if (stackb->b > stacka->a && stackb->b < stacka->b)
	{
		count = count + ft_sb(stackb, stacka, printer);
		count = count + ft_pa(stacka, stackb, printer);
		count = count + ft_sa(stacka, stackb, printer);
	}
	return (count);
}

int	r_optim_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stackb->c < stacka->a && stackb->c > stacka->c)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		count = count + ft_pa(stacka, stackb, printer);
	}
	else if (stackb->c > stacka->a && stackb->c < stacka->b)
	{
		count = count + ft_rrb(stackb, stacka, printer);
		count = count + ft_pa(stacka, stackb, printer);
		count = count + ft_sa(stacka, stackb, printer);
	}
	return (count);
}
