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

#include "../../includes/push_swap.h"

void	ft_printer(t_info printer)
{
	int	i;
	int	len;

	i = 0;
	printer_initial_setup(printer);
	len = ft_max(printer.lena, printer.lenb);
	while (i < len)
	{
		if (printer.lena != printer.lenb)
			i = i + printer_diff_len(stacka, stackb, printer);
		else if (printer.lena == printer.lenb)
			i = i + printer_same_len(stacka, stackb, printer);
		if (i < len && printer.lena != printer.lenb)
			i = i + printer_final_print(stacka, stackb, printer, i);
	ft_putstr("_               _\n");
	ft_putstr("a               b\n");
}

void    printer_initial_setup(t_info printer)
{
    ft_putstr("---------------------------------\n");
	ft_putstr("exec ");
	ft_putstr(printer.move);
	ft_putstr("-------instruction number");
	ft_putnbr(printer.count);
	ft_putstr("\n\n");
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
