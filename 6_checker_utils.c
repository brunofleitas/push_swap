/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_checker_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:30:19 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 02:32:40 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

/*
  Parameters:
    op: String representing the operation to perform.
    top_stack_a, top_stack_b: Pointers to the heads of the two linked lists.
  Description:
    Executes swap operations based on the first character of the string op.
    Supports swapping elements at the top of the first list ('a'), swapping 
	elements at the top of the second list ('b'), and swapping elements
	in the two lists ('s').
*/
void	run_swap_op(char *op, t_list **top_stack_a, t_list **top_stack_b)
{
	if (op[1] == 'a')
		sa(top_stack_a);
	else if (op[1] == 'b')
		sb(top_stack_b);
	else
		ss(top_stack_a, top_stack_b);
}

/*
  Parameters:
    op: String representing the operation to perform.
    top_stack_a, end_stack_a: Pointers to the head and tail of the first 
	linked list.
    top_stack_b: Pointer to the head of the second linked list.
  Description:
    Executes push operations based on the first character of the string op.
    Supports push to a ('a') and push to b ('b').
*/
void	run_push_op(char *op, t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b)
{
	t_list	*end_stack_b;

	end_stack_b = *top_stack_b;
	if (end_stack_b)
		while ((end_stack_b)->next != NULL)
			(end_stack_b) = (end_stack_b)->next;
	if (op[1] == 'a')
		pa(top_stack_a, end_stack_a, top_stack_b, &end_stack_b);
	else if (op[1] == 'b')
		pb(top_stack_a, end_stack_a, top_stack_b, &end_stack_b);
}

/*
  Parameters:
    op: String representing the operation to perform.
    top_stack_a, end_stack_a: Pointers to the head and tail of the first 
	linked list.
    top_stack_b: Pointer to the head of the second linked list.
  Description:
    Executes reverse rotate operations based on the second character of the 
	string op.
    Supports reverse rotate a ('a'), reverse rotate b ('b'), and reverse double
	rotate ('r').
*/
void	run_rev_rot_op(char *op, t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b)
{
	t_list	*end_stack_b;

	end_stack_b = *top_stack_b;
	if (end_stack_b)
		while ((end_stack_b)->next != NULL)
			(end_stack_b) = (end_stack_b)->next;
	if (op[2] == 'a')
		rra(top_stack_a, end_stack_a);
	else if (op[2] == 'b')
		rrb(top_stack_b, &end_stack_b);
	else
		rrr(top_stack_a, end_stack_a, top_stack_b, &end_stack_b);
}

/*
  Parameters:
    op: String representing the operation to perform.
    top_stack_a, end_stack_a: Pointers to the head and tail of the first linked
	list.
    top_stack_b: Pointer to the head of the second linked list.
  Description:
    Executes rotate operations based on the second character of the string op.
    Supports rotate a ('a'), rotate b ('b'), and double rotate ('r').
*/
void	run_rot_op(char *op, t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b)
{
	t_list	*end_stack_b;

	end_stack_b = *top_stack_b;
	if (end_stack_b)
		while ((end_stack_b)->next != NULL)
			(end_stack_b) = (end_stack_b)->next;
	if (op[1] == 'a')
		ra(top_stack_a, end_stack_a);
	else if (op[1] == 'b')
		rb(top_stack_b, &end_stack_b);
	else
		rr(top_stack_a, end_stack_a, top_stack_b, &end_stack_b);
}
