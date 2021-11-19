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

#include "../includes/push_swap.h"

/**
void    format_printing_initial(t_stack  stackA, t_stack stackB)
{
    int i;

    i = 0;
    printf("Init a and b\n");
    while (i < stackA->max_size)
}
**/
void	ft_print_full_stack(t_stack stackA, t_stack stackB, int j)
{
	printf("This is stackA \n, at the %dth iteration\n", j);
	printf("----------------------------------------\n");
	ft_print_stack(stackA);
	printf("----------------------------------------\n");
	printf("\n\n");
	printf("This is stackB \n");
	printf("----------------------------------------\n");
	ft_print_stack(stackB);
	printf("----------------------------------------\n");
	printf("these are the values of stackA\n");
	printf("size: %d\n", stackA.size);
	printf("max_size: %d\n", stackA.max_size);
	printf("a is %d\n", stackA.a);
	printf("b is %d\n", stackA.b);
	printf("c is %d\n", stackA.c);
	printf("these are the values of stackB\n");
	printf("size; %d\n", stackB.size);
	printf("max_size: %d\n", stackB.max_size);
	printf("x is %d\n", stackB.x);
	printf("y is %d\n", stackB.y);
	printf("midpoint is %d\n", stackB.midpoint);
	ft_print_distances(stackA, 0);
}

void	ft_simple_print(t_stack stackA, t_stack stackB)
{
	printf("*****************************************\n");
	ft_print_stack(stackA);
	printf("*****************************************\n");
	ft_print_stack(stackB);
	printf("*****************************************\n");
}


void	ft_print_distances(t_stack stackA, int j)
{
	printf("the value of distances at the %dth iteration is (ignore this part)\n", j);
	printf("d_a is %d\n", stackA.d_a);
	printf("d_b is %d\n", stackA.d_b);
	printf("d_c is %d\n", stackA.d_c);
}
