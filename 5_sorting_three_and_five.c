/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_sorting_three_and_five.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:35:17 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 15:24:15 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of a linked list.
  Description:
    Sorts the first three elements of the linked list using specific rotation 
	operations.
    Conditions determine the sequence of sa, ra, and rra operations to sort 
	the elements correctly.
*/
void	sort_three_stack(t_list **top_stack_a, t_list **end_stack_a)
{
	if (((*top_stack_a)->rank == 1) && ((*top_stack_a)->next->rank == 3))
	{
		run_sa(top_stack_a);
		run_ra(top_stack_a, end_stack_a);
	}
	else if ((*top_stack_a)->rank == 2)
	{
		if ((*top_stack_a)->next->rank == 1)
			run_sa(top_stack_a);
		else
			run_rra(top_stack_a, end_stack_a);
	}
	else if ((*top_stack_a)->rank == 3)
	{
		if ((*top_stack_a)->next->rank == 1)
			run_ra(top_stack_a, end_stack_a);
		else
		{
			run_sa(top_stack_a);
			run_rra(top_stack_a, end_stack_a);
		}
	}
}

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of the first 
	linked list.
    top_stack_b, end_stack_b: Pointers to the head and tail of the second 
	linked list.
  Description:
    Moves elements from the first stack to the second if they are above 
	average.
    Uses pb operation to move elements, otherwise uses ra operation.
    Ensures the first stack has 5 or fewer elements after moving.
*/
void	move_above_average(t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b, t_list **end_stack_b)
{
	t_list	*tmp;

	while (ft_lstsize(*top_stack_a) > 5)
	{
		tmp = *top_stack_a;
		if (tmp->rank > average(*top_stack_a))
			pb(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
		else
			run_ra(top_stack_a, end_stack_a);
	}
}

/*
  Parameters:
    top_stack_a: Pointer to the head of a linked list.
  Return value:
    Maximum rank in the linked list.
  Description:
    Searches for the maximum rank in a linked list.
    Returns the highest rank found.
*/
int	search_max_value(t_list **top_stack_a)
{
	int		max;
	t_list	*tmp;

	tmp = *top_stack_a;
	max = (tmp)->rank;
	while (tmp)
	{
		if ((tmp)->rank > max)
			max = (tmp)->rank;
		(tmp) = (tmp)->next;
	}
	return (max);
}

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of the first 
	linked list.
    top_stack_b, end_stack_b: Pointers to the head and tail of the second 
	linked list.
  Description:
    Moves the maximum value from the first stack to the second stack.
    Determines the optimal path (either from the top or bottom) to move 
	the maximum value.
    Uses pb operation to move the maximum value.
*/
void	pb_max(t_list **top_stack_a, t_list **end_stack_a, t_list **top_stack_b,
		t_list **end_stack_b)
{
	if (ft_lstsize(*top_stack_a) > 3)
	{
		if (moves_to_extreme(1, top_stack_a,
				search_max_value(top_stack_a)) <= moves_to_extreme(0,
				end_stack_a, search_max_value(top_stack_a)))
		{
			while (moves_to_extreme(1, top_stack_a,
					search_max_value(top_stack_a))
				&& (*top_stack_a)->rank != search_max_value(top_stack_a))
				run_ra(top_stack_a, end_stack_a);
			pb(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
		}
		else
		{
			while (moves_to_extreme(0, end_stack_a,
					search_max_value(top_stack_a))
				&& (*top_stack_a)->rank != search_max_value(top_stack_a))
				run_rra(top_stack_a, end_stack_a);
			pb(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
		}
	}
}

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of the first 
	linked list.
    top_stack_b, end_stack_b: Pointers to the head and tail of the second 
	linked list.
  Description:
    Sorts the first five elements of the first stack by moving them to the 
	second stack.
    Utilizes pb_max to move the maximum values twice, followed by sorting the 
	first three elements.
    Additional pa and ra operations ensure the second stack is sorted and 
	aligned properly.
*/
void	sort_five_stack(t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b, t_list **end_stack_b)
{
	if (ft_lstsize(*top_stack_a) > 3)
	{
		pb_max(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
		pb_max(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
	}
	sort_three_stack(top_stack_a, end_stack_a);
	if (*top_stack_b)
	{
		pa(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
		run_ra(top_stack_a, end_stack_a);
	}
	if (*top_stack_b)
	{
		pa(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
		run_ra(top_stack_a, end_stack_a);
	}
}
