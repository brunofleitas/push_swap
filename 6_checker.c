/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 01:42:39 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 02:31:51 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
/*
#include "1_main.c"
#include "2_compute_string.c"
#include "2_generate_list.c"
#include "2_generating_utils.c"
#include "3_ranking.c"
#include "4_push_operations.c"
#include "4_reverse_rotate_operations.c"
#include "4_rotate_operations.c"
#include "4_swap_operations.c"
#include "5_algorithm.c"
#include "5_algorithm_utils.c"
#include "5_calculate_average.c"
#include "5_find_lower_cost.c"
#include "5_main_algorithm_utils.c"
#include "5_sorting_three_and_five.c"
#include "get_next_line.c"
#include "get_next_line_utils.c"
*/

/*
  Parameters:
    op: String representing the operation to perform.
    top_stack_a, end_stack_a: Pointers to the head and tail of the first linked
	list.
    top_stack_b: Pointer to the head of the second linked list.
  Description:
    Executes different operations based on the first character of the string op
    Supports swap ('s'), push ('p'), reverse rotate ('rr'), and regular rotate
	('r' & 'a', 'b', 'r').
*/
void	run_operation(char *op, t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b)
{
	if (op[0] == 's')
		run_swap_op(op, top_stack_a, top_stack_b);
	else if (op[0] == 'p')
		run_push_op(op, top_stack_a, end_stack_a, top_stack_b);
	else if ((op[0] == 'r') && (op[1] == 'r') && (op[2] != '\n'))
		run_rev_rot_op(op, top_stack_a, end_stack_a, top_stack_b);
	else if ((op[0] == 'r') && (op[1] == 'a' || op[1] == 'b' || op[1] == 'r'))
		run_rot_op(op, top_stack_a, end_stack_a, top_stack_b);
}

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of the first linked
	list.
    top_stack_b: Pointer to the head of the second linked list.
  Description:
    Executes operations based on lines read from standard input.
    Checks if the first stack is sorted and if the second stack is empty.
    Outputs "OK" if conditions are met, "KO" otherwise.
    Clears both stacks after checking.
*/
void	checker_algorithm(t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b)
{
	char	*gnl;

	*top_stack_b = NULL;
	gnl = get_next_line(0);
	while (gnl)
	{
		run_operation(gnl, top_stack_a, end_stack_a, top_stack_b);
		free(gnl);
		gnl = get_next_line(0);
	}
	if (check_if_is_it_sorted(top_stack_a) && (!*top_stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_listclear(top_stack_a);
	ft_listclear(top_stack_b);
}

/*
  Parameters:
    argv: Array of command-line arguments.
  Description:
    Processes the second command-line argument specifically.
    Creates a linked list structure based on the argument.
    If successful, performs ranking and checks the algorithm.
*/
void	case_argv_2_checker(char **argv)
{
	int		error;
	t_list	*top_stack_a;
	t_list	*end_stack_a;
	t_list	*top_stack_b;

	top_stack_a = NULL;
	end_stack_a = NULL;
	top_stack_b = NULL;
	error = create_structure_str(argv[1], &top_stack_a, &end_stack_a);
	if (error)
		write(2, "Error\n", 6);
	else
	{
		ranking_structure(&top_stack_a);
		checker_algorithm(&top_stack_a, &end_stack_a, &top_stack_b);
	}
}

/*
  Parameters:
    argc: Number of command-line arguments.
    argv: Array of command-line arguments.
  Description:
    Processes command-line arguments beyond the first two.
    Creates a linked list structure based on the arguments.
    If successful, performs ranking and checks the algorithm.
*/
void	case_argv_more_2_checker(int argc, char **argv)
{
	int		error;
	t_list	*top_stack_a;
	t_list	*end_stack_a;
	t_list	*top_stack_b;

	top_stack_a = NULL;
	end_stack_a = NULL;
	top_stack_b = NULL;
	error = create_structure(argc, argv, &top_stack_a, &end_stack_a);
	if (error)
		write(2, "Error\n", 6);
	else
	{
		ranking_structure(&top_stack_a);
		checker_algorithm(&top_stack_a, &end_stack_a, &top_stack_b);
	}
}

/*
  Parameters:
    argc: Argument count passed to the program.
    argv: Array of arguments passed to the program.
  Return value:
    1: Indicates successful execution.
  Description:
    Handles different scenarios based on the number of command-line arguments
	received.
    Calls appropriate function based on the number of arguments.
*/
int	main(int argc, char **argv)
{
	if (argc == 2)
		case_argv_2_checker(argv);
	if (argc > 2)
		case_argv_more_2_checker(argc, argv);
	return (1);
}

/*
		ARG="2 3 1" ; echo rra | ./checker $ARG
		int		argc = 2;
		char	*argv[] = {"program", "2 3 1 5 4"};
		int fd = open("./fd.txt", O_RDONLY);
		if (fd == -1)
			return(1);
*/
