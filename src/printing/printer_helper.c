/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/12/01 18:21:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	printer_diff_len(t_info printer)
{
	int		i;
	int		difference;

	i = 0;
	if (printer.lena > printer.lenb)
	{
		difference = printer.lena - printer.lenb;
		while (i < difference)
		{
			ft_putnbr(printer.stacka.array[i++][0]);
			ft_putstr("\n");
		}
	}
	else if (printer.lena < printer.lenb)
		i = i + printer_difflen_b(printer);
	return (i);
}

int	printer_difflen_b(t_info printer)
{
	int		i;
	int		difference;

	i = 0;
	difference = printer.lenb - printer.lena;
	while (i < difference)
	{
		ft_putstr("                ");
		ft_putnbr(printer.stackb.array[i++][0]);
		ft_putstr("\n");
	}
	return (i);
}

int	printer_same_len(t_info printer, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(printer.stacka.array[i][0]);
		ft_putstr("                ");
		ft_putnbr(printer.stackb.array[i][0]);
		ft_putstr("\n");
		i++;
	}
	return (i);
}

int	printer_final_print(t_info printer, int i, int len)
{
	int		j;

	j = 0;
	if (i < len && printer.lena > printer.lenb)
	{
		while (i < len)
		{
			ft_putnbr(printer.stacka.array[i++][0]);
			ft_putstr("               ");
			ft_putnbr(printer.stackb.array[j++][0]);
			ft_putstr("\n");
		}
	}
	else if (i < len && printer.lenb > printer.lena)
		i = i + printer_final_b(printer, i, len);
	return (i);
}

int	printer_final_b(t_info printer, int i, int len)
{
	int		j;

	j = 0;
	while (i < len)
	{
		ft_putnbr(printer.stacka.array[j++][0]);
		ft_putstr("               ");
		ft_putnbr(printer.stackb.array[i++][0]);
		ft_putstr("\n");
	}
	return (i);
}
