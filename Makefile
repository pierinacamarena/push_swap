# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 19:34:42 by pcamaren          #+#    #+#              #
#    Updated: 2021/10/05 17:40:37 by pcamaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRC = src/algorithm/push_swap.c \
		src/algorithm/stackA_moves.c \
		src/algorithm/stack_moves_helper.c \
		src/algorithm/stackB_moves.c \
		src/algorithm/stack_rr_moves.c \
		src/algorithm/stack_rrr_moves.c \
		src/chunking/chunking.c \
		src/dirty_sort/dirty_sort.c \
		src/indexing/indexing.c \
		src/mark_up/markup.c \
		src/mark_up/markup_greater.c \
		src/mark_up/markup_index.c \
		src/mark_up/markup_utils.c \
		src/normal/intermediate.c \
		src/normal/intermediate_helper_less.c \
		src/normal/intermediate_helper_bigger.c \
		src/normal/distances.c \
		src/normal/sort_base_cases.c \
		src/normal/sort_stack.c \
		src/normal/sort_stack_helpers.c \
		src/normal/top_stack.c \
		src/optimization/optimization.c \
		src/optimization/r_optimization.c \
		src/optimization/optimization_less.c \
		src/optimization/r_optimization_less.c \
		src/optimization/optimization_loop.c \
		src/optimization/optimization_less_loop.c \
		src/printing/debug_functions.c \
		src/printing/printer.c \
		src/printing/printer_helper.c \
		src/push_to_a/solve_b.c \
		src/push_to_b/first_chunk_helper.c \
		src/push_to_b/choose_push.c \
		src/push_to_b/push_chunk.c \
		src/push_to_b/push_chunk_helper.c \
		src/push_to_b/pushtob_utils.c \
		src/push_to_b/push_chunk_first.c \
		src/push_to_b/other_chunks.c \
		src/push_to_b/rrb_chunk.c \
		src/push_to_b/set_location.c \
		src/push_to_b/t_hold_init.c \
		src/reverse/intermediate_reverse.c \
		src/reverse/intermediate_bigger_reverse.c \
		src/reverse/intermediate_smaller_reverse.c \
		src/reverse/top_stack_reverse.c \
		src/reverse/inverse_sort.c \
		src/reverse/reverse_base_cases.c \
		src/reverse/reverse_distance.c \
		src/reverse/to_stackb.c \
		src/set_up/printer_setup.c \
		src/set_up/stack_values.c \
		src/set_up/stack_setup.c \
		src/utils/cleaner.c \
		src/utils/utils2.c \
		src/utils/utils.c \

OBJ		= $(SRC:.c=.o)

CC		= gcc -g

FLAGS	= -Werror -Wall -Wextra

INC		= -I includes/

RM		= rm -f

all :			$(NAME)

$(NAME) :		$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC)
clean :
			$(RM) $(OBJ)

fclean :		clean
			$(RM) $(NAME)

re :			fclean all

.PHONY : clean fclean all re
