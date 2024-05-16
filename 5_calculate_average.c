/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_calculate_average.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:24:44 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/15 16:47:28 by bfleitas         ###   ########.fr       */
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

/*
  Parameters:
    lst: Pointer to the head of a linked list.
  Return value:
    Sum of all ranks in the linked list.
  Description:
    Sums up the ranks of all elements in a linked list.
*/
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

/*
  Parameters:
    top_of_stack_a: Pointer to the head of a linked list.
  Return value:
    Average of all ranks in the linked list.
  Description:
    Calculates the average rank of all elements in a linked list.
*/
int	average(t_list *top_of_stack_a)
{
	return (sum_lst(top_of_stack_a) / ft_lstsize(top_of_stack_a));
}
