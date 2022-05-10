/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:43:25 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:50:57 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

int	check_arguments(int ac, char **av)
{
	int	error;

	error = 0;
	if (ac == 0 || ac == 1)
	{
		ft_putstr("not enough arguments\n");
		return (0);
	}
	error = check_numbers(ac, av);
	if (error == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	check_numbers(int ac, char **av)
{
	int	i;
	int	j;
	int	is_digit;

	j = 0;
	i = 1;
	while (i < (ac))
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			is_digit = ft_isdigit(av[i][j]);
			if (is_digit == 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
