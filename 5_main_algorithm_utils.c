/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_main_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:12:03 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 15:25:59 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    top_stack_b: Pointer to the head of a linked list.
    number: Target rank to reach.
  Return value:
    Number of moves to reach the target rank from the top of the list.
  Description:
    Counts the number of moves needed to reach a specific rank at the top of a 
	linked list.
*/
int	moves_to_nbr(t_list **top_stack_b, int number)
{
	int		moves;
	t_list	*tmp;

	moves = 0;
	tmp = *top_stack_b;
	while (tmp->rank != number)
	{
		moves++;
		tmp = tmp->next;
	}
	return (moves);
}

/*
  Parameters:
    top_stack_a: Pointer to the head of a linked list.
  Return value:
    1 if the list is sorted in ascending order, 0 otherwise.
  Description:
    Checks if the linked list is sorted in ascending order starting from the 
	top.
    Returns 1 if the list is sorted, 0 if not.
*/
int	check_if_is_it_sorted(t_list **top_stack_a)
{
	int		rank;
	t_list	*tmp;

	rank = 1;
	tmp = *top_stack_a;
	while (tmp)
	{
		if (tmp->rank == rank)
			rank++;
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of a linked list.
  Description:
    Performs final rotations on the linked list to optimize its state.
    Rotations are conditional based on the size of the list and the positions 
	of certain ranks.
*/
void	final_rotation(t_list **top_stack_a, t_list **end_stack_a)
{
	if (ft_lstsize(*top_stack_a) > 5)
	{
		if ((*top_stack_a)->next->rank != 1)
		{
			if (moves_to_extreme(1, top_stack_a,
					search_max_value(top_stack_a)) <= moves_to_extreme(0,
					end_stack_a, search_max_value(top_stack_a)))
				while (moves_to_extreme(1, top_stack_a,
						search_max_value(top_stack_a)))
					run_ra(top_stack_a, end_stack_a);
			else
				while (((*top_stack_a)->next->rank != 1) && moves_to_extreme(0,
						end_stack_a, search_max_value(top_stack_a)))
					run_rra(top_stack_a, end_stack_a);
		}
		run_ra(top_stack_a, end_stack_a);
	}
}

/*
  Parameters:
    top_stack_b, end_stack_b: Pointers to the head and tail of a linked list.
    lower_cost: Pointer to a t_table structure holding cost-related information
  Description:
    Applies moves to the second stack based on the lower cost calculation.
    Adjusts the position of the number and its best friend according to the 
	cost minimization strategy.
*/
void	apply_b_moves(t_list **top_stack_b, t_list **end_stack_b,
		t_table *lower_cost)
{
	if (moves_to_nbr(top_stack_b,
			lower_cost->number) == lower_cost->moves_put_nbr_top)
		while (moves_to_extreme(1, top_stack_b, lower_cost->number))
			run_rb(top_stack_b, end_stack_b);
	else
		while (moves_to_extreme(0, end_stack_b, lower_cost->number)
			&& (*top_stack_b)->rank != lower_cost->number)
			run_rrb(top_stack_b, end_stack_b);
}

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of a linked list.
    lower_cost: Pointer to a t_table structure holding cost-related 
	information.
  Description:
    Applies moves to the first stack based on the lower cost calculation.
    Adjusts the position of the best friend according to the cost minimization 
	strategy.
*/
void	apply_a_moves(t_list **top_stack_a, t_list **end_stack_a,
		t_table *lower_cost)
{
	if (moves_to_nbr(top_stack_a,
			lower_cost->best_friend) == lower_cost->moves_put_bf_top)
		while (moves_to_extreme(1, top_stack_a, lower_cost->best_friend))
			run_ra(top_stack_a, end_stack_a);
	else
		while (moves_to_extreme(0, end_stack_a, lower_cost->best_friend)
			&& (*top_stack_a)->rank != lower_cost->best_friend)
			run_rra(top_stack_a, end_stack_a);
}
