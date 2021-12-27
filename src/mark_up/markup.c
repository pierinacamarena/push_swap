/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    markup(t_stack *stacka)
{
    t_stack arr;
    char     c;
    int     *counter_i;
    int     *counter_g;
    int     head_i;
    int     head_g;

    arr = dirty_sorting(*stacka);
    stacka->indices = set_index(arr, *stacka);
    counter_i = head_index_counter(*stacka, indexed);
    counter_g = head_greater_counter(*stacka, indexed);
    c = markup_choice(counter_i, counter_g);
    if (c == 'i')
    {
        head = head_finder_index(counter, stacka->max_size)
        index_selection(stacka, head);
    }
    else if (c == 'g')
    {
        head_g = head_finder_greater(counter, stacka->max_size);
        greater_selection(stacka, head_g);
    }
    else if (c == 'e')
    {
        head_i = head_finder_index(counter, stacka->max_size);
        head_g = head_finder_greater(counter, stacka->max_size);
        if (head_i < head_g)
            index_selection(stacka, head);
        else
            greater_selection(stacka, head_g);
    }

}

char markup_choice(int *counter_i, int *counter_g, int size)
{
    int head_i;
    int head_g;

    head_i = find_max(counter_i, size);
    head_g = find_max(counter_g, size);
    if (head_i > head_g)
        return ('i');
    else if (head_i < head_g)
        return ('g');
    else
        return ('e')
}
