/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/12/01 18:04:22 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_printer(t_info printer)
{
	ft_putstr(printer.move);
	ft_putstr("\n");
}

void	printer_initial_setup(t_info printer)
{
	ft_putstr(printer.move);
	ft_putstr("\n");
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

/*void	ft_printer_full_print(t_info printer)
{
	int		i;
	int		len;

	i = 0;
	printer_initial_setup(printer);
	len = ft_max(printer.lena, printer.lenb);
	while (i < len)
	{
		if (printer.lena != printer.lenb)
			i = i + printer_diff_len(printer);
		else if (printer.lena == printer.lenb)
			i = i + printer_same_len(printer, len);
		if (i < len && printer.lena != printer.lenb)
			i = i + printer_final_print(printer, i, len);
	}
	ft_putstr("_               _\n");
	ft_putstr("a               b\n");
}

void	printer_initial_setup_full(t_info printer)
{
	//ft_putstr("---------------------------------\n");
	//ft_putstr("exec ");
	ft_putstr(printer.move);
	//ft_putstr("-------instruction number ");
	//ft_putnbr(printer.count);
	ft_putstr("\n");
}*/