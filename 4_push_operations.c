/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_push_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:37:31 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 15:06:00 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    top_of_stack_a: A double pointer to the head node of the first stack.
    end_of_stack_a: A double pointer to the tail node of the first stack.
    top_of_stack_b: A double pointer to the head node of the second stack.
    end_of_stack_b: A double pointer to the tail node of the second stack.
  Description:
    This function moves the top element from the second stack (`top_of_stack_b`
	and `end_of_stack_b`) to the top of the first stack (`top_of_stack_a` and 
	`end_of_stack_a`). It performs the following steps:
    1. Checks if the second stack is not empty.
    2. Moves the top element of the second stack to a temporary variable 
	(`element_to_move`).
    3. Updates the `top_of_stack_b` to point to the next element in the second 
	stack, adjusting the `prev` pointer of the new top element if necessary.
    4. Sets the `prev` pointer of `element_to_move` to NULL, effectively 
	removing it from the second stack.
    5. Adjusts the `next` pointer of `element_to_move` to point to the top 
	element of the first stack, updating the `prev` pointer of the new top 
	element of the first stack if necessary.
    6. Adds `element_to_move` to the first stack, either at the top if the 
	first stack is not empty or at the bottom if it is.
    7. Prints "pa" to stdout to indicate the operation was performed.
*/
void	pa(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b)
{
	t_list	*element_to_move;

	if (*top_of_stack_b)
	{
		element_to_move = *top_of_stack_b;
		*top_of_stack_b = element_to_move->next;
		if (*top_of_stack_b != NULL)
			(*top_of_stack_b)->prev = NULL;
		else
			*end_of_stack_b = NULL;
		element_to_move->prev = NULL;
		element_to_move->next = *top_of_stack_a;
		if (*top_of_stack_a != NULL)
			(*top_of_stack_a)->prev = element_to_move;
		else
			*end_of_stack_a = element_to_move;
		*top_of_stack_a = element_to_move;
	}
}

/*
  Parameters:
    top_of_stack_a: A double pointer to the head node of the first stack.
    end_of_stack_a: A double pointer to the tail node of the first stack.
    top_of_stack_b: A double pointer to the head node of the second stack.
    end_of_stack_b: A double pointer to the tail node of the second stack.
  Description:
    This function moves the top element from the first stack (`top_of_stack_a` 
	and `end_of_stack_a`) to the top of the second stack (`top_of_stack_b` and 
	`end_of_stack_b`). It performs the following steps:
    1. Checks if the first stack is not empty.
    2. Moves the top element of the first stack to a temporary variable 
	(`element_to_move`).
    3. Updates the `top_of_stack_a` to point to the next element in the first 
	stack, adjusting the `prev` pointer of the new top element if necessary.
    4. Sets the `prev` pointer of `element_to_move` to NULL, effectively 
	removing it from the first stack.
    5. Adjusts the `next` pointer of `element_to_move` to point to the top 
	element of the second stack, updating the `prev` pointer of the new top 
	element of the second stack if necessary.
    6. Adds `element_to_move` to the second stack, either at the top if the 
	second stack is not empty or at the bottom if it is.
    7. Prints "pb" to stdout to indicate the operation was performed.
*/
void	pb(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b)
{
	t_list	*element_to_move;

	if (*top_of_stack_a)
	{
		element_to_move = *top_of_stack_a;
		*top_of_stack_a = element_to_move->next;
		if (*top_of_stack_a != NULL)
			(*top_of_stack_a)->prev = NULL;
		else
			*end_of_stack_a = NULL;
		element_to_move->prev = NULL;
		element_to_move->next = *top_of_stack_b;
		if (*top_of_stack_b != NULL)
			(*top_of_stack_b)->prev = element_to_move;
		else
			*end_of_stack_b = element_to_move;
		*top_of_stack_b = element_to_move;
	}
	write(1, "pb\n", 3);
}
