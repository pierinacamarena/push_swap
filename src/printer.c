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
	int	move_q;
	int 	i;
	int	len;

	i = 0;
	ft_putstr("---------------------------------\n");
	ft_putstr("exec ");
	while (i < printer.move_q)
	{
		ft_putstr(printer.move[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
	len = ft_max(printer.lenA, printer.lenB);
	i = 0;
	while (i < len)
	{
		if (printer.lenA > printer.lenB)
		{
			while(i < printer.lenA)
			{
				ft_putnbr(printer.stackA.array[i]);
				if++;
			}
		}
		else if (printer.lenA < printer.lenB)
		{
			while(i < printer.lenB)
			{
				ft_putnbr(printer.stackA.array[i]);
				i++;
			}
		}
		else
		{
			ft_putnbr(printer.stackA.array[i]);
			ft_putnbr(printer.stackA.array[i]);
			i++
		}
		if(i < len)
		{
			ft_putnbr(printer.stackA.array[i]);
			ft_putnbr(printer.stackA.array[i]);
			i++;
		}
	}
}
