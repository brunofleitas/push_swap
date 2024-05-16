/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-ranking.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:09:28 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/15 15:37:00 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    top_of_stack: A pointer to the head node of the linked list representing 
	the structure.
  Return value:
    1: Indicates that all nodes in the linked list have been assigned a rank 
	different from zero.
    0: Indicates that there is at least one node in the linked list that has 
	not been assigned a rank.
  Description:
    This function iterates through the linked list starting from the head node 
	(`top_of_stack`). It checks each node to see if its `rank` field is equal 
	to 0, which indicates that the node has not yet been assigned a rank. If 
	any node is found with a rank of 0, the function immediately returns 0, 
	indicating that not all nodes have been assigned a rank. If the function 
	completes the iteration without finding any node with a rank of 0, it 
	returns 1, indicating that all nodes have been assigned a rank.
*/
int	all_ranks_filled(t_list *top_of_stack)
{
	t_list	*iter;

	iter = top_of_stack;
	while (iter)
	{
		if (iter->rank == 0)
			return (0);
		iter = iter->next;
	}
	return (1);
}

/*
  Parameters:
    top_of_stack: A double pointer to the head node of the linked list 
	representing the structure.
    rank: The minimum rank to be assigned to nodes in the list.
  Description:
    This function iterates through the linked list starting from the head node 
	(`top_of_stack`). It looks for nodes where the `rank` field is 0, 
	indicating that they have not yet been assigned a rank. Among these nodes, 
	it identifies the one with the smallest `number` field and assigns it the 
	specified `rank`. This process helps in assigning unique ranks to nodes 
	based on their numerical values, ensuring that each node eventually gets a 
	rank. The function modifies the `rank` field of the selected node to 
	reflect the assigned rank.
*/
void	assign_min_rank(t_list **top_of_stack, int rank)
{
	t_list	*current;
	t_list	*min;
	int		min_nbr;

	current = *top_of_stack;
	min = NULL;
	min_nbr = 2147483647;
	while (current)
	{
		if (current->rank == 0 && min_nbr >= current->number)
		{
			min = current;
			min_nbr = current->number;
		}
		current = current->next;
	}
	if (min != NULL)
		min->rank = rank;
}

/*
  Parameters:
    top_of_stack: A double pointer to the head node of the linked list 
	representing the structure.
  Description:
    This function assigns ranks to the elements in the linked list starting 
	from the head node (`top_of_stack`). It initializes the rank of the first 
	element to 1 and then iteratively assigns ranks to subsequent elements, 
	ensuring that each element receives a unique rank. The ranking process 
	continues until all elements have received a rank, as determined by the 
	`all_ranks_filled` function. The `assign_min_rank` function is called to 
	assign ranks to the elements, but the implementation details of how ranks 
	are assigned are abstracted away here, focusing instead on the overall 
	logic of the ranking process.
*/
void	ranking_structure(t_list **top_of_stack)
{
	int	rank;

	if (*top_of_stack)
	{
		rank = 1;
		while (!all_ranks_filled(*top_of_stack))
		{
			assign_min_rank(top_of_stack, rank);
			rank++;
		}
	}
}
