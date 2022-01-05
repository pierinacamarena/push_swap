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
/*

Part II: From Stack A to Stack B
Pseudocode

WHILE stack A has elements with "false" value in "Keep in Stack A" field
      IF sa (swap a) is needed
            perform sa (swap a) command
            update markup
      ELSE IF head element of stack A has "false" value in "Keep in Stack A" field
            perform pb (push b) command
      ELSE
            perform ra (rotate a) command
How to check that sa (swap a) is needed?
You have to perform sa (swap a) and then remake markup. We only have to update markup with chosen at previous steps parameters (as markup_head).

Then we have to compare how many elements will be kept in stack A with performed sa (swap a) and without it.

If after performing sa (swap a) more elements will be kept, it means that there is a reason to do it.

After all we have to unmake sa (swap a) and return result of our calculations.
*/

void    push_to_b(t_stack *stacka);
{
    int i;
    int stacka_check;
    int count;

    i = 0;
    count = 0;
    stacka_check = check_bool_array(*stacka);
    while (stacka_check == 1)
    {
        stacka_check = check_bool_array(*stacka);
        //check if sa is needed
        else if (stacka->array[0] == 0)
            count = count + ft_pb(stacka, stackb, printer);
        else
            count = count + ft_ra(stacka, stackb, printer);   
    }
}

int check_stacka(t_stack stacka)
{
    int i;

    i = 0;
    while (i < stacka.size)
    {
        if (stacka->array[i][2] == 0)
            return (1);
        i++;
    }
    return (0);
}

int check_sa(t_stack *stacka);
{
    int original_stay;
    int new_stay;
    int temp;

    original_stay = stacka.stay_a;
    temp = ft_sa(stacka, stackb, printer);
    markup(stacka);
    new_stay = stacka.stay_a;
    if (new_stay > original_stay)
        return (0);
    else
    {
        temp = temp + ft_sa(stacka, stackb, printer);
        markup(stacka);
        return (1)
    }
}
