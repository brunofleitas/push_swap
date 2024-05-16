/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-compute_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:21:40 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/15 15:11:07 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    nptr: A pointer to a null-terminated character string that represents a 
	part of an integer number.
    i: A pointer to an integer that represents the current position in the 
	string being processed.
  Return value:
    The converted integer value if the conversion was successful, otherwise 0.
  Description:
    This function converts a substring representation of an integer to an 
	integer value. It starts by checking for optional sign characters 
	('-' or '+') at the current position and adjusts the sign accordingly. 
	Then, it reads the digits of the number sequentially, converting them to 
	their corresponding integer values. The function ensures that the 
	resulting integer fits within the range of a signed long int 
	(-2147483648 to 2147483647). If the conversion would cause overflow or 
	underflow, the function returns 0. Otherwise, it returns the converted 
	integer value.
*/
int	ft_atoi_str(const char *nptr, int *i)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (nptr[*i] != 0 && (nptr[*i] >= '0' && nptr[*i] <= '9'))
	{
		result = (nptr[*i] - '0') + (result * 10);
		(*i)++;
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483648)
		return (0);
	else
		return ((int)result);
}

/*
  Parameters:
    argv: A pointer to a null-terminated character string that represents a 
	sequence of numbers separated by spaces.
    i: The index of the current character being processed.
    top_of_stack: A double pointer to the head node of the first stack.
    end_of_stack: A double pointer to the head node of the second stack.
  Return value:
    ALL_GOOD: Indicates that the current number was processed and added to the 
	stacks successfully.
    WRONG_INPUT: Indicates that the current number could not be processed or 
	added to the stacks.
  Description:
    This function attempts to process the current number in the string as 
	follows:
    1. Skips any leading whitespace characters and checks for optional space 
	after '0'. If '0' followed by a space is detected, it sets `nbr` to 0.
    2. Otherwise, it tries to convert the current number to an integer using 
	`ft_atoi_str`. If the conversion fails (returns 0), it considers this as 
	wrong input.
    3. It searches if the number exists in the list represented by 
	`top_of_stack`. If not found:
       - If `top_of_stack` is empty, it adds the number to the beginning of 
	   `end_of_stack`.
       - Else, it adds the number to the end of `end_of_stack`.
    4. Returns `ALL_GOOD` if the number was successfully added to the stacks, 
	otherwise `WRONG_INPUT`.
*/
int	process_input_stack_str(char *argv, int i, t_list **top_of_stack,
		t_list **end_of_stack)
{
	int	nbr;

	while (argv[i] != 0 && ((argv[i] == ' ') || (argv[i] >= 9
				&& argv[i] <= 13)))
		i++;
	if (argv[i] == '0' && argv[i++ + 1] == ' ')
		nbr = 0;
	else
	{
		nbr = ft_atoi_str(argv, &i);
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
    argv: A pointer to a null-terminated character string that represents a 
	sequence of numbers separated by spaces.
    top_of_stack: A double pointer to the head node of the first stack.
    end_of_stack: A double pointer to the head node of the last stack.
  Return value:
    ALL_GOOD: Indicates that all numbers in the string were processed correctly
    WRONG_INPUT: Indicates that an invalid input was encountered.
  Description:
    This function iterates over the characters in the input string, treating 
	each group of consecutive digits as a separate number. For each number 
	identified:
    1. It checks if the current character or preceding characters contain 
	spaces or letters, returning `WRONG_INPUT` if so.
    2. It processes the current number along with the rest of the string and 
	the stacks, potentially modifying the stacks based on the number's content.
    3. If an error occurs during processing, it immediately returns 
	`WRONG_INPUT`.
    The function continues iterating until all characters in the string have 
	been processed. If all numbers pass the validation and processing stages, 
	it returns `ALL_GOOD`.
*/
int	create_structure_str(char *argv, t_list **top_of_stack,
		t_list **end_of_stack)
{
	int	i;
	int	error;

	if (check_spaces(argv) || check_for_letters(argv))
		return (WRONG_INPUT);
	i = 0;
	while (i != ft_strlen(argv))
	{
		error = process_input_stack_str(argv, i, top_of_stack, end_of_stack);
		if (error)
			return (WRONG_INPUT);
	}
	return (ALL_GOOD);
}
