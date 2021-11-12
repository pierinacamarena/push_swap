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


void	ft_printer(t_info printer)
{
	int	move_q;
	int 	i;
	int	len;

	i = 0;
	ft_putstr("---------------------------------\n");
	ft_putstr("exec ");
	ft_putstr(printer.move)
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
				ft_putstr("\n");
				i++;
			}
		}
		else if (printer.lenA < printer.lenB)
		{
			while(i < printer.lenB)
			{
				ft_putnbr(printer.stackA.array[i]);
				ft_putstr("\n");
				i++;
			}
		}
		else
		{
			ft_putnbr(printer.stackA.array[i]);
			ft_putstr(" ");
			ft_putnbr(printer.stackA.array[i]);
			ft_putstr("\n");
			i++
		}
		if(i < len)
		{
			ft_putnbr(printer.stackA.array[i]);
			ft_putstr(" ");
			ft_putnbr(printer.stackA.array[i]);
			ft_putstr("\n");
			i++;
		}
	}
	ft_putstr("_ _\n");
	ft_putstr("a b\n");
}
