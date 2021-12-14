/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:08:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:36:04 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int optima_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int check;

    check = 0;
    if ((stacka->a > stackb->a && stacka->a < stackb->c) || \
        (stacka->a < stackb->a && stacka->a > stackb->b))
        check = 1;
    
    return (check);
}

int optimb_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int check;

    check = 0;
    if ((stacka->b > stackb->a && stacka->b < stackb->c) || \
        (stacka->b < stackb->a && stacka->b > stackb->b))
        check = 1;
    return (check);
}

int optimc_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer)
{
    int check;

    check = 0;
    if ((stacka->c > stackb->a && stacka->c < stackb->c) || \
        (stacka->c < stackb->a && stacka->c > stackb->b))
        check = 1;
    return (check);
}