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
	t_hold	hold_one;
	t_hold	hold_two;
	int		len;
	int		i;
	int		*arr;
	t_chunk	chunking;
	int		split;
	int		count;

	count = 0;
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
		split = 5;
		initial_print(printer);
		printf("\n");
		arr = indexing(&stacka);
		chunking = split_choice(stacka, arr);
		i = 0;
		while (i < stacka.size)
		{
			printf("%d    | %d  %d\n", i, stacka.array[i], arr[i]);
			i++;
		}
		i = 0;
		while (i < split)
		{
			printf("%d\n", chunking.chunks[i]);
			i++;
		}
		i = 0;
		while (i < split)
		{
			printf("chunk size %d chunk: %d\n", i + 1, chunking.chunk_size[i]);
			i++;
		}
		i = 0;
		while (i < 3)
		{	
			count = count + choose_push(&stacka, &stackb, &printer, chunking.chunks);
			i++;
		}
		count = count + ft_sort_three_reverse(&stackb, &stacka, &printer);
		printf("stacka\n");
		ft_print_stack(stacka);
		printf("stackb\n");
		ft_print_stack(stackb);
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
