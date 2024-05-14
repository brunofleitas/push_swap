/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:56:27 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/14 11:22:26 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters: 
      str: The string to convert to an integer.
  Return value:
      The integer value parsed from the string.
  Description:
      This function converts a string representation of an 
	  integer to an integer value.
      It skips leading whitespace characters, handles sign characters,
	  and processes numeric characters.
      The resulting integer is returned.
*/
int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] != 0 && ((nptr[i] == ' ')
			|| (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = (nptr[i] - '0') + (result * 10);
		i++;
	}
	result *= sign;
	if (result <= 2147483647 && result >= -2147483648)
		return (int)result;
	else 
		return (0);
}

int	search_nbr_list(int nbr, t_list *top_of_stack)
{
	while (top_of_stack)
	{
		if (nbr == top_of_stack->number)
			return (1);
		top_of_stack = top_of_stack->next;
	}
	return(0);
}

t_list	*add_node_end(int nbr, t_list **end_of_stack)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (WRONG_MALLOC);
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

int create_structure(int argc, char **argv, t_list	**top_of_stack,
	t_list **end_of_stack)
{
	int		i;
	int		nbr;

	i = 1;
	while (i < argc)
	{
		if (check_spaces(argv[i]) ||check_for_letters(argv[i]))
			return (WRONG_INPUT);
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
		}
		else 
			return (WRONG_INPUT);
		i++;
	}
	return (ALL_GOOD);
}
