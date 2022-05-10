/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:15:03 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:21 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_stack
{
	int	size;
	int	midpoint;
	int	a;
	int	b;
	int	c;
	int	x;
	int	y;
	int	*array;
	int	max_size;
	int	d_a;
	int	d_b;
	int	d_c;
}		t_stack;

typedef struct s_dirtysort
{
	int	i;
	int	j;
	int	k;
	int	n1;
	int	n2;
	int	*larr;
	int	*rarr;
}	t_dirtysort;

typedef struct s_chunk
{
	int	*chunks;
	int	*chunk_size;
	int	splits;
	int	current_chunk;
	int	push_nums;
	int	rrbs;
}	t_chunk;

typedef struct s_hold
{
	char	location;
	int		number;
	int		moves;
	int		distance;
}		t_hold;

typedef struct s_info
{
	t_stack	stacka;
	t_stack	stackb;
	int		lena;
	int		lenb;
	int		count;
	char	move[4];
	char	ins;

}		t_info;

typedef struct s_program
{
	t_stack	stacka;
	t_stack	stackb;
	t_info	printer;
	t_chunk	chunking;
}		t_program;

/*
-----Algorithm-----
*/

/*
push_swap.c
*/
void	sort_stack(t_program *p);

/*
stack_moves_helper.c
*/

/*
stackA_moves.c
*/
void	ft_temp_sa(t_stack *stacka, t_stack *stackb, t_info *printer);
void	ft_sa(t_program *p);
void	ft_ra(t_program *p);
void	ft_rra(t_program *p);
void	ft_pa(t_program *p);
void	ft_pa_helper(t_program *p);

/*
stackB_moves.c
*/
void	ft_sb(t_program *p);
void	ft_rb(t_program *p);
void	ft_rrb(t_program *p);
void	ft_pb(t_program *p);
void	ft_pb_helper(t_program *p);

/*
stack_rr_moves.c
*/
void	ft_rr(t_program *p);
void	ft_ra_rr(t_program *p);
void	ft_rb_rr(t_program *p);

/*
stack_rrr_moves.c
*/
void	ft_rrr(t_program *p);
void	ft_rra_rrr(t_program *p);
void	ft_rrb_rrr(t_program *p);

/*
-----Chunking-----
*/

/*
chunking.c
*/

t_chunk	split_choice(t_stack stacka, int *arr);
t_chunk	splitter(t_stack stacka, int n, int *arr);
void	set_size_chunks(t_chunk *chunking, t_stack stacka, int n);
int		has_chunk(t_stack stacka, t_chunk chunking, int n);

/*
-----Dirty_Sort-----
*/

/*
dirty_sort.c
*/
int		*dirty_sorting(t_program p);

/*
merge_sort.c
*/
int		*quickmergesort(t_stack stacka);

/*
-----Indexing----
*/

/*
indexing.c
*/
int		index_finder(t_stack stacka, int numb);
void	set_index(int *arr, t_stack *stacka);
int		*indexing(t_program p);

/*
-----Mark_up-----
*/

/*
markup.c
*/
void	markup(t_stack *stacka);
void	temp_markup(t_stack *stacka);
void	printer_markup(t_stack stacka, int *counter_i, int *counter_g);
void	print_final_markup(t_stack stacka);
char	markup_choice(int *counter_i, int *counter_g, int size);

/*
markup_greater.c
*/
int		markup_head_count(t_stack stacka, int index);
int		head_finder_greater(int *counter, int size);
int		*head_greater_counter(t_stack stacka);
int		*greater_temp_selection(t_stack *stacka, int index);
void	greater_selection(t_stack *stacka, int index);

/*
markup_index.c
*/
int		index_head_count(t_stack stacka, int index);
int		head_finder_index(int *counter, int size);
int		*head_index_counter(t_stack stacka);
int		*index_temp_selection(t_stack *stacka, int index);
void	index_selection(t_stack *stacka, int index);

/*
markup_utils.c
*/
int		index_value_finder(t_stack stacka, int index);
int		find_max(int *array, int len);
int		find_min(int *array, int len);
int		multiple_max(int *counter, int head, int size);
int		temp_stay_a(t_stack stacka);

/*
-----Normal------
*/

/*
distances.c
*/

/*
intermediate_helper_bigger.c
*/

/*
intermediate_helper_less.c
*/

/*
intermediate.c
*/

/*
sort_base_cases.c
*/
void	ft_sort_three(t_program *p);
void	ft_sort_three_helper(t_program *p);
int		ft_base_case_two(t_program *p);
int		ft_base_case_one(t_program *p);

/*
sort_stack_helpers.c
*/

/*
sort_stack.c
*/

/*
top_stack.c
*/

/*
-----Optimization-----
*/

/*
optimization.c
*/

int		optim_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int		optim(t_stack *stacka, t_stack *stackb, t_info *printer);
int		optim_a(t_stack *stacka, t_stack *stackb, t_info *printer);
int		optim_b(t_stack *stacka, t_stack *stackb, t_info *printer);
int		optim_c(t_stack *stacka, t_stack *stackb, t_info *printer);

/*
r_optimization.c
*/

int		r_optim_checker(t_program *p);
void	r_optim(t_program *p);
void	r_optim_a(t_program *p);
void	r_optim_b(t_program *p);
void	r_optim_c(t_program *p);

/*
r_optimization_less.c
*/

int		r_optim_less_checker(t_program *p);
void	r_optim_less(t_program *p, int *new_ra);
void	r_optim_less_a(t_program *p);
void	r_optim_less_b(t_program *p);
void	r_optim_less_c(t_program *p);

/*
optimization_loop.c
*/
int		optima_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int		optimb_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int		optimc_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
/*
optimization_less_loop.c
*/
int		optima_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int		optimb_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int		optimc_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer);

/*
-----Printing-----
*/

int		printer_diff_len(t_info printer);
int		printer_difflen_b(t_info printer);
int		printer_same_len(t_info printer, int len);
int		printer_final_print(t_info printer, int i, int len);
int		printer_final_b(t_info printer, int i, int len);
void	printer_initial_setup(t_info printer);

/*
debug_functions.c
*/

void	ft_print_distances_b(t_stack stackb);
void	ft_print_distances(t_stack stacka);

/*
printer_helper.c
*/

/*
printer.c
*/

/*
-----Push_to_b------
*/

/*
solve_b.c
*/

void	solve_b(t_program *p);

/*
-----Push_to_b------
*/

/*
first_chunk_helper.c
*/
void	support(t_program *p, t_hold num);
void	middle_helper(t_program *p, t_hold num);

/*
push_to_b.c
*/

void	push_to_b(t_stack *stacka, t_stack *stackb, t_info *printer);
int		check_stacka(t_stack stacka);
int		sa_check(t_stack *stacka, t_stack *stackb, t_info *printer);

/*
push_chunk.c
*/
void	solve_a(t_program *p);

/*
choose_push.c
*/
t_hold	find_top_num(t_program *p, int border);
t_hold	find_lower_num(t_program *p, int border);
void	choose_push_helper(t_program *p, t_hold one, t_hold two);
void	choose_push(t_program *p, int *chunks);

/*
push_chunk_helper.c
*/
t_hold	same_moves(t_hold one, t_hold two);
t_hold	choose_number(t_program *p, int chunk);
char	chunk_checker(t_stack stacka, t_chunk chunking);

/*
pushtob_utils.c
*/
int		distance(t_program p, t_hold num);
int		optim_distance(t_program p, t_hold num);
int		expected_stackbsize(t_chunk chunking);
void	rrb_helper_extra(t_program *p, int *complete_distance);

/*
push_chunk_first.c
*/
void	first_chunk(t_program *p);

/*
other_chunks.c
*/
void	smallest_push(t_program *p, t_hold num);

/*
set_location.c
*/
void	loc_helper(t_program *p, t_hold *num);
void	second_help(t_program *p, t_hold *num);
void	loc_b_helper(t_program *p, t_hold *num);
void	set_chunk_location(t_program *p, t_hold *num);
void	set_location_simple(t_program *p, t_hold num);

/*
rrb_chunk.c
*/
int		opt(t_program *p, t_hold *num, \
t_hold *next_hold, int *complete_distance);
int		rrb_chunk(t_program *p, t_hold *num, int *complete_distance);
void	solve_intermediate(t_program *p, t_hold *num);
void	chunk_solver(t_program *p);

/*
t_hold_init.c
*/
t_hold	init_hold(void);

/*
-----Reverse-----
*/

/*
intermediate_bigger_reverse.c
*/
void	rda_more_midpoint(t_program *p);
void	rdb_more_midpoint(t_program *p);
void	rdc_more_midpoint(t_program *p);

/*
intermediate_reverse.c
*/
void	rdb_smaller(t_program *p);
void	rdc_smaller(t_program *p);
void	rda_smaller(t_program *p);
/*
intermediate_smaller_reverse.c
*/
void	rda_less_midpoint(t_program *p);
void	rdb_less_midpoint(t_program *p);
void	rdc_less_midpoint(t_program *p);

/*
inverse_sort.c
*/
void	sort_inverse_top(t_program *p);
void	sort_inverse_inter(t_program *p);
void	sort_inverse_end(t_program *p);
void	sort_inverse_initial(t_program *p);
void	ft_sort_inverse(t_program *p);
/*
reverse_base_cases.c
*/
void	sort_three_reverse_helper(t_program *p);
void	ft_sort_three_reverse(t_program *p);
void	ft_rbase_case_two(t_program *p);
void	ft_rbase_case_one(t_program *p);
/*
reverse_distance.c
*/
void	ft_distance_reverse(t_program *p);
void	ft_rda(t_program *p);
void	ft_rdb(t_program *p);
void	ft_rdc(t_program *p);
/*
top_stack_reverse.c
*/
void	reverse_top_stack_a(t_program *p);
void	reverse_top_stack_b(t_program *p);
void	reverse_top_stack_c(t_program *p);
/*
to_stackb.c
*/
void	pb_stackb(t_program *p);

/*
-----Set up-----
*/

/*
lnkdlst_setup.c
*/

/*
printer_setup.c
*/

/*
stacK_setup.c
*/

/*
stack_values.c
*/

void	ft_val_updta(t_program *p);
void	ft_val_updtb(t_program *p);

/*
-----Utils-----
*/

/*
check_error.c
*/
int	check_numbers(int ac, char **av);
int	check_arguments(int ac, char **av);

/*
utils.c
*/
/*
utils2.c
*/
int	ft_isdigit(int c);
t_stack	init_stack(int ac);
t_stack	ft_stack_populate(t_stack *stack, char **av, int size);
t_info	init_printer(t_stack stacka, t_stack stackb);
void	update_printer(t_program *p, char *move);
void	ft_printer(t_info printer);
void	initial_print(t_info printer);
bool	ft_check_sorted(t_stack stack);
bool	ft_check_sorted_reverse(t_stack stack);
int		ft_atoi(const char *str);
void	ft_putstr(char const *s);
void	ft_putneg(unsigned int n);
void	ft_putnbr(int i);
int		ft_max(int a, int b);
void	ft_putchar(char c);

#endif
