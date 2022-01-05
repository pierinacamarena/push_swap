/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:53:03 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/05 19:23:02 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * This function will initialize a stack that will later be populated
 *
 **/
t_stack	init_stack(int len)
{
	t_stack stack;
	int		i;	
	int		**array;

	array = (int **)malloc(sizeof(int*) * len);
	while (i < len)
	{
		array[i] = (int*)malloc(sizeof(int) * 3);
		i++;
	}
	stack.array = array;
	stack.max_size = len;
	stack.size = 0;

	return (stack);
}

bool	ft_check_sorted_reverse(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < (stack.size - 2) && (stack.array[i][0] > stack.array[j][0]))
	{
		i++;
		j++;
	}
	if ((i == stack.size - 2) && (stack.array[i][0] > stack.array[j][0]))
		return (true);
	return (false);
}

/**
 *	This function checks if the stack is sorted in ascending order
 **/

bool	ft_check_sorted(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < (stack.size - 2) && (stack.array[i][0] < stack.array[j][0]))
	{
		i++;
		j++;
	}
	if ((i == stack.size - 2) && (stack.array[i][0] < stack.array[j][0]))
		return (true);
	return (false);
}

/**
 *	This function populates the array of the stack struct with the list of
 *	numbers given from av.
 **/

t_stack	ft_stack_populate(t_stack *stack, char **av, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= size)
	{
		stack->array[j][0] = ft_atoi(av[i]);
		i++;
		j++;
	}
	stack->size = size;
	stack->a = stack->array[0][0];
	stack->b = stack->array[1][0];
	stack->c = stack->array[size - 1][0];
	return (*stack);
}
