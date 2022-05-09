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
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_stack
{
  int size;
  int midpoint;
  int a;
  int b;
  int c;
  int x;
  int y;
  int *array;
  int max_size;
  int d_a;
  int d_b;
  int d_c;
} t_stack;

typedef struct s_dirtysort
{
  int i;
  int j;
  int k;
  int n1;
  int n2;
  int *larr;
  int *rarr;
} t_dirtysort;


typedef struct s_chunk
{
  int *chunks;
  int *chunk_size;
  int splits;
  int current_chunk;
  int push_nums;
  int rrbs;
} t_chunk;

typedef struct s_hold
{
  int   number;
  int   moves;
  char  location;
  int   distance;
} t_hold;

typedef struct s_info 
{
  t_stack	stacka;
  t_stack	stackb;
  int		lena;
  int		lenb;
  int   count;
  char		move[4];

} t_info;

typedef struct s_program
{
  t_stack stacka;
  t_stack stackb;
  t_info  printer;
  t_chunk chunking;
} t_program;


/*
-----Algorithm-----
*/

/*
push_swap.c
*/
//void	sort_stack(t_stack *stacka, t_stack *stackb, t_info *printer);
void	sort_stack(t_program *p);

/*
stack_moves_helper.c
*/

/*
stackA_moves.c
*/
int	ft_temp_sa(t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_sa (t_program *p);
int	ft_ra (t_program *p);
int	ft_rra (t_program *p);
int	ft_pa (t_program *p);
void  ft_pa_helper(t_program *p);

/*
stackB_moves.c
*/
int	ft_sb (t_program *p);
int	ft_rb (t_program *p);
int	ft_rrb (t_program *p);
int	ft_pb (t_program *p);
void  ft_pb_helper(t_program *p);

/*
stack_rr_moves.c
*/
int ft_rr(t_program *p);
int ft_ra_rr(t_program *p);
int ft_rb_rr(t_program *p);

/*
stack_rrr_moves.c
*/
int ft_rrr(t_program *p);
int ft_rra_rrr(t_program *p);
int ft_rrb_rrr(t_program *p);

/*
-----Chunking-----
*/

/*
chunking.c
*/

t_chunk   split_choice(t_stack stacka, int *arr);
t_chunk   splitter(t_stack stacka, int n, int *arr);
void      set_size_chunks(t_chunk *chunking, t_stack stacka, int n);
int       has_chunk(t_stack stacka, t_chunk chunking, int n);     

/*
-----Dirty_Sort-----
*/

/*
dirty_sort.c
*/
int *dirty_sorting(t_program p);

/*
merge_sort.c
*/
int *quickmergesort(t_stack stacka);

/*
-----Indexing----
*/

/*
indexing.c
*/
int     index_finder(t_stack stacka, int numb);
void  set_index(int *arr, t_stack *stacka);
int  *indexing(t_program p);

/*
-----Mark_up-----
*/

/*
markup.c
*/
void  markup(t_stack *stacka);
void  temp_markup(t_stack *stacka);
void  printer_markup(t_stack stacka, int *counter_i, int *counter_g);
void  print_final_markup(t_stack stacka);
char  markup_choice(int *counter_i, int *counter_g, int size);

/*
markup_greater.c
*/
int     markup_head_count(t_stack stacka, int index);
int     head_finder_greater(int *counter, int size);
int     *head_greater_counter(t_stack stacka);
int     *greater_temp_selection(t_stack *stacka, int index);
void  greater_selection(t_stack *stacka, int index);

/*
markup_index.c
*/
int     index_head_count(t_stack stacka, int index);
int     head_finder_index(int *counter, int size);
int     *head_index_counter(t_stack stacka);
int     *index_temp_selection(t_stack *stacka, int index);
void  index_selection(t_stack *stacka, int index);


/*
markup_utils.c
*/
int index_value_finder(t_stack stacka, int index);
int find_max(int *array, int len);
int find_min(int *array, int len);
int multiple_max(int *counter, int head, int size);
int temp_stay_a(t_stack stacka);

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
int	ft_sort_three (t_program *p);
int   ft_sort_three_helper(t_program *p);
int	ft_base_case_two (t_program *p);
int	ft_base_case_one (t_program *p);

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

int optim_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int optim(t_stack *stacka, t_stack *stackb, t_info *printer);
int optim_a(t_stack *stacka, t_stack *stackb, t_info *printer);
int optim_b(t_stack *stacka, t_stack *stackb, t_info *printer);
int optim_c(t_stack *stacka, t_stack *stackb, t_info *printer);

/*
r_optimization.c
*/

int r_optim_checker(t_program *p);
int r_optim(t_program *p);
int r_optim_a(t_program *p);
int r_optim_b(t_program *p);
int r_optim_c(t_program *p);

/*
optimization_less.c
*/

int optim_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int optim_less(t_stack *stacka, t_stack *stackb, t_info *printer, int *new_rb);
int optim_less_a(t_stack *stacka, t_stack *stackb, t_info *printer);
int optim_less_b(t_stack *stacka, t_stack *stackb, t_info *printer);
int optim_less_c(t_stack *stacka, t_stack *stackb, t_info *printer);

/*
r_optimization_less.c
*/

int r_optim_less_checker(t_program *p);
int r_optim_less(t_program *p, int *new_ra);
int r_optim_less_a(t_program *p);
int r_optim_less_b(t_program *p);
int r_optim_less_c(t_program *p);

/*
optimization_loop.c
*/
int optima_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int optimb_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int optimc_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
/*
optimization_less_loop.c
*/
int optima_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int optimb_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int optimc_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer);

/*
-----Printing-----
*/

int   printer_diff_len(t_info printer);
int   printer_difflen_b(t_info printer);
int   printer_same_len(t_info printer, int len);
int   printer_final_print(t_info printer, int i, int len);
int   printer_final_b(t_info printer, int i, int len);
void  printer_initial_setup(t_info printer);

/*
debug_functions.c
*/

void	ft_print_distances_b(t_stack stackb);
void	ft_print_distances (t_stack stacka);

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

int solve_b(t_program *p);

/*
-----Push_to_b------
*/

/*
first_chunk_helper.c
*/
int middle_helper(t_program *p, t_hold num);

/*
push_to_b.c
*/

void  push_to_b(t_stack *stacka, t_stack *stackb, t_info *printer);
int     check_stacka(t_stack stacka);
int     sa_check(t_stack *stacka, t_stack *stackb, t_info *printer);

/*
push_chunk.c
*/
int    solve_a(t_program *p);
int    solve_first_chunk(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk chunking);

/*
choose_push.c
*/
t_hold  find_top_num(t_program *p, int border);
t_hold  find_lower_num(t_program  *p, int border);
int choose_push_helper(t_program *p, t_hold one, t_hold two);
int     choose_push(t_program *p, int *chunks);

/*
push_chunk_helper.c
*/
t_hold	same_moves(t_hold one, t_hold two);
t_hold  choose_number(t_program *p, int chunk);
int     solve_other_chunk(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking);
char    chunk_checker(t_stack stacka, t_chunk chunking);
int    solve_other_chunk_v2(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking);

/*
push_chunk_optimization.c
*/
int optim_higher_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking);
int optim_smaller(t_stack *stacka, t_stack *stackb, t_info *printer, t_chunk *chunking);

/*
pushtob_utils.c
*/
int distance(t_program p, t_hold num);
int optim_distance(t_program p, t_hold num);
int expected_stackbsize(t_chunk chunking);
int	rrb_helper_extra(t_program *p, int *complete_distance);

/*
push_chunk_first.c
*/
int    first_chunk(t_program *p);

/*
other_chunks.c
*/
int smallest_push(t_program *p, t_hold num);
int mid_push(t_stack *stacka, t_stack *stackb, t_info *printer, t_hold *num, t_chunk *chunking);

/*
set_location.c
*/
int	loc_helper(t_program *p, t_hold *num);
int	second_help(t_program *p, t_hold *num);
int	loc_b_helper(t_program *p, t_hold *num);
int set_chunk_location(t_program *p, t_hold *num);
int set_location_simple(t_program *p, t_hold num);

/*
rrb_chunk.c
*/
int opt(t_program *p, t_hold *num, t_hold *next_hold, int *complete_distance);
int rrb_chunk(t_program *p, t_hold *num, int *complete_distance);
int solve_intermediate(t_program *p, t_hold *num);
int chunk_solver(t_program *p);

/*
t_hold_init.c
*/
t_hold  init_hold(void);

/*
-----Reverse-----
*/

/*
intermediate_bigger_reverse.c
*/
int   rda_more_midpoint(t_program *p);
int   rdb_more_midpoint(t_program *p);
int	  rdc_more_midpoint(t_program *p);

/*
intermediate_reverse.c
*/
int	rdb_smaller (t_program *p);
int	rdc_smaller (t_program *p);
int	rda_smaller (t_program *p);
/*
intermediate_smaller_reverse.c
*/
int   rda_less_midpoint(t_program *p);
int   rdb_less_midpoint(t_program *p);
int	  rdc_less_midpoint(t_program *p);

/*
inverse_sort.c
*/
int	sort_inverse_top(t_program *p);
int	sort_inverse_inter(t_program *p);
int	sort_inverse_end(t_program *p);
int	sort_inverse_initial(t_program *p);
int	ft_sort_inverse (t_program *p);
/*
reverse_base_cases.c
*/
int sort_three_reverse_helper(t_program *p);
int	ft_sort_three_reverse (t_program *p);
int 	ft_rbase_case_two (t_program *p);
int	  ft_rbase_case_one (t_program *p);
/*
reverse_distance.c
*/
void	ft_distance_reverse (t_program *p);
void	ft_rda (t_program *p);
void	ft_rdb (t_program *p);
void	ft_rdc (t_program *p);
/*
top_stack_reverse.c
*/
int	reverse_top_stack_a (t_program *p);
int	reverse_top_stack_b (t_program *p);
int	reverse_top_stack_c (t_program *p);
/*
to_stackb.c
*/
int pb_stackb(t_program *p);

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

void	ft_val_updta (t_program *p);
void	ft_val_updtb (t_program *p);

/*
-----Utils-----
*/

/*
cleaner.c
*/

/*
utils.c
*/

/*
utils2.c
*/
t_stack	init_stack (int ac);
t_stack	ft_stack_populate (t_stack *stack, char **av, int size);
t_info	init_printer(t_stack stacka, t_stack stackb);
void	update_printer(t_program *p, char *move);
void	ft_printer(t_info printer);
void	initial_print(t_info printer);
bool	ft_check_sorted (t_stack stack);
bool	ft_check_sorted_reverse (t_stack stack);
int	ft_sort_stack (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_sort_main_algo (t_stack *stacka, t_stack *stackb, t_info *printer);
void	ft_print_stack (t_stack stack);
void	ft_distance (t_stack *stacka, t_stack *stackb);
void	ft_print_full_stack (t_stack stacka, t_stack stackb, int j);
void	ft_simple_print (t_stack stacka, t_stack stackb);

int	ft_top_stack_a (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_top_stack_b (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_top_stack_c (t_stack *stacka, t_stack *stackb, t_info *printer);
int	  ft_db_smaller (t_stack *stacka, t_stack *stackb, t_info *printer);
int	  ft_dc_smaller (t_stack *stacka, t_stack *stackb, t_info *printer);
int	  ft_da_smaller (t_stack *stacka, t_stack *stackb, t_info *printer);
void	ft_da (t_stack *stacka, t_stack *stackb);
void 	ft_db (t_stack *stacka, t_stack *stackb);
void	ft_dc (t_stack *stacka, t_stack *stackb);
int	  ft_atoi (const char *str);
void	ft_putstr (char const *s);
void	ft_putneg(unsigned int n);
void	ft_putnbr(int i);
int	  ft_max(int a, int b);
void	ft_putchar(char c);
int   da_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int   db_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int   dc_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int   da_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int   db_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int   dc_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);

int   algo_helper_top(t_stack *stacka, t_stack *stackb, t_info *printer);
int   algo_helper_intermediate(t_stack *stacka, t_stack *stackb, t_info *printer);
int	  algo_helper_begin(t_stack *stacka, t_stack *stackb, t_info *printer);
int   algo_helper_end(t_stack *stacka, t_stack *stackb, t_info *printer);

#endif
