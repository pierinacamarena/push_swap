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
	int	i;
	int	j;
	int	len;
	int	difference;

	i = 0;
	j = 0;
	ft_putstr("---------------------------------\n");
	ft_putstr("exec ");
	ft_putstr(printer.move);
	ft_putstr("---------");
	ft_putnbr(printer.count);
	ft_putstr("\n");
	len = ft_max(printer.lena, printer.lenb);
	while (i < len)
	{
		if (printer.lena > printer.lenb)
		{
			difference = printer.lena - printer.lenb;
			while (i < difference)
			{
				ft_putnbr(printer.stacka.array[i]);
				ft_putstr("\n");
				i++;
			}
		}
		else if (printer.lena < printer.lenb)
		{
			difference = printer.lenb - printer.lena;
			while (i < difference)
			{
				ft_putstr("                ");
				ft_putnbr(printer.stackb.array[i]);
				ft_putstr("\n");
				i++;
			}
		}
		else if (printer.lena == printer.lenb)
		{
			while (i < len)
			{
				ft_putnbr(printer.stacka.array[i]);
				ft_putstr("                ");
				ft_putnbr(printer.stackb.array[i]);
				ft_putstr("\n");
				i++;
			}
		}
		if (i < len && printer.lena > printer.lenb)
		{
			while (i < len)
			{
				ft_putnbr(printer.stacka.array[i]);
				ft_putstr("               ");
				ft_putnbr(printer.stackb.array[j]);
				ft_putstr("\n");
				i++;
				j++;
			}
		}
		else if (i < len && printer.lenb > printer.lena)
		{
			j = 0;
			while (i < len)
			{
				ft_putnbr(printer.stacka.array[j]);
				ft_putstr("               ");
				ft_putnbr(printer.stackb.array[i]);
				ft_putstr("\n");
				i++;
				j++;
			}
		}
	}
	ft_putstr("_               _\n");
	ft_putstr("a               b\n");
}

void	initial_print(t_info printer)
{
	int	i;
	int	len;

	i = 0;
	ft_putstr("---------------------------------\n");
	ft_putstr("Before sorting \n");
	len = printer.lena;
	while (i < len)
	{
		ft_putnbr(printer.stacka.array[i]);
		ft_putstr("\n");
		i++;
	}
	ft_putstr("_               _\n");
	ft_putstr("a               b\n");
}
