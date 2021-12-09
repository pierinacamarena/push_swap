/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:51:46 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/05 19:54:56 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_print_full_stack(t_stack stacka, t_stack stackb, int j)
{
	printf("This is stackA \n, at the %dth iteration\n", j);
	printf("----------------------------------------\n");
	ft_print_stack(stacka);
	printf("----------------------------------------\n");
	printf("\n\n");
	printf("This is stackB \n");
	printf("----------------------------------------\n");
	ft_print_stack(stackb);
	printf("----------------------------------------\n");
	printf("these are the values of stackA\n");
	printf("size: %d\n", stacka.size);
	printf("max_size: %d\n", stacka.max_size);
	printf("a is %d\n", stacka.a);
	printf("b is %d\n", stacka.b);
	printf("c is %d\n", stackb.c);
	printf("these are the values of stackB\n");
	printf("size; %d\n", stackb.size);
	printf("max_size: %d\n", stackb.max_size);
	printf("x is %d\n", stackb.x);
	printf("y is %d\n", stackb.y);
	printf("midpoint is %d\n", stackb.midpoint);
	ft_print_distances(stacka);
}

void	ft_simple_print(t_stack stacka, t_stack stackb)
{
	printf("*****************************************\n");
	ft_print_stack(stacka);
	printf("*****************************************\n");
	ft_print_stack(stackb);
	printf("*****************************************\n");
}

void	ft_print_distances(t_stack stacka)
{
	printf("the value of distances is:\n -------------------------\n");
	printf("d_a is %d\n", stacka.d_a);
	printf("d_b is %d\n", stacka.d_b);
	printf("d_c is %d\n", stacka.d_c);
}

void	ft_print_distances_b(t_stack stackb)
{
	printf("the value of distances is:\n -------------------------\n");
	printf("d_a is %d\n", stackb.d_a);
	printf("d_b is %d\n", stackb.d_b);
	printf("d_c is %d\n", stackb.d_c);
	printf("size of stackb is %d\n", stackb.size);
	printf("-------------------------\n");
}
