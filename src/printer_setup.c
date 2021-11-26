/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:43:25 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:50:57 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_info	init_printer(t_stack stacka, t_stack stackb)
{
	t_info	printer;

	printer.stacka = stacka;
	printer.stackb = stackb;
	printer.lena = stacka.size;
	printer.lenb = stackb.size;
	printer.move[3] = '\0';
	printer.move[2] = '\0';
	printer.count = 0;
	return (printer);
}

void	update_printer(t_stack stacka, t_stack stackb, \
		t_info *printer, char *move)
{
	printer->lena = stacka.size;
	printer->lenb = stackb.size;
	printer->move[0] = move[0];
	printer->move[1] = move[1];
	printer->move[2] = '\0';
	if (move[2] != '\0')
		printer->move[2] = move[2];
	ft_printer(*printer);
}