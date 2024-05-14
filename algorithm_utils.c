/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:06:31 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/14 14:27:36 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters: 
      lst: The pointer to the first element of the list.
  Return value:
      The number of elements in the list.
  Description:
      Counts the number of elements in the list 'lst'.
      Returns 0 if 'lst' is NULL.
*/
int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}

int	sum_lst(t_list *lst)
{
	int	sum;

	sum = 0;
	while (lst)
	{
        sum += lst->rank;
		lst = lst->next;
	}
	return (sum);
}

int average(t_list *top_of_stack_a)
{
    return (sum_lst(top_of_stack_a) / ft_lstsize(top_of_stack_a));
}

int	smaller_number(t_list **top_of_stack)
{
	int min;
	t_list *tmp;

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

int calculate_best_friend(t_list **top_of_stack, int number)
{
	int	bf;
	int diff;
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

int moves_to_extreme(int top, t_list **border_of_stack, int number)
{
	int moves;
	t_list *tmp;

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
	return(moves);
}

int calculate_moves(t_list **top_of_stack, t_list **end_of_stack, int number)
{
	if (moves_to_extreme(1, top_of_stack, number) < 
			moves_to_extreme(0, end_of_stack, number))
		return (moves_to_extreme(1, top_of_stack, number));
	else
		return (moves_to_extreme(0, end_of_stack, number));
}
