/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algorithm_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:06:31 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/15 16:27:08 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    top_of_stack: Pointer to the head of a linked list.
  Return value:
    Smallest rank in the linked list.
  Description:
    Iterates through a linked list to find the smallest rank.
    Returns the smallest rank found.
*/
int	smaller_number(t_list **top_of_stack)
{
	int		min;
	t_list	*tmp;

	tmp = *top_of_stack;
	min = tmp->rank;
	while (tmp)
	{
		if (tmp->rank < min)
			min = tmp->rank;
		tmp = tmp->next;
	}
	return (min);
}

/*
  Parameters:
    top_of_stack: Pointer to the head of a linked list.
    number: Target number for comparison.
  Return value:
    Best friend number or smallest number in the list.
  Description:
    Finds the best friend number by comparing each element's rank to the 
	target number.
    Returns the sum of the target number and the closest positive difference.
    If no close match is found, returns the smallest number in the list.
*/
int	calculate_best_friend(t_list **top_of_stack, int number)
{
	int		bf;
	int		diff;
	t_list	*tmp;

	tmp = *top_of_stack;
	bf = 2147483647;
	while (tmp)
	{
		diff = (tmp)->rank - number;
		if (diff > 0 && diff < bf)
			bf = diff;
		(tmp) = (tmp)->next;
	}
	if (bf != 2147483647)
		return (number + bf);
	else
		return (smaller_number(top_of_stack));
}

/*
  Parameters:
    top: Boolean flag indicating traversal direction (true for top, false for 
	bottom).
    border_of_stack: Pointer to the head of a doubly-linked list.
    number: Target rank to reach.
  Return value:
    Number of moves to reach the target rank from the specified direction.
  Description:
    Calculates the number of moves to reach a specific rank in a doubly-linked 
	list.
    Traverses from the top or bottom depending on the 'top' flag.
*/
int	moves_to_extreme(int top, t_list **border_of_stack, int number)
{
	int		moves;
	t_list	*tmp;

	tmp = *border_of_stack;
	if (top)
		moves = 0;
	else
		moves = 1;
	while ((tmp)->rank != number)
	{
		moves++;
		if (top)
			(tmp) = (tmp)->next;
		else
			(tmp) = (tmp)->prev;
	}
	return (moves);
}

/*
  Parameters:
    top_of_stack: Pointer to the head of a linked list.
    end_of_stack: Pointer to the tail of a linked list.
    number: Target rank to reach.
  Return value:
    Minimum number of moves to reach the target rank from either end of the 
	lists.
  Description:
    Compares the number of moves to reach a target rank from the top and 
	bottom ends of two linked lists.
    Returns the minimum number of moves required.
*/
int	calculate_moves(t_list **top_of_stack, t_list **end_of_stack, int number)
{
	if (moves_to_extreme(1, top_of_stack, number) < moves_to_extreme(0,
			end_of_stack, number))
		return (moves_to_extreme(1, top_of_stack, number));
	else
		return (moves_to_extreme(0, end_of_stack, number));
}
