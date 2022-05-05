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

	len = ac - 1;
	if (ac == 0 || ac == 1)
	{
		ft_putstr("no numbers to sort\n");
		return (0);
	}
	stacka = init_stack(len);
	ft_stack_populate(&stacka, av, len);
	stackb = init_stack(len);
	printer = init_printer(stacka, stackb);
	if (ft_check_sorted(stacka) || len == 1)
		ft_putstr("it is sorted! \n");
	else
		sort_stack(&stacka, &stackb, &printer);
	return (0);
}

void	sort_stack(t_stack *stacka, t_stack *stackb, t_info *printer)
{
	initial_print(*printer);
	printf("\n");
	solve_a(stacka, stackb, printer);
	printf("stacka\n");
	ft_print_stack(*stacka);
	printf("stackb\n");
	ft_print_stack(*stackb);
	printf("the size is %d\n", stackb->size);
	printf("the number of instructions is %d\n", printer->count);
	free(stacka->array);
	free(stackb->array);
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
