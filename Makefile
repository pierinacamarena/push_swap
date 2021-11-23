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

SRC = src/algo_helpers.c \
	  	src/algo_helpers_reverse.c \
		src/cleaner.c \
		src/debug_functions.c \
		src/inverse_sort.c \
		src/lnkdlst_setup.c \
		src/printer.c \
		src/printer_setup.c \
		src/push_swap.c \
		src/reverse_distance.c \
		src/sort_base_cases.c \
		src/sort_stack.c \
		src/stackA_moves.c \
		src/stackB_moves.c \
		src/stack_setup.c \
		src/stack_values.c \
		src/utils2.c \
		src/utils.c

OBJ		= $(SRC:.c=.o)

CC		= gcc

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
