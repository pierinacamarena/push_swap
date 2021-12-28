/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    push_to_b(t_stack *stacka);
{
    int i;
    int bool_check;
    int count;

    i = 0;
    count = 0;
    bool_check = check_bool_array(stacka);
    while (bool_check == 1)
    {
        if (stacka->bool_index[0] == 0)
            count = ft_pb(stacka, stackb, printer);   
    }
}

int check_bool_array(t_stack stacka)
{
    int i;
    i = 0;
    while(i < stacka.size)
    {
        if (stacka.bool_index[i] == 1)
            return (1);
        i++;
    }
    return (0);
}
