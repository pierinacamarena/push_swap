/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:11:21 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:17:32 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_distance_reverse(t_stack *stackA, t_stack *stackB)
{
	ft_rda(stackA, stackB);
	ft_rdb(stackA, stackB);
	ft_rdc(stackA, stackB);
}

void	ft_rda(t_stack *stackA, t_stack *stackB)
{
	int	d;
	int	i;

	i = 0;
	if (stackB->a < stackA->midpoint)
	{
	   // printf("a < midpoint\n");
	   // printf("a is %d is and midpoint is %d\n", stackB->a, stackA->midpoint);
		while (stackB->a > stackA->array[i] && stackA->array[i] != stackA->midpoint)
		{
		    //printf("a is %d and stackA->array[i] is %d\n", stackB->a, stackA->array[i]);
		    //printf("inside while loop, i is %d\n", i);
			i++;
		}
		stackB->d_a = i;
		//printf("d_a is %d\n", stackB->d_a);
	}
	else if (stackB->a > stackA->midpoint)
	{
	    //printf("a > midpoint\n");
	    //printf("a is %d is and midpoint is %d\n", stackB->a, stackA->midpoint);
		i = 0;
		d = stackA->size - 1;
		while (stackB->a < stackA->array[d])
		{
		 //   printf("a is %d and stackA->array[i] is %d\n", stackB->a, stackA->array[d]);
		   // printf("inside while loop, i is %d and d is %d\n", i, d);
			i++;
			d--;
		}
		stackB->d_a = i;
		//printf("d_a is %d\n", stackB->d_a);
	}
}
void	ft_rdb(t_stack *stackA, t_stack *stackB)
{
	int	d;
	int	i;

	i = 0;
	if (stackB->b < stackA->midpoint)
	{
	//    printf("b < midpoint\n");
	  //  printf("b is %d is and midpoint is %d\n", stackB->b, stackA->midpoint);
		while (stackB->b > stackA->array[i])
		{
	//	    printf("inside while loop, i is %d\n", i);
			i++;
		}
		stackB->d_b = i;
	//	printf("d_b is %d\n", stackB->d_a);
	}
	else if (stackB->b > stackA->midpoint)
	{
	  //  printf("b > midpoint\n");
    //	printf("b is %d is and midpoint is %d\n", stackB->b, stackA->midpoint);
		i = 0;
		d = stackA->size - 1;
		while (stackB->b < stackA->array[d])
		{
			d--;
//			printf("inside while loop, i is %d\n", i);
			i++;
		}
		stackB->d_b = i;
//		printf("d_b is %d\n", stackB->d_a);
	}
}

void	ft_rdc(t_stack *stackA, t_stack *stackB)
{
	int	d;
	int	i;

	i = 0;
	if (stackB->c < stackA->midpoint)
	{
//	    printf("c < midpoint\n");
//	    printf("c is %d is and midpoint is %d\n", stackB->c, stackA->midpoint);
		while (stackB->c > stackA->array[i])
		{	
		//	printf("inside while loop, i is %d\n", i);
			i++;
		}
		stackB->d_c = i;
//		printf("d_c is %d\n", stackB->d_a);
	}
	else if (stackB->c > stackA->midpoint)
	{
//	    printf("c > midpoint\n");
//	    printf("c is %d is and midpoint is %d\n", stackB->c, stackA->midpoint);
		i = 0;
		d = stackA->size - 1;
		while (stackB->c < stackA->array[d])
		{
			d--;
//			printf("inside while loop, i is %d\n", i);
			i++;
		}
		stackB->d_c = i;
//		printf("d_c is %d\n", stackB->d_a);
	}
}
