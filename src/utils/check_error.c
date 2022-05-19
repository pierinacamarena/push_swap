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

int	check_arguments(int ac, char **av)
{
	int			error_a;
	int			error_b;
	int			error_c;
	long long	*numbers;

	if (ac == 0 || ac == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	error_a = check_numbers(ac, av);
	numbers = populate_numbers(ac, av);
	error_b = check_duplicates(numbers, ac - 1);
	error_c = check_num_size(numbers, ac - 1);
	if (error_a == 0 || error_b == 1 || error_c == -1)
	{
		ft_putstr("Error\n");
		free(numbers);
		return (0);
	}
	free(numbers);
	return (1);
}

int	find_dup(long long *list, int len, int number)
{
	int	i;
	int	duplicates;

	i = 0;
	duplicates = 0;
	while (i < len)
	{
		if (list[i] == number)
			duplicates++;
		i++;
	}
	if (duplicates > 1)
		return (1);
	return (0);
}

int	check_duplicates(long long *list, int len)
{
	int	i;
	int	number;
	int	is_dup;

	i = 0;
	while (i < len)
	{
		number = list[i];
		is_dup = find_dup(list, len, number);
		if (is_dup == 1)
			return (1);
		i++;
	}
	return (0);
}

long long	*populate_numbers(int ac, char **av)
{
	long long	*numbers;
	char		*end;
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 1;
	len = ac - 1;
	numbers = (long long *)malloc(sizeof(long long) * (len));
	while (i < len)
	{
		numbers[i] = ft_strtoll(av[j], &end);
		i++;
		j++;
	}
	return (numbers);
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
			if (is_digit == 0 && av[i][j] != '-')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
