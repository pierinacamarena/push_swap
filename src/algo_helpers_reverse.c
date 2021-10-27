#include "push_swap.h"

int		reverse_top_stack_a(t_stack *stackA, t_stack *stackB)
{
	int	count;

	count = 0;
	if (stackB->a < stackA->x)
	{
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		return (count);
	}
	else if (stackB->a > stackA->y)
	{
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		count = count + ft_ra(stackB);
		printf("ra\n");
		ft_simple_print(*stackA, *stackB);
		return (count);
	}
	return (count);
}

int	reverse_top_stack_b(t_stack *stackA, t_stack *stackB)
{
	int	count;

	count = 0;
	if (stackB->b < stackA->x)
	{
		count = count + ft_sb(stackB);
		printf("sb\n");
		ft_simple_print(*stackA, *stackB);
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		return (count);
	}
	else if (stackB->b > stackA->y)
	{
		count = count + ft_sb(stackB);
		printf("sb\n");
		ft_simple_print(*stackA, *stackB);
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		count = count + ft_ra(stackA);
		printf("ra\n");
		ft_simple_print(*stackA, *stackB);
		return(count);
	}
	return(count);
}

int	reverse_top_stack_c(t_stack *stackA, t_stack *stackB)
{
	int	count;

	count = 0;
	if (stackB->c < stackA->x)
	{
		count = count + ft_rrb(stackB);
		printf("rrb\n");
		ft_simple_print(*stackA, *stackB);
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		return (count);
	}
	else if (stackB->c > stackA->y)
	{
		count = count + ft_rrb(stackB);
		printf("rrb\n");
		ft_simple_print(*stackA, *stackB);
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		count = count + ft_ra(stackA);
		printf("ra\n");
		ft_simple_print(*stackA, *stackB);
		return (count);
	}
	return(count);
}

int	rdb_smaller(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	count;

	i = 0;
	if (stackB->b < stackA->midpoint)
	{
		count = ft_sb(stackB);
		while (i < stackB->d_b)
		{
			count = count + ft_ra(stackA);
			printf("ra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		i = 0;
		while (i < stackB->d_b)
		{
			count = count + ft_rra(stackA);
			printf("rra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		return (count);
	}
	else
	{
		count = ft_sb(stackB);
		printf("sb\n");
		ft_simple_print(*stackA, *stackB);
		while (i < stackB->d_b)
		{
			count = count + ft_rra(stackA);
			printf("rra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		i = 0;
		while (i <= stackB->d_b)
		{
			count = count + ft_ra(stackA);
			printf("ra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		return (count);
	}
}

int rdc_smaller(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	count;

	i = 0;
	if (stackB->c < stackA->midpoint)
	{
		count = ft_rra(stackA);
		printf("rra\n");
		ft_simple_print(*stackA, *stackB);
		while (i < stackB->d_c)
		{
			count = count + ft_ra(stackA);
			printf("ra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		i = 0;
		while (i < stackB->d_c)
		{
			count = count + ft_rra(stackA);
			printf("rra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		return (count);
	}
	else
	{
		count = ft_rra(stackA);
		printf("rra\n");
		ft_simple_print(*stackA, *stackB);
		while (i < stackB->d_c)
		{
			count = count + ft_rra(stackA);
			printf("rra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		i = 0;
		while (i <= stackB->d_c)
		{
			count = count + ft_ra(stackA);
			printf("ra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		return (count);
	}
}

int	rda_smaller(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (stackB->a < stackA->midpoint)
	{
		while (i < stackB->d_a)
		{
			count = count + ft_ra(stackA);
			printf("ra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		i = 0;
		while (i < stackB->d_a)
		{
			count = count + ft_rra(stackA);
			printf("rra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		return (count);
	}
	else
	{
		while (i < stackB->d_a)
		{
			count = count + ft_rra(stackA);
			printf("rra\n");
			ft_simple_print(*stackA, *stackB);
			i++;
		}
		count = count + ft_pa(stackA, stackB);
		printf("pa\n");
		ft_simple_print(*stackA, *stackB);
		i = 0;
		while (i <= stackB->d_a)
		{
			count = count +ft_ra(stackA);
			ft_simple_print(*stackA, *stackB);
			printf("ra\n");
			i++;
		}
		return (count);
	}
}
