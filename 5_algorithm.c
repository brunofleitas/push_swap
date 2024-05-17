/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:23:10 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 15:26:11 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of the first linked
	list.
    top_stack_b, end_stack_b: Pointers to the head and tail of the second 
	linked list.
  Description:
    Main algorithm for manipulating stacks to achieve a sorted order.
    Checks if the first stack is already sorted, then moves above-average 
	elements.
    Sorts five stacks and applies moves to minimize cost.
    Continues applying moves until the second stack is empty.
    Performs final rotations on the first stack.
*/
void	main_algorithm(t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b, t_list **end_stack_b)
{
	t_table	*lower_cost;

	if (check_if_is_it_sorted(top_stack_a))
		return ;
	move_above_average(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
	sort_five_stack(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
	while (*top_stack_b)
	{
		lower_cost = find_lower_cost(top_stack_a, end_stack_a, top_stack_b,
				end_stack_b);
		apply_b_moves(top_stack_b, end_stack_b, lower_cost);
		apply_a_moves(top_stack_a, end_stack_a, lower_cost);
		pa(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
		free(lower_cost);
	}
	final_rotation(top_stack_a, end_stack_a);
}
