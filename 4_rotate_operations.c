/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_rotate_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:38:37 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/15 15:54:19 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    top_of_stack_a: A double pointer to the head node of the first stack.
    end_of_stack_a: A double pointer to the tail node of the first stack.
  Description:
    This function rotates the first stack so that the first element becomes the
	new bottom element. It performs the following steps:
    1. Checks if the first stack is not empty.
    2. Stores the first element of the stack in a temporary variable 
	(`first_element`).
    3. Updates the `top_of_stack_a` to point to the next element in the first 
	stack, adjusting the `prev` pointer of the new top element if necessary.
    4. If the new top of the stack is not NULL, it sets its `prev` pointer to 
	NULL, indicating it is now the top element.
    5. If the stack became empty after the rotation, it also sets 
	`end_of_stack_a` to NULL.
    6. Sets the `next` pointer of the new bottom element (`first_element`) to 
	the old bottom element, and the `prev` pointer of the old bottom element 
	to `first_element`.
    7. Finally, it updates `end_of_stack_a` to point to `first_element`, 
	completing the rotation.
    8. Prints "ra" to stdout to indicate the operation was performed.
*/
void	ra(t_list **top_of_stack_a, t_list **end_of_stack_a)
{
	t_list	*first_element;

	if (*top_of_stack_a)
	{
		first_element = *top_of_stack_a;
		*top_of_stack_a = first_element->next;
		if (*top_of_stack_a)
			(*top_of_stack_a)->prev = NULL;
		else
			*end_of_stack_a = NULL;
		(*end_of_stack_a)->next = first_element;
		first_element->prev = *end_of_stack_a;
		first_element->next = NULL;
		(*end_of_stack_a)->next = first_element;
		*end_of_stack_a = first_element;
	}
	write(1, "ra\n", 3);
}

/*
  Parameters:
    top_of_stack_b: A double pointer to the head node of the second stack.
    end_of_stack_b: A double pointer to the tail node of the second stack.
  Description:
    This function rotates the second stack so that the first element becomes 
	the new bottom element. It performs the following steps:
    1. Checks if the second stack is not empty.
    2. Stores the first element of the stack in a temporary variable 
	(`first_element`).
    3. Updates the `top_of_stack_b` to point to the next element in the 
	second stack, adjusting the `prev` pointer of the new top element if 
	necessary.
    4. If the new top of the stack is not NULL, it sets its `prev` pointer 
	to NULL, indicating it is now the top element.
    5. If the stack became empty after the rotation, it also sets 
	`end_of_stack_b` to NULL.
    6. Sets the `next` pointer of the new bottom element (`first_element`) 
	to the old bottom element, and the `prev` pointer of the old bottom 
	element to `first_element`.
    7. Finally, it updates `end_of_stack_b` to point to `first_element`, 
	completing the rotation.
    8. Prints "rb" to stdout to indicate the operation was performed.
*/
void	rb(t_list **top_of_stack_b, t_list **end_of_stack_b)
{
	t_list	*first_element;

	if (*top_of_stack_b)
	{
		first_element = *top_of_stack_b;
		*top_of_stack_b = first_element->next;
		if (*top_of_stack_b)
			(*top_of_stack_b)->prev = NULL;
		else
			*end_of_stack_b = NULL;
		(*end_of_stack_b)->next = first_element;
		first_element->prev = *end_of_stack_b;
		first_element->next = NULL;
		(*end_of_stack_b)->next = first_element;
		*end_of_stack_b = first_element;
	}
	write(1, "rb\n", 3);
}

/*
  Parameters:
    top_of_stack_a: A double pointer to the head node of the first stack.
    end_of_stack_a: A double pointer to the tail node of the first stack.
    top_of_stack_b: A double pointer to the head node of the second stack.
    end_of_stack_b: A double pointer to the tail node of the second stack.
  Description:
    This function performs a simple rotation on both stacks simultaneously. 
	It calls the `ra` function to rotate the first stack so that the first 
	element becomes the new bottom element, and then calls the `rb` function 
	to perform a similar rotation on the second stack. After both rotations 
	are completed, it prints "rr" to stdout to indicate the operation was 
	performed.
*/
void	rr(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b)
{
	ra(&(*top_of_stack_a), &(*end_of_stack_a));
	rb(&(*top_of_stack_b), &(*end_of_stack_b));
	write(1, "rr\n", 3);
}
