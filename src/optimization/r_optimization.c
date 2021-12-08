/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_optimization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int r_optim(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    printf("inside reverse optimization main function\n");
    printf("number of instruction is %d\n", printer->count);
    int count;

    count = 0;
    if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
        (stackb->a > stacka->a && stackb->a < stacka->b))
        count = count + r_optim_a(stacka, stackb, printer);
    if ((stackb->b < stacka->a && stackb->b > stacka->c) || \
        (stackb->b > stacka->a && stackb->b < stacka->b))
        count = count + r_optim_b(stacka, stackb, printer);
    if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
        (stackb->a > stacka->a && stackb->a < stacka->b))
        count = count + r_optim_c(stacka, stackb, printer);
    return (count);
}

int r_optim_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    printf("inside reverse optimization a\n");
    printf("number of instruction is %d\n", printer->count);
    int count;

    count = 0;
    if (stackb->a < stacka->a && stackb->a > stacka->c)
    {
        printf("inside r_optimization a_a\n");
        printf("number of instruction is %d\n", printer->count);
        count = count + ft_pa(stacka, stackb, printer);  
    }
    else if (stackb->a > stacka->a && stackb->a < stacka->b)
    {
        printf("inside r_optimization a_b\n");
        printf("number of instruction is %d\n", printer->count);
        count = count + ft_pa(stacka, stackb, printer);
        count = count + ft_sa(stacka, stackb, printer);
    }
    return (count);
}

int r_optim_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    printf("inside reverse optimization b\n");
    printf("number of instruction is %d\n", printer->count);
    int count;

    count = 0;
    if (stackb->b < stacka->a && stackb->b > stacka->c)
    {
        printf("inside r_optimization b_a\n");
        printf("number of instruction is %d\n", printer->count);
        count = count + ft_sb(stackb, stacka, printer);
        count = count + ft_pa(stacka, stackb, printer);
    }
    else if (stackb->b > stacka->a && stackb->b < stacka->b)
    {
        printf("inside r_optimization b_b\n");
        printf("number of instruction is %d\n", printer->count);
        count = count + ft_sb(stackb, stacka, printer);
        count = count + ft_pa(stacka, stackb, printer);
        count = count + ft_sa(stacka, stackb, printer);
    }
    return (count);
}

int r_optim_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    printf("inside reverse optimization c\n");
    printf("number of instruction is %d\n", printer->count);
    int count;

    count = 0;
    if (stackb->c < stacka->a && stackb->c > stacka->c)
    {
        printf("inside r_optimization c_a\n");
        printf("number of instruction is %d\n", printer->count);
        count = count + ft_rrb(stackb, stacka, printer);
        count = count + ft_pa(stacka, stackb, printer);
    }
    else if (stackb->c > stacka->a && stackb->c < stacka->b)
    {
        printf("inside r_optimization c_b\n");
        printf("number of instruction is %d\n", printer->count);
        count = count + ft_rrb(stackb, stacka, printer);
        count = count + ft_pa(stacka, stackb, printer);
        count = count + ft_sa(stacka, stackb, printer);
    }
    return (count);
}