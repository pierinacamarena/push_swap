/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stacka;
	t_stack	stackb;
	t_info	printer;
	int		len;
	int		count;

	len = ac - 1;
	if (ac == 0 || ac == 1)
	{
		ft_putstr("no numbers to sort");
		return (0);
	}
	stacka = init_stack(len);
	ft_stack_populate(&stacka, av, len);
	stackb = init_stack(len);
	printer = init_printer(stacka, stackb);
	if (ft_check_sorted(stacka) || len == 1)
		ft_putstr("it is sorted! \n");
	else
	{
		initial_print(printer);
		count = ft_sort_stack(&stacka, &stackb, &printer);
	//	ft_putstr("number of instructions is ");
	//	ft_putnbr(count);
	//	ft_putstr("\n");
	//	ft_print_stack(stacka);
	//	ft_print_stack(stackb);
	//free stacks 
	}
	return (0);
}

/**
 * Prints the elements of the stack from top to bottom.
 **/

void	ft_print_stack(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size)
	{
		printf("%d\n", stack.array[i]);
		i++;
	}
}
