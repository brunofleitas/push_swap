/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:51 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/15 14:33:09 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    lst: A pointer to the head node of the linked list to clear.
  Return value:
    None. This function modifies the original linked list in place.
  Description:
    This function clears a linked list starting from its head node.
	It iterates through the list, freeing each node until the entire
	list is cleared. After this operation, the original linked list will
	have been emptied, and all nodes previously allocated will have been freed.
*/
void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

/*
  Parameters:
    argv: An array of pointers to null-terminated character strings 
	representing the command-line arguments. This function specifically uses
	 the second argument (argv[1]) as input.
  Return value:
    None.
  Description:
    This function is designed to handle cases where the program receives 
	exactly one command-line argument. It performs several steps:
    1. Initializes variables for error handling and stack management.
    2. Calls `create_structure_str` to initialize and populate the stack a 
	(`top_stack_a` and `end_stack_a`) based on the single command-line argument
	provided. If an error occurs during this process, it writes an error 
	message to standard error.
    3. If the structure creation is successful, it proceeds to rank the 
	structure using `ranking_structure`.
    4. Executes the main algorithm of the program using `main_algorithm`, 
	passing the initialized stacks as parameters.
    5. Cleans up memory allocated to `top_stack_a` using `ft_lstclear`.
*/

void	case_argv_2(char **argv)
{
	int		error;
	t_list	*top_stack_a;
	t_list	*end_stack_a;
	t_list	*top_stack_b;
	t_list	*end_stack_b;

	top_stack_a = NULL;
	end_stack_a = NULL;
	top_stack_b = NULL;
	end_stack_b = NULL;
	error = create_structure_str(argv[1], &top_stack_a, &end_stack_a);
	if (error)
		write(2, "Error\n", 6);
	else
	{
		ranking_structure(&top_stack_a);
		main_algorithm(&top_stack_a, &end_stack_a, &top_stack_b, &end_stack_b);
	}
	ft_lstclear(&top_stack_a);
}

/*
  Parameters:
    argc: The count of command-line arguments passed to the program.
    argv: An array of pointers to null-terminated character strings 
	representing the command-line arguments.
  Return value:
    None.
  Description:
    This function is designed to handle cases where the program receives 
	more than one command-line argument. It performs several steps:
    1. Initializes variables for error handling and stack management.
    2. Calls `create_structure` to initialize and populate the stack a 
	(`top_stack_a` and `end_stack_a`). 
	If an error occurs during this process, it writes an error message 
	to standard error.
    3. If the structure creation is successful, it proceeds to rank the 
	structure using `ranking_structure`.
    4. Executes the main algorithm of the program using `main_algorithm`, 
	passing the initialized stacks as parameters.
    5. Cleans up memory allocated to `top_stack_a` using `ft_lstclear`.
*/

void	case_argv_more_2(int argc, char **argv)
{
	int		error;
	t_list	*top_stack_a;
	t_list	*end_stack_a;
	t_list	*top_stack_b;
	t_list	*end_stack_b;

	top_stack_a = NULL;
	end_stack_a = NULL;
	top_stack_b = NULL;
	end_stack_b = NULL;
	error = create_structure(argc, argv, &top_stack_a, &end_stack_a);
	if (error)
		write(2, "Error\n", 6);
	else
	{
		ranking_structure(&top_stack_a);
		main_algorithm(&top_stack_a, &end_stack_a, &top_stack_b, &end_stack_b);
	}
	ft_lstclear(&top_stack_a);
}

/*
  Parameters:
    argc: The count of command-line arguments passed to the program.
    argv: An array of pointers to null-terminated character strings 
	representing the command-line arguments.
  Return value:
    1: Indicates that the program has completed execution successfully.
  Description:
    This is the main entry point of the program. Depending on the number of
	command-line arguments received, it calls different functions to handle 
	these arguments appropriately. 
    - If exactly one argument is provided, it calls `case_argv_2`.
    - If more than one argument is provided, it calls `case_argv_more_2`.
    The return value of 1 indicates successful completion of the 
	program's logic.
*/
int	main(int argc, char **argv)
{
	if (argc == 2)
		case_argv_2(argv);
	if (argc > 2)
		case_argv_more_2(argc, argv);
	return (1);
}
