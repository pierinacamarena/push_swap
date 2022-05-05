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

int	optim_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	checker;

	checker = 0;
	if ((stacka->a > stackb->a && stacka->a < stackb->c) || \
			(stacka->a < stackb->a && stacka->a > stackb->b))
		checker++;
	if ((stacka->b > stackb->a && stacka->b < stackb->c) || \
			(stacka->b < stackb->a && stacka->b > stackb->b))
		checker++;
	if ((stacka->c > stackb->a && stacka->c < stackb->c) || \
			(stacka->c < stackb->a && stacka->c > stackb->b))
		checker++;
	return (checker);
}

int	optim_less(t_stack *stacka, t_stack *stackb, t_info *printer, int *new_rb)
{
	int	count;
	int	check;
	int	checker;
	int	ind_check;

	count = 0;
	check = 0;
	ind_check = 0;
	while ((checker = optim_less_checker(stacka, stackb, printer)) > 0)
	{
		while ((ind_check = optima_less_checker(stacka, stackb, printer)) == 1)
		{
			if ((stacka->a > stackb->a && stacka->a < stackb->c) || \
					(stacka->a < stackb->a && stacka->a > stackb->b))
			{
				check++;
				count = count + optim_less_a(stacka, stackb, printer);
			}
		}
		while ((ind_check = optimb_less_checker(stacka, stackb, printer)) == 1)
		{
			if ((stacka->b > stackb->a && stacka->b < stackb->c) || \
					(stacka->b < stackb->a && stacka->b > stackb->b))
			{
				check++;
				count = count + optim_less_b(stacka, stackb, printer);
			}
		}
		while ((ind_check = optimc_less_checker(stacka, stackb, printer)) == 1)
		{
			if ((stacka->c > stackb->a && stacka->c < stackb->c) || \
					(stacka->c < stackb->a && stacka->c > stackb->b))
			{
				check++;
				count = count + optim_less_c(stacka, stackb, printer);
			}
		}
	}
	*new_rb = check;
	return (count);
}

int	optim_less_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stacka->a > stackb->a && stacka->a < stackb->c)
	{
		count = count + ft_pb(stacka, stackb, printer);
	}
	else if (stacka->a < stackb->a && stacka->a > stackb->b)
	{
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_sb(stackb, stacka, printer);
	}
	return (count);
}

int	optim_less_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stacka->b > stackb->a && stacka->b < stackb->c)
	{
		count = count + ft_sa(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
	}
	else if (stacka->b < stackb->a && stacka->b > stackb->b)
	{
		count = count + ft_sa(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_sb(stackb, stacka, printer);
	}
	return (count);
}

int	optim_less_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	int	count;

	count = 0;
	if (stacka->c > stackb->a && stacka->c < stackb->c)
	{
		count = count + ft_rra(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
	}
	else if (stacka->c < stackb->a && stacka->c > stackb->b)
	{
		count = count + ft_rra(stacka, stackb, printer);
		count = count + ft_pb(stacka, stackb, printer);
		count = count + ft_sb(stackb, stacka, printer);
	}
	return (count);
}
