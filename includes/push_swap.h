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
  char		move[4];

} t_info;

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
void	ft_print_stack (t_stack stack);
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
void	ft_distance_reverse (t_stack *stacka, t_stack *stackb);
void	ft_rda (t_stack *stacka, t_stack *stackb);
void	ft_rdb (t_stack *stacka, t_stack *stackb);
void	ft_rdc (t_stack *stacka, t_stack *stackb);
void	ft_val_updta (t_stack * stacka);
void	ft_val_updtb (t_stack * stackb);
void	ft_distance (t_stack *stacka, t_stack *stackb);
void	ft_print_full_stack (t_stack stacka, t_stack stackb, int j);
void	ft_print_distances (t_stack stacka, int j);
void	ft_simple_print (t_stack stacka, t_stack stackb);
int	ft_base_case_two (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_base_case_one (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_top_stack_a (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_top_stack_b (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_top_stack_c (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_db_smaller (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_dc_smaller (t_stack *stacka, t_stack *stackb, t_info *printer);
int	ft_da_smaller (t_stack *stacka, t_stack *stackb, t_info *printer);
void	ft_da (t_stack *stacka, t_stack *stackb);
void 	ft_db (t_stack *stacka, t_stack *stackb);
void	ft_dc (t_stack *stacka, t_stack *stackb);
int	ft_atoi (const char *str);
void	ft_putstr (char const *s);
int 	ft_rbase_case_two (t_stack * stacka, t_stack * stackb, t_info *printer);
int	ft_rbase_case_one (t_stack * stacka, t_stack * stackb, t_info *printer);
void	ft_putneg(unsigned int n);
void	ft_putnbr(int i);
int	ft_max(int a, int b);
void	ft_putchar(char c);
void	ft_print_distances_b(t_stack stackb);
#endif
