/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 01:42:39 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 00:00:53 by bfleitas         ###   ########.fr       */
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

void	ft_listclear(t_list **lst)
{
	t_list	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	run_swap_op(char *op, t_list **top_stack_a, t_list **top_stack_b)
{
	if (op[1] == 'a')
		sa(top_stack_a);
	else if (op[1] == 'b')
		sb(top_stack_b);
	else
		ss(top_stack_a, top_stack_b);
}

void	run_push_op(char *op, t_list **top_stack_a, t_list **end_stack_a, t_list **top_stack_b, t_list **end_stack_b)
{
	if (op[1] == 'a')
		pa(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
	else if (op[1] == 'b')
		pb(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
}

void	run_rev_rot_op(char *op, t_list **top_stack_a, t_list **end_stack_a, t_list **top_stack_b, t_list **end_stack_b)
{
	if (op[2] == 'a')
		rra(top_stack_a, end_stack_a);
	else if (op[2] == 'b')
		rrb(top_stack_b, end_stack_b);
	else
		rrr(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
}

void	run_rot_op(char *op, t_list **top_stack_a, t_list **end_stack_a, t_list **top_stack_b, t_list **end_stack_b)
{
	if (op[1] == 'a')
		ra(top_stack_a, end_stack_a);
	else if (op[1] == 'b')
		rb(top_stack_b, end_stack_b);
	else
		rr(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
}

void	run_operation(char *op, t_list **top_stack_a, t_list **end_stack_a, t_list **top_stack_b, t_list **end_stack_b)
{
	if (op[0] == 's')
		run_swap_op(op, top_stack_a, top_stack_b);
	else if (op[0] == 'p')
		run_push_op(op, top_stack_a, end_stack_a, top_stack_b, end_stack_b);
	else if ((op[0] == 'r') && (op[1] == 'r'))
		run_rev_rot_op(op, top_stack_a, end_stack_a, top_stack_b, end_stack_b);
	else
		run_rot_op(op, top_stack_a, end_stack_a, top_stack_b, end_stack_b);
}

void	checker_algorithm(t_list **top_stack_a, t_list **end_stack_a)
{
	char	*gnl;
	t_list	*top_stack_b;
	t_list	*end_stack_b;

	top_stack_b = NULL;
	end_stack_b = NULL;
	gnl = get_next_line(0); //VER FD
	while (gnl)
	{
		run_operation(gnl, top_stack_a, end_stack_a, &top_stack_b, &end_stack_b);
		free (gnl);
		gnl = get_next_line(0);
	}
	if (check_if_is_it_sorted(top_stack_a) && (!top_stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_listclear(top_stack_a);
	ft_listclear(&top_stack_b);
}

void	case_argv_2_checker(char **argv)
{
	int		error;
	t_list	*top_stack_a;
	t_list	*end_stack_a;

	top_stack_a = NULL;
	end_stack_a = NULL;
	error = create_structure_str(argv[1], &top_stack_a, &end_stack_a);
	if (error)
		write(2, "Error\n", 6);
	else
	{
		ranking_structure(&top_stack_a);
		checker_algorithm(&top_stack_a, &end_stack_a);
	}
}

void	case_argv_more_2_checker(int argc, char **argv)
{
	int		error;
	t_list	*top_stack_a;
	t_list	*end_stack_a;

	top_stack_a = NULL;
	end_stack_a = NULL;
	error = create_structure(argc, argv, &top_stack_a, &end_stack_a);
	if (error)
		write(2, "Error\n", 6);
	else
	{
		ranking_structure(&top_stack_a);
		checker_algorithm(&top_stack_a, &end_stack_a);
	}
}
/**/
int	main(int argc, char **argv)
{
//	int		argc = 2;
//	char	*argv[] = {"program", "1 3 2"};

//	ARG="2 3 1" ; echo rra | ./checker $ARG
//	int fd = open("./fd.txt", O_RDONLY);
//	if (fd == -1)
//		return(1);
	if (argc == 2)
		case_argv_2_checker(argv);
	if (argc > 2)
		case_argv_more_2_checker(argc, argv);
	return (1);
}
/**/
