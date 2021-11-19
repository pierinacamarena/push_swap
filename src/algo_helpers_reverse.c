#include "../includes/push_swap.h"

int		reverse_top_stack_a(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	count;

	count = 0;
	if (stackB->a < stackA->x)
	{
		count = count + ft_pa(stackA, stackB, printer);
		return (count);
	}
	else if (stackB->a > stackA->y)
	{
		count = count + ft_pa(stackA, stackB, printer);
		count = count + ft_ra(stackB, stackA, printer);
		return (count);
	}
	return (count);
}

int	reverse_top_stack_b(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	count;

	count = 0;
	if (stackB->b < stackA->x)
	{
		count = count + ft_sb(stackB, stackA, printer);
		count = count + ft_pa(stackA, stackB, printer);
		return (count);
	}
	else if (stackB->b > stackA->y)
	{
		count = count + ft_sb(stackB, stackA, printer);
		count = count + ft_pa(stackA, stackB, printer);
		count = count + ft_ra(stackA, stackB, printer);
		return(count);
	}
	return(count);
}

int	reverse_top_stack_c(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	count;

	count = 0;
	if (stackB->c < stackA->x)
	{
		count = count + ft_rrb(stackB, stackA, printer);
		count = count + ft_pa(stackA, stackB, printer);
		return (count);
	}
	else if (stackB->c > stackA->y)
	{
		count = count + ft_rrb(stackB, stackA, printer);
		count = count + ft_pa(stackA, stackB, printer);
		count = count + ft_ra(stackA, stackA, printer);
		return (count);
	}
	return(count);
}

int	rdb_smaller(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	if (stackB->b < stackA->midpoint)
	{
		count = ft_sb(stackB, stackA, printer);
		while (i < stackB->d_b)
		{
			count = count + ft_ra(stackA, stackB, printer);
			i++;
		}
		count = count + ft_pa(stackA, stackB, printer);
		i = 0;
		while (i < stackB->d_b)
		{
			count = count + ft_rra(stackA, stackB, printer);
			i++;
		}
		return (count);
	}
	else
	{
		count = ft_sb(stackB, stackA, printer);
		while (i < stackB->d_b)
		{
			count = count + ft_rra(stackA, stackB, printer);
			i++;
		}
		count = count + ft_pa(stackA, stackB, printer);
		i = 0;
		while (i <= stackB->d_b)
		{
			count = count + ft_ra(stackA, stackB, printer);
			i++;
		}
		return (count);
	}
}

int rdc_smaller(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	if (stackB->c < stackA->midpoint)
	{
		count = ft_rra(stackA, stackB, printer);
		while (i < stackB->d_c)
		{
			count = count + ft_ra(stackA, stackB, printer);
			i++;
		}
		count = count + ft_pa(stackA, stackB, printer);
		i = 0;
		while (i < stackB->d_c)
		{
			count = count + ft_rra(stackA, stackB, printer);
			i++;
		}
		return (count);
	}
	else
	{
		count = ft_rra(stackA, stackB, printer);
		while (i < stackB->d_c)
		{
			count = count + ft_rra(stackA, stackB, printer);
			i++;
		}
		count = count + ft_pa(stackA, stackB, printer);
		i = 0;
		while (i <= stackB->d_c)
		{
			count = count + ft_ra(stackA, stackB, printer);
			i++;
		}
		return (count);
	}
}

int	rda_smaller(t_stack *stackA, t_stack *stackB, t_info *printer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (stackB->a < stackA->midpoint)
	{
		while (i < stackB->d_a)
		{
			count = count + ft_ra(stackA, stackB, printer);
			i++;
		}
		count = count + ft_pa(stackA, stackB, printer);
		i = 0;
		while (i < stackB->d_a)
		{
			count = count + ft_rra(stackA, stackB, printer);
			i++;
		}
		return (count);
	}
	else
	{
		while (i < stackB->d_a)
		{
			count = count + ft_rra(stackA, stackB, printer);
			i++;
		}
		count = count + ft_pa(stackA, stackB, printer);
		i = 0;
		while (i <= stackB->d_a)
		{
			count = count + ft_ra(stackA, stackB, printer);
			i++;
		}
		return (count);
	}
}
