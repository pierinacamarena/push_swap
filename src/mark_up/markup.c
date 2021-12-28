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
    counter_i = head_index_counter(*stacka);
    printf("counter_i is\n");
    counter_g = head_greater_counter(*stacka);
    printer_markup(*stacka, counter_i, counter_g);
    c = markup_choice(counter_i, counter_g, stacka->max_size);
    printf("c is %c\n",c);
    if (c == 'i')
    {
        head_i = head_finder_index(counter_i, stacka->max_size);
        index_selection(stacka, head_i);
    }
    else if (c == 'g')
    {
        head_g = head_finder_greater(counter_g, stacka->max_size);
        printf("head is %d\n", head_g);
        greater_selection(stacka, head_g);
        print_final_markup(*stacka);
    }
    else if (c == 'e')
    {
        head_i = head_finder_index(counter_i, stacka->max_size);
        head_g = head_finder_greater(counter_g, stacka->max_size);
        if (head_i < head_g)
            index_selection(stacka, head_i);
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
        return ('e');
}

void printer_markup(t_stack stacka, int *counter_i, int *counter_g)
{
    int i;

    i = 0;
    printf("here are the following arrays\n");
    printf("First two are: stacka, indices\n");
    while (i < stacka.max_size)
    {
        printf("%d  %d\n",stacka.array[i], stacka.indices[i]);
        i++;
    }
    i = 0;
    printf("Second three are: index0-n, counter_i, counterg\n");
    while (i < stacka.max_size)
    {
        printf("%d  %d  %d\n", i, counter_i[i], counter_g[i]);
        i++;
    }
}

void    print_final_markup(t_stack stacka)
{
    int i;

    i = 0;
    while (i < stacka.max_size)
    {
        printf("%d | %d | %d\n", stacka.array[i], stacka.indices[i], stacka.bool_index[i]);
        i++;
    }
}