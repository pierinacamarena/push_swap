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
	t_stack		stacka;
	t_stack		stackb;
	t_info		printer;
	t_program	p;
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
	p.stacka = stacka;
	p.stackb = stackb;
	p.printer = printer;
	if (ft_check_sorted(stacka) || len == 1)
		ft_putstr("it is sorted! \n");
	else
		sort_stack(&p);
	return (0);
}

void	sort_stack(t_program *p)
{
	int count;

	count = 0;
	initial_print(p->printer);
	printf("\n");
	if (p->stacka.max_size > 20)
	{	
		count = count + solve_a(p);
		count = count + solve_b(p);
	}
	else if (p->stacka.max_size <= 20)
	{
		if (p->stacka.size == 2)
			count = count + ft_sa(p);
		if (p->stacka.size == 3)
			count = count + ft_sort_three(p);
		else if (p->stacka.size > 3 && p->stacka.size <= 20)
			count = count + ft_sort_inverse(p);
	}
	printf("stacka\n");
	ft_print_stack(p->stacka);
	printf("stackb\n");
	ft_print_stack(p->stackb);
	printf("the size is %d\n", p->stackb.size);
	printf("the number of instructions is %d\n", p->printer.count);
	free(p->stacka.array);
	free(p->stackb.array);
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
