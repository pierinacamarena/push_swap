/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:06 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int r_optim_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int checker;

    checker = 0;
    if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
        (stackb->a > stacka->a && stackb->a < stacka->b))
        checker++;
    if ((stackb->b < stacka->a && stackb->b > stacka->c) || \
        (stackb->b > stacka->a && stackb->b < stacka->b))
        checker++;
    if ((stackb->c < stacka->a && stackb->c > stacka->c) || \
        (stackb->c > stacka->a && stackb->c < stacka->b))
        checker++;
    return (checker);

}

int r_optim_less(t_stack *stacka, t_stack *stackb, t_info *printer, int *new_ra)
{
    int count;
    int check;

    count = 0;
    check = 0;
    printf("inside reverse optimization less main function\n");
    printf("number of instruction is %d\n", printer->count);
    if ((stackb->a < stacka->a && stackb->a > stacka->c) || \
        (stackb->a > stacka->a && stackb->a < stacka->b))
    {
        count = count + r_optim_less_a(stacka, stackb, printer);
        check++;
        printf("inside roptim less, the vale of check is %d\n", check);
    }
    if ((stackb->b < stacka->a && stackb->b > stacka->c) || \
        (stackb->b > stacka->a && stackb->b < stacka->b))
    {
        count = count + r_optim_less_b(stacka, stackb, printer);
        check++;
        printf("inside roptim less, the vale of check is %d\n", check);
    }
    if ((stackb->c < stacka->a && stackb->c > stacka->c) || \
        (stackb->c > stacka->a && stackb->c < stacka->b))
    {
        count = count + r_optim_less_c(stacka, stackb, printer);
        check++;
        printf("inside roptim less, the vale of check is %d\n", check);
    }
    *new_ra = check;
    printf("inside roptim less, the vale of new_ra is %d\n", *new_ra);
    return (count);
}

int r_optim_less_a(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    count = 0;
    printf("inside reverse optimization less_a function\n");
    printf("number of instruction is %d\n", printer->count);
    if (stackb->a < stacka->a && stackb->a > stacka->c)
    {
        printf("inside r_optimization_less a_a\n");
        printf("number of instruction is %d\n", printer->count);
        ft_pa(stacka, stackb, printer);
    }
    else if (stackb->a > stacka->a && stackb->a < stacka->b)
    {
        printf("inside r_optimization_less a_b\n");
        printf("number of instruction is %d\n", printer->count);
        ft_pa(stacka, stackb, printer);
        ft_sa(stacka, stackb, printer);
    }
    return (count);
}

int r_optim_less_b(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    count = 0;
    printf("inside reverse optimization less_b function\n");
    printf("number of instruction is %d\n", printer->count);
    if (stackb->b < stacka->a && stackb->b > stacka->c)
    {
        printf("inside r_optimization_less b_a\n");
        printf("number of instruction is %d\n", printer->count);
        ft_sb(stackb, stacka, printer);
        ft_pa(stacka, stackb, printer);
    }
    else if (stackb->b > stacka->a && stackb->b < stacka->b)
    {
        printf("inside r_optimization_less b_b\n");
        printf("number of instruction is %d\n", printer->count);
        ft_sb(stackb, stacka, printer);
        ft_pa(stacka, stackb, printer);
        ft_sa(stacka, stackb, printer);
    }
    return (count);
}

int r_optim_less_c(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int count;

    count = 0;
    printf("inside reverse optimization less_c function\n");
    printf("number of instruction is %d\n", printer->count);
    if (stackb->c < stacka->a && stackb->c > stacka->c)
    {
        printf("inside r_optimization_less c_a\n");
        printf("number of instruction is %d\n", printer->count);
        ft_rrb(stackb, stacka, printer);
        ft_pa(stacka, stackb, printer);
    }
    else if (stackb->c > stacka->a && stackb->c < stacka->b)
    {
        printf("inside r_optimization_less c_b\n");
        printf("number of instruction is %d\n", printer->count);
        ft_rrb(stackb, stacka,printer);
        ft_pa(stacka, stackb, printer);
        ft_sa(stacka, stackb, printer);
    }
    return (count);
}