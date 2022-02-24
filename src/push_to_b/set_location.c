/* ************************************************************************** */

#include "../../includes/push_swap.h"

int set_chunk_location(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num)
{
    int i;
    int k;
    int count;
    int moves_left;

    i = 0;
    k = 0;
    count = 0;
    num->distance = distance(*stacka, *stackb, *num);
    if (num->location == 't')
    {
        if (num->distance > num->moves)
        {
            while (k < num->moves)
            {
                count = count + ft_rr(stacka, stackb, printer);
                k++;   
            }
            moves_left = num->distance - num->moves;
            while (i < moves_left)
            {
                count = count + ft_rb(stackb, stacka, printer);
                i++;
            }
        }
        else if (num->distance == num->moves)
        {
            while (k < num->moves)
            {
                count = count + ft_rr(stacka, stackb, printer);
                k++;   
            }        
        }
        else if (num->distance < num->moves)
        {
            while (k < num->distance)
            {
                count = count + ft_rr(stacka, stackb, printer);
                k++;   
            }
            moves_left = num->moves - num->distance;
            while (i < moves_left)
            {
                count = count + ft_ra(stacka, stackb, printer);
                i++;
            }

        }
    }
    else if (num->location == 'b')
    {
        while (k < num->moves)
        {
            count = count + ft_rra(stacka, stackb, printer);
            k++;   
        }
        while (i < num->distance)
        {
            count = count + ft_rb(stackb, stacka, printer);
            i++;
        }
    }
    return (count);
}

int set_location_simple(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold num)
{
    int k;

    k = 0;
    if (num.location == 't')
    {
        while (k < num.moves)
        {
            count = count + ft_rb(stacka, stackb, printer);
            k++;
        }
    }
    else if (num.location == 'b')
    {
        while (k > num.moves)
        {
            count = count + ft_rrb(stacka, stackb, printer);
            k++;
        }
    }
}
