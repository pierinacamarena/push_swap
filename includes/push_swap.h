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
  int *index;
  int *original_index;
  int max_size;
  int d_a;
  int d_b;
  int d_c;
} t_stack;

/**
struct LinkedList
{
	int	data;
	struct	LinkedLIst *next;
};

typedef struct *node;

*/
typedef struct s_info 
{
  t_stack	stacka;
  t_stack	stackb;
  int		lena;
  int		lenb;
  int   count;
  char		move[4];

} t_info;

typedef struct markup
{
  int *indexed;
  int *
}

/*
-----Algorithm-----
*/

/*
push_swap.c
*/

/*
stack_moves_helper.c
*/

/*
stackA_moves.c
*/

/*
stackB_moves.c
*/

/*
-----Dirty_Sort-----
*/

/*
dirty_sort.c
*/
t_stack dirty_sorting(t_stack stacka);

/*
-----Indexing----
*/

/*
index.c
*/
int *indexing(t_stack *stacka);
//int find_min(t_stack *stacka);
int find_indices(t_stack *stacka, int *processed, int len);
int check_min(int *processed, int len, int i);

/*
indexing.c
*/
int index_finder(t_stack stacka, int numb);
int *set_index(t_stack arr, t_stack stacka);

/*
-----Mark_up-----
*/

/*
markup.c
*/
void    markup(t_stack *stacka);
char markup_choice(int *counter_i, int *counter_g, int size);

/*
markup_greater.c
*/
int markup_head_count(t_stack stacka, int index);
int find_head_greater(t_stack stacka);
int head_finder_greater(int *counter, int size);
void greater_selection(t_stack *stacka, int index);

/*
markup_index.c
*/
int index_head_count(t_stack stacka, int index);
int find_head_index(t_stack stacka);
int head_finder_index(int *counter, int size);
void index_selection(t_stack *stacka, int index);


/*
markup_utils.c
*/
int index_value_finder(t_stack stacka, int index);
int find_max(int *array, int len);
int find_min(int *array, int len);
int multiple_max(int *counter, int head, int size);

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

int r_optim_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int r_optim(t_stack *stacka, t_stack *stackb, t_info *printer);
int r_optim_a(t_stack *stacka, t_stack *stackb, t_info *printer);
int r_optim_b(t_stack *stacka, t_stack *stackb, t_info *printer);
int r_optim_c(t_stack *stacka, t_stack *stackb, t_info *printer);

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

int r_optim_less_checker(t_stack *stacka, t_stack *stackb, t_info *printer);
int r_optim_less(t_stack *stacka, t_stack *stackb, t_info *printer, int *new_ra);
int r_optim_less_a(t_stack *stacka, t_stack *stackb, t_info *printer);
int r_optim_less_b(t_stack *stacka, t_stack *stackb, t_info *printer);
int r_optim_less_c(t_stack *stacka, t_stack *stackb, t_info *printer);

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
-----Reverse-----
*/

/*
intermediate_bigger_reverse.c
*/

/*
intermediate_reverse.c
*/

/*
intermediate_smaller_reverse.c
*/

/*
inverse_sort.c
*/
int	sort_inverse_top(t_stack *stacka, t_stack *stackb, t_info *printer);
int	sort_inverse_inter(t_stack *stacka, t_stack *stackb, t_info *printer);
int	sort_inverse_end(t_stack *stacka, t_stack *stackb, t_info *printer);
int	sort_inverse_initial(t_stack *stacka, t_stack *stackb, t_info *printer);
/*
reverse_base_cases.c
*/
int sort_three_reverse_helper(t_stack *stackb, t_stack *stacka, t_info *printer);
/*
reverse_distance.c
*/

/*
top_stack_reverse.c
*/

/*
to_stackb.c
*/
int pb_stackb(t_stack *stacka, t_stack *stackb, t_info *printer);

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
void	update_printer(t_stack stacka, t_stack stackb, t_info *printer, char *move);
void	ft_printer(t_info printer);
void	initial_print(t_info printer);
bool	ft_check_sorted (t_stack stack);
bool	ft_check_sorted_reverse (t_stack stack);
int	ft_sa (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_sb (t_stack *stackb, t_stack *stacka, t_info *printer);
int	ft_ra (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_rb (t_stack *stackb, t_stack *stacka, t_info *printer);
int	ft_rra (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_rrb (t_stack *stackb, t_stack *stacka, t_info *printer);
int	ft_pa (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_pb (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_sort_stack (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_sort_three (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_sort_three_reverse (t_stack *stackb, t_stack *stacka, t_info *printer);
int	ft_sort_main_algo (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_sort_inverse (t_stack *stacka, t_stack *stackb, t_info *printer);
int	reverse_top_stack_a (t_stack *stacka, t_stack *stackb, t_info *printer);
int	reverse_top_stack_b (t_stack *stacka, t_stack *stackb, t_info *printer);
int	reverse_top_stack_c (t_stack *stacka, t_stack *stackb, t_info *printer);
int	rdb_smaller (t_stack *stacka, t_stack *stackb, t_info *printer);
int	rdc_smaller (t_stack *stacka, t_stack *stackb, t_info *printer);
int	rda_smaller (t_stack *stacka, t_stack *stackb, t_info *printer);
void  ft_pa_helper(t_stack *stacka, t_stack *stackb);
void  ft_pb_helper(t_stack *stacka, t_stack *stackb);
void	ft_print_stack (t_stack stack);
void	ft_distance_reverse (t_stack *stacka, t_stack *stackb);
void	ft_rda (t_stack *stacka, t_stack *stackb);
void	ft_rdb (t_stack *stacka, t_stack *stackb);
void	ft_rdc (t_stack *stacka, t_stack *stackb);
int   rda_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int   rdb_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int	  rdc_more_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int   rda_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int   rdb_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
int	  rdc_less_midpoint(t_stack *stacka, t_stack *stackb, t_info *printer);
void	ft_val_updta (t_stack * stacka);
void	ft_val_updtb (t_stack * stackb);
void	ft_distance (t_stack *stacka, t_stack *stackb);
void	ft_print_full_stack (t_stack stacka, t_stack stackb, int j);
void	ft_simple_print (t_stack stacka, t_stack stackb);
int	ft_base_case_two (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_base_case_one (t_stack *stacka, t_stack *stackb, t_info *printer);
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
int 	ft_rbase_case_two (t_stack * stacka, t_stack * stackb, t_info *printer);
int	  ft_rbase_case_one (t_stack * stacka, t_stack * stackb, t_info *printer);
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
int   ft_sort_three_helper(t_stack *stacka, t_stack *stackb, t_info *printer);
int   algo_helper_top(t_stack *stacka, t_stack *stackb, t_info *printer);
int   algo_helper_intermediate(t_stack *stacka, t_stack *stackb, t_info *printer);
int	  algo_helper_begin(t_stack *stacka, t_stack *stackb, t_info *printer);
int   algo_helper_end(t_stack *stacka, t_stack *stackb, t_info *printer);
int   printer_diff_len(t_info printer);
int   printer_difflen_b(t_info printer);
int   printer_same_len(t_info printer, int len);
int   printer_final_print(t_info printer, int i, int len);
int   printer_final_b(t_info printer, int i, int len);
void  printer_initial_setup(t_info printer);
#endif
