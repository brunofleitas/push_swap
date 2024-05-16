/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_generate_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:56:27 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/15 14:56:43 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    nptr: A pointer to a null-terminated character string that represents an 
	integer number.
  Return value:
    The converted integer value if the conversion was successful, otherwise 0.
  Description:
    This function converts a string representation of an integer to an integer 
	value. It starts by skipping any leading whitespace characters and then 
	checks for optional sign characters ('-' or '+'). After processing the 
	sign, it reads the digits of the number sequentially, converting them to 
	their corresponding integer values. The function ensures that the resulting
	integer fits within the range of a signed long int 
	(-2147483648 to 2147483647). If the conversion would cause overflow or 
	underflow, the function returns 0. Otherwise, it returns the converted 
	integer value.
*/
int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] != 0 && ((nptr[i] == ' ') || (nptr[i] >= 9
				&& nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
		result = (nptr[i++] - '0') + (result * 10);
	result *= sign;
	if (result <= 2147483647 && result >= -2147483648)
		return ((int)result);
	else
		return (0);
}

/*
  Parameters:
    nbr: The integer value to search for in the linked list.
    top_of_stack: A pointer to the head node of the linked list.
  Return value:
    1: Indicates that the number was found in the linked list.
    0: Indicates that the number was not found in the linked list.
  Description:
    This function traverses the linked list starting from the head node 
	(`top_of_stack`). It compares each node's number with the target number 
	(`nbr`). If a match is found, it immediately returns 1. If the end of the 
	list is reached without finding a match, it returns 0.
*/
int	search_nbr_list(int nbr, t_list *top_of_stack)
{
	while (top_of_stack)
	{
		if (nbr == top_of_stack->number)
			return (1);
		top_of_stack = top_of_stack->next;
	}
	return (0);
}

/*
  Parameters:
    nbr: The integer value to be stored in the new node.
    end_of_stack: A double pointer to the last node of the linked list.
  Return value:
    A pointer to the newly added node. If memory allocation fails, NULL is 
	returned.
  Description:
    This function creates a new node with the given integer value and appends 
	it to the end of the linked list pointed to by `end_of_stack`. If the list 
	is not empty, the new node becomes the next node after the current last 
	node, and the previous pointer of the last node is set to the new node. If 
	the list is empty, the new node becomes the first node, and its previous 
	pointer is set to NULL. Finally, the `end_of_stack` pointer is updated to 
	point to the new node.
*/
t_list	*add_node_end(int nbr, t_list **end_of_stack)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->number = nbr;
	new_node->rank = 0;
	new_node->next = NULL;
	if (*end_of_stack)
	{
		new_node->prev = *end_of_stack;
		(*end_of_stack)->next = new_node;
	}
	else
		new_node->prev = NULL;
	*end_of_stack = new_node;
	return (new_node);
}

/*
  Parameters:
    argv: An array of pointers to null-terminated character strings 
	representing the command-line arguments.
    i: The index of the current argument being processed.
    top_of_stack: A double pointer to the head node of the first stack.
    end_of_stack: A double pointer to the head node of the second stack.
  Return value:
    ALL_GOOD: Indicates that the current argument was processed and added to 
	the stacks successfully.
    WRONG_INPUT: Indicates that the current argument could not be processed or 
	added to the stacks.
  Description:
    This function attempts to process the current command-line argument as 
	follows:
    1. If the argument is a single digit '0', it sets `nbr` to 0.
    2. Otherwise, it tries to convert the argument to an integer using 
	`ft_atoi`. If the conversion fails (returns 0), it considers this as wrong 
	input.
    3. It searches if the number exists in the list represented by 
	`top_of_stack`. If not found:
       - If `top_of_stack` is empty, it adds the number to the beginning of 
	   `end_of_stack`.
       - Else, it adds the number to the end of `end_of_stack`.
    4. Returns `ALL_GOOD` if the number was successfully added to the stacks, 
	otherwise `WRONG_INPUT`.
*/
int	process_input_and_stack(char **argv, int i, t_list **top_of_stack,
		t_list **end_of_stack)
{
	int	nbr;

	if (argv[i][0] == '0' && argv[i][1] == '\0')
		nbr = 0;
	else
	{
		nbr = ft_atoi(argv[i]);
		if (nbr == 0)
			return (WRONG_INPUT);
	}
	if (!search_nbr_list(nbr, *top_of_stack))
	{
		if (!*top_of_stack)
			*top_of_stack = add_node_end(nbr, end_of_stack);
		else
			*end_of_stack = add_node_end(nbr, end_of_stack);
		return (ALL_GOOD);
	}
	else
		return (WRONG_INPUT);
}

/*
  Parameters:
    argc: The count of command-line arguments passed to the program.
    argv: An array of pointers to null-terminated character strings 
	representing the command-line arguments.
    top_of_stack: A double pointer to the head node of the first stack.
    end_of_stack: A double pointer to the head node of the second stack.
  Return value:
    ALL_GOOD: Indicates that all inputs were processed correctly.
    WRONG_INPUT: Indicates that an invalid input was encountered.
  Description:
    This function iterates over the command-line arguments, starting from the 
	second argument (since the first argument, `argc`, is not processed). For 
	each argument, it performs the following steps:
    1. Checks if the current argument contains spaces or letters, returning 
	`WRONG_INPUT` if so.
    2. Processes the current argument along with the rest of the arguments and 
	the stacks, potentially modifying the stacks based on the argument's 
	content.
    3. If an error occurs during processing, it immediately returns 
	`WRONG_INPUT`.
    The function continues iterating until all arguments have been processed.
	If all arguments pass the validation and processing stages, it returns 
	`ALL_GOOD`.
*/
int	create_structure(int argc, char **argv, t_list **top_of_stack,
		t_list **end_of_stack)
{
	int	i;
	int	error;

	i = 1;
	while (i < argc)
	{
		if (check_spaces(argv[i]) || check_for_letters(argv[i]))
			return (WRONG_INPUT);
		error = process_input_and_stack(argv, i, top_of_stack, end_of_stack);
		if (error)
			return (WRONG_INPUT);
		i++;
	}
	return (ALL_GOOD);
}
