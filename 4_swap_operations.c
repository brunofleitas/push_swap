/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_swap_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:33:59 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/21 15:00:29 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_sa(t_list **top_of_stack_a)
{
	sa(top_of_stack_a);
	write(1, "sa\n", 3);
}

void	run_sb(t_list **top_of_stack_b)
{
	sb(top_of_stack_b);
	write(1, "sb\n", 3);
}

/*
  Parameters:
    top_of_stack_a: A double pointer to the head node of the first stack.
  Description:
    This function swaps the number and rank of the top element of the first 
	stack with those of the next element in the stack. It performs the 
	following steps:
    1. Checks if the first stack is not empty.
    2. Retrieves the next element in the stack.
    3. If the next element exists, it swaps the `number` and `rank` fields 
	between the current top element and the next element.
    4. Prints "sa" to stdout to indicate the operation was performed.
*/
void	sa(t_list **top_of_stack_a)
{
	t_list	*next;
	int		temp;

	if (*top_of_stack_a)
	{
		next = (*top_of_stack_a)->next;
		if (next)
		{
			temp = (*top_of_stack_a)->number;
			(*top_of_stack_a)->number = next->number;
			next->number = temp;
			temp = (*top_of_stack_a)->rank;
			(*top_of_stack_a)->rank = next->rank;
			next->rank = temp;
		}
	}
}

/*
  Parameters:
    top_of_stack_b: A double pointer to the head node of the second stack.
  Description:
    This function swaps the number and rank of the top element of the second 
	stack with those of the next element in the stack. It performs the 
	following steps:
    1. Checks if the second stack is not empty.
    2. Retrieves the next element in the stack.
    3. If the next element exists, it swaps the `number` and `rank` fields 
	between the current top element and the next element.
    4. Prints "sb" to stdout to indicate the operation was performed.
*/
void	sb(t_list **top_of_stack_b)
{
	t_list	*next;
	int		temp;

	if (*top_of_stack_b)
	{
		next = (*top_of_stack_b)->next;
		if (next)
		{
			temp = (*top_of_stack_b)->number;
			(*top_of_stack_b)->number = next->number;
			next->number = temp;
			temp = (*top_of_stack_b)->rank;
			(*top_of_stack_b)->rank = next->rank;
			next->rank = temp;
		}
	}
}

/*
  Parameters:
    top_of_stack_a: A double pointer to the head node of the first stack.
    top_of_stack_b: A double pointer to the head node of the second stack.
  Description:
    This function performs swap operations on the top elements of both stacks. 
	It calls the `sa` function to swap the number and rank of the top element 
	of the first stack with those of the next element, and then calls the `sb` 
	function to perform a similar operation on the second stack. After both 
	operations are completed, it prints "ss" to stdout to indicate the 
	operation was performed.
*/
void	ss(t_list **top_of_stack_a, t_list **top_of_stack_b)
{
	sa(&(*top_of_stack_a));
	sb(&(*top_of_stack_b));
}
