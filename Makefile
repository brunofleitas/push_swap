# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 02:39:48 by bfleitas          #+#    #+#              #
#    Updated: 2024/05/17 02:51:42 by bfleitas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

RM	= rm -rf

LIBC	= ar rcs

SRCS	= 1_main.c \
		2_compute_string.c 2_generate_list.c 2_generating_utils.c\
		3_ranking.c \
		4_push_operations.c 4_reverse_rotate_operations.c \
		4_rotate_operations.c 4_swap_operations.c \
		5_algorithm.c 5_algorithm_utils.c 5_calculate_average.c \
		5_find_lower_cost.c 5_main_algorithm_utils.c \
		5_sorting_three_and_five.c

SRCSB	=  6_checker.c \
		2_compute_string.c 2_generate_list.c 2_generating_utils.c\
		3_ranking.c \
		4_push_operations.c 4_reverse_rotate_operations.c \
		4_rotate_operations.c 4_swap_operations.c \
		5_algorithm.c 5_algorithm_utils.c 5_calculate_average.c \
		5_find_lower_cost.c 5_main_algorithm_utils.c \
		5_sorting_three_and_five.c\
		get_next_line.c get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

OBJSB	= $(SRCSB:.c=.o)

NAME	= push_swap.a

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

.c.o: 
	$(CC) $(CFLAGS) -c $< -o  ${<:.c=.o}

bonus: $(NAME) $(OBJSB)
	$(LIBC) $(NAME) $(OBJSB)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(bonus)

re: fclean all

.PHONY: all bonus clean fclean re