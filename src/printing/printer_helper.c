/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int     printer_diff_len(t_stack stacka, t_stack stackb, t_info printer)
{
    int     i;
    int     difference;
    
    i = 0; 
    if (printer.lena > printer.lenb)
	{
		difference = printer.lena - printer.lenb;
		while (i < difference)
        {
			ft_putnbr(printer.stacka.array[i++]);
			ft_putstr("\n");
		}
    }
	else if (printer.lena < printer.lenb)
        i = i + printer_difflen_b(stacka, stackb, printer);
    return (i);
}

int     printer_difflen_b(t_stack stacka, t_stack stackb, t_info printer)
{
    int     i;
    int     difference;

    i = 0;
    difference = printer.lenb - printer.lena;
	while (i < difference)
	{
        ft_putstr("                ");
		ft_putnbr(printer.stackb.array[i++]);
		ft_putstr("\n");
    }
    return (i);
}

int     printer_same_len(t_stack stacka, t_stack stackb, t_info printer)
{
    int     i;

    i = 0;
    while (i < len)
	{
		ft_putnbr(printer.stacka.array[i]);
	    ft_putstr("                ");
		ft_putnbr(printer.stackb.array[i]);
		ft_putstr("\n");
		i++;
	}
    return (i);
}

int     printer_final_print(t_stack stacka, t_stack stackb, t_info printer, int i)
{
    int     len
    int     j;

    j = 0;
    len = ft_max(printer.lena, printer.lenb);
    if (i < len && printer.lena > printer.lenb)
	{
	    while (i < len)
		{
			ft_putnbr(printer.stacka.array[i++]);
			ft_putstr("               ");
			ft_putnbr(printer.stackb.array[j++]);
			ft_putstr("\n");
		}
	}
	else if (i < len && printer.lenb > printer.lena)
        i = i + printer_final_b(stacka, stackb, printer, i);
    return (i);
}

int     printer_final_b(t_stack stacka, t_stack stackb, t_info printer, int i)
{
    int     len;
    int     j;

    j = 0;
    len = ft_max(printer.lena, printer.lenb);
    while (i < len)
	{
        ft_putnbr(printer.stacka.array[j++]);
		ft_putstr("               ");
		ft_putnbr(printer.stackb.array[i++]);
		ft_putstr("\n");
	}
    return (i);
}
