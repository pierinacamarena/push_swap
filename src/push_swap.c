/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/05 19:54:53 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	main(int ac, char **av)
{
	t_stack stackA;
	t_stack stackB;
	int i;
	int len;
	int	count;

	i = 0;
	len = ac - 1;
	if (ac == 0 || ac == 1)
	{
		printf("no numbers to sort");
		return (0);
	}
	stackA = init_stack(len);
	ft_stack_populate(&stackA, av, len);
	stackB = init_stack(len);
	if (ft_check_sorted(stackA) || len == 1)
		printf("it is sorted! \n");
	else
	{
		ft_simple_print(stackA, stackB);
		count = ft_sort_stack(&stackA, &stackB);
		printf("number of instructions is %d\n", count);
	}
	return (0);
}

/**
 * Prints the elements of the stack from top to bottom.
 **/

void	ft_print_stack(t_stack stack)
{
	int i;

	i = 0;
	while (i < stack.size)
	{
		printf("%d\n",stack.array[i]);
		i++;
	}
}
