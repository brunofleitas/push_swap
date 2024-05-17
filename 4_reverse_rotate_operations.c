/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_reverse_rotate_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:39:32 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 15:22:15 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_rra(t_list **top_of_stack_a, t_list **end_of_stack_a)
{
	rra(top_of_stack_a, end_of_stack_a);
	write(1, "rra\n", 4);
}

void	run_rrb(t_list **top_of_stack_b, t_list **end_of_stack_b)
{
	rrb(top_of_stack_b, end_of_stack_b);
	write(1, "rrb\n", 4);
}

/*
  Parameters:
    top_of_stack_a: A double pointer to the head node of the first stack.
    end_of_stack_a: A double pointer to the tail node of the first stack.
  Description:
    This function rotates the first stack so that the last element becomes the 
	new top element. It performs the following steps:
    1. Checks if the first stack is not empty.
    2. Stores the last element of the stack in a temporary variable 
	(`last_element`).
    3. Updates the `end_of_stack_a` to point to the previous element of the 
	last element, effectively moving the last element out of the stack.
    4. If the new tail of the stack is not NULL, it sets its `next` pointer 
	to NULL, indicating the end of the stack.
    5. If the stack became empty after the rotation, it also sets 
	`top_of_stack_a` to NULL.
    6. Sets the `prev` pointer of the new top element (`last_element`) to 
	the old top element, and the `next` pointer of the old top element to 
	`NULL`.
    7. Finally, it updates `top_of_stack_a` to point to `last_element`, 
	completing the rotation.
    8. Prints "rra" to stdout to indicate the operation was performed.
*/
void	rra(t_list **top_of_stack_a, t_list **end_of_stack_a)
{
	t_list	*last_element;

	if (*top_of_stack_a && (*top_of_stack_a)->next)
	{
		last_element = *end_of_stack_a;
		*end_of_stack_a = last_element->prev;
		if (*end_of_stack_a)
			(*end_of_stack_a)->next = NULL;
		else
			*top_of_stack_a = NULL;
		(*top_of_stack_a)->prev = last_element;
		last_element->next = *top_of_stack_a;
		last_element->prev = NULL;
		*top_of_stack_a = last_element;
	}
}

/*
  Parameters:
    top_of_stack_b: A double pointer to the head node of the second stack.
    end_of_stack_b: A double pointer to the tail node of the second stack.
  Description:
    This function rotates the second stack so that the last element becomes 
	the new top element. It performs the following steps:
    1. Checks if the second stack is not empty.
    2. Stores the last element of the stack in a temporary variable 
	(`last_element`).
    3. Updates the `end_of_stack_b` to point to the previous element of the 
	last element, effectively moving the last element out of the stack.
    4. If the new tail of the stack is not NULL, it sets its `next` pointer 
	to NULL, indicating the end of the stack.
    5. If the stack became empty after the rotation, it also sets 
	`top_of_stack_b` to NULL.
    6. Sets the `prev` pointer of the new top element (`last_element`) to the 
	old top element, and the `next` pointer of the old top element to `NULL`.
    7. Finally, it updates `top_of_stack_b` to point to `last_element`, 
	completing the rotation.
    8. Prints "rrb" to stdout to indicate the operation was performed.
*/
void	rrb(t_list **top_of_stack_b, t_list **end_of_stack_b)
{
	t_list	*last_element;

	if (*top_of_stack_b && (*top_of_stack_b)->next)
	{
		last_element = *end_of_stack_b;
		*end_of_stack_b = last_element->prev;
		if (*end_of_stack_b)
			(*end_of_stack_b)->next = NULL;
		else
			*top_of_stack_b = NULL;
		(*top_of_stack_b)->prev = last_element;
		last_element->next = *top_of_stack_b;
		last_element->prev = NULL;
		*top_of_stack_b = last_element;
	}
	write(1, "rrb\n", 4);
}

/*
  Parameters:
    top_of_stack_a: A double pointer to the head node of the first stack.
    end_of_stack_a: A double pointer to the tail node of the first stack.
    top_of_stack_b: A double pointer to the head node of the second stack.
    end_of_stack_b: A double pointer to the tail node of the second stack.
  Description:
    This function performs a reverse rotation on both stacks simultaneously. 
	It calls the `rra` function to rotate the first stack so that the last 
	element becomes the new top element, and then calls the `rrb` function 
	to perform a similar rotation on the second stack. After both rotations 
	are completed, it prints "rrr" to stdout to indicate the operation was 
	performed.
*/
void	rrr(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b)
{
	rra(&(*top_of_stack_a), &(*end_of_stack_a));
	rrb(&(*top_of_stack_b), &(*end_of_stack_b));
	write(1, "rrr\n", 4);
}
