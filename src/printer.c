/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_printer(t_info printer)
{
	int 	i;
	int	j;
	int	len;
	int	difference;

	i = 0;
	j = 0;
	ft_putstr("---------------------------------\n");
	ft_putstr("exec ");
	ft_putstr(printer.move);
	ft_putstr("\n");
	len = ft_max(printer.lenA, printer.lenB);
	while (i < len)
	{
		if (printer.lenA > printer.lenB)
		{
			difference = printer.lenA - printer.lenB;
			while(i < difference)
			{
				ft_putnbr(printer.stackA.array[i]);
				ft_putstr("\n");
				i++;
			}
		}
		else if (printer.lenA < printer.lenB)
		{
			difference = printer.lenB - printer.lenA;
			while(i < difference)
			{
				ft_putstr("  ");
				ft_putnbr(printer.stackB.array[i]);
				ft_putstr("\n");
				i++;
			}
		}
		else if (printer.lenA == printer.lenB)
		{
			while (i < len)
			{
				ft_putnbr(printer.stackA.array[i]);
				ft_putstr(" ");
				ft_putnbr(printer.stackB.array[i]);
				ft_putstr("\n");
				i++;
			}
		}
		if (i < len && printer.lenA > printer.lenB)
		{
			while (i < len)
			{
				ft_putnbr(printer.stackA.array[i]);
				ft_putstr(" ");
				ft_putnbr(printer.stackB.array[j]);
				ft_putstr("\n");
				i++;
				j++;
			}
		}
		else if (i < len && printer.lenB > printer.lenA)
		{
			j = 0;
			while (i < len)
			{
				ft_putnbr(printer.stackA.array[j]);
				ft_putstr(" ");
				ft_putnbr(printer.stackB.array[i]);
				ft_putstr("\n");
				i++;
				j++;
			}
		}
	}
	ft_putstr("_ _\n");
	ft_putstr("a b\n");
}

void	initial_print(t_info printer)
{
	int 	i;
	int	len;

	i = 0;
	ft_putstr("---------------------------------\n");
	ft_putstr("Before sorting \n");
	len = printer.lenA;
	while (i < len)
	{
		ft_putnbr(printer.stackA.array[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("_ _\n");
	ft_putstr("a b\n");
}

