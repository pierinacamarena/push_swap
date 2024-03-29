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

/*
void    markup(t_stack *stacka)
{
    char    c;
    int     *counter_i;
    int     *counter_g;
    int     head_i;
    int     head_g;

    counter_i = head_index_counter(*stacka);
    //printf("counter_i is\n");
    counter_g = head_greater_counter(*stacka);
    printer_markup(*stacka, counter_i, counter_g);
    c = markup_choice(counter_i, counter_g, stacka->size);
    printf("c is %c\n",c);
    if (c == 'i')
    {
        printf("i chose i\n");
        head_i = head_finder_index(counter_i, stacka->size);
        index_selection(stacka, head_i);
        stacka->stay_a = find_max(counter_i, stacka->size);
        print_final_markup(*stacka);
    }
    else if (c == 'g')
    {
        printf("i chose g\n");
        head_g = head_finder_greater(counter_g, stacka->size);
        printf("head is %d\n", head_g);
        greater_selection(stacka, head_g);
        stacka->stay_a = find_max(counter_g, stacka->size);
        print_final_markup(*stacka);
    }
    else if (c == 'e')
    {
        printf("inside e\n");
        head_i = head_finder_index(counter_i, stacka->size);
        head_g = head_finder_greater(counter_g, stacka->size);
        printf("heads i and g are %d %d\n", head_i, head_g);
        stacka->stay_a = find_max(counter_g, stacka->size);
        if (head_i < head_g)
        {
            printf("i chose i\n");
            index_selection(stacka, head_i);
            print_final_markup(*stacka);
        }
        else
        {
            printf("i chose g\n");
            greater_selection(stacka, head_g);
            print_final_markup(*stacka);
        }
    }
    free(counter_i);
    free(counter_g);

}

void    temp_markup(t_stack *stacka)
{
    char    c;
    int     *counter_i;
    int     *counter_g;
    int     head_i;
    int     head_g;

    counter_i = head_index_counter(*stacka);
    //printf("counter_i is\n");
    counter_g = head_greater_counter(*stacka);
    printer_markup(*stacka, counter_i, counter_g);
    c = markup_choice(counter_i, counter_g, stacka->size);
    printf("c is %c\n",c);
    if (c == 'i')
    {
        head_i = head_finder_index(counter_i, stacka->size);
        printf("head is %d\n", head_i);
        stacka->temp_a = index_temp_selection(stacka, head_i);
        stacka->stay_a_temp = temp_stay_a(*stacka);
        print_final_markup(*stacka);
    }
    else if (c == 'g')
    {
        head_g = head_finder_greater(counter_g, stacka->size);
        printf("head is %d\n", head_g);
        stacka->temp_a = greater_temp_selection(stacka, head_g);
        stacka->stay_a_temp = temp_stay_a(*stacka);
        print_final_markup(*stacka);
    }
    else if (c == 'e')
    {
        head_i = head_finder_index(counter_i, stacka->size);
        head_g = head_finder_greater(counter_g, stacka->size);
        stacka->stay_a_temp = temp_stay_a(*stacka);
        printf("heads i and g are %d %d\n", head_i, head_g);
        if (head_i < head_g)
        {
        //    printf("inside i\n");
            stacka->temp_a = index_temp_selection(stacka, head_i);
            print_final_markup(*stacka);
        }
        else
        {
//            printf("inside g\n");
            stacka->temp_a = greater_temp_selection(stacka, head_g);
            print_final_markup(*stacka);
        }
    }
    free(counter_g);
    free(counter_i);
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
        printf("%d  %d\n",stacka.array[i][0], stacka.array[i][1]);
        i++;
    }
    i = 0;
        printf("Second two are: index0-n, counter_i, counterg\n");
    while (i < stacka.max_size)
    {
        printf("%d  %d\n", counter_i[i], counter_g[i]);
        i++;
    }
}

void    print_final_markup(t_stack stacka)
{
    int i;

    i = 0;
    while (i < stacka.max_size)
    {
        printf("%d | %d | %d\n", stacka.array[i][0], \
        stacka.array[i][1], stacka.array[i][2]);
        i++;
    }
}
*/