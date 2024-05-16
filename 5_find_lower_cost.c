/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_find_lower_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:46:30 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/15 16:53:17 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of the first 
	linked list.
    top_stack_b, end_stack_b: Pointers to the head and tail of the second 
	linked list.
  Return value:
    Pointer to a t_table structure initialized with lower cost calculations.
  Description:
    Initializes a t_table structure with calculations for lower cost.
    Allocates memory for the structure, sets its fields based on input 
	stacks.
*/
t_table	*initialize_lower_cost(t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b, t_list **end_stack_b)
{
	t_table	*lower_cost;
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *top_stack_a;
	tmp_b = *top_stack_b;
	lower_cost = malloc(sizeof(t_table));
	if (!lower_cost)
		return (NULL);
	lower_cost->number = tmp_b->rank;
	lower_cost->best_friend = calculate_best_friend(&tmp_a, lower_cost->number);
	lower_cost->moves_put_nbr_top = calculate_moves(top_stack_b, end_stack_b,
			lower_cost->number);
	lower_cost->moves_put_bf_top = calculate_moves(top_stack_a, end_stack_a,
			lower_cost->best_friend);
	lower_cost->cost = lower_cost->moves_put_nbr_top
		+ lower_cost->moves_put_bf_top;
	return (lower_cost);
}

/*
  Parameters:
    lower_cost: Pointer to a t_table structure holding the current lower cost.
    tmp: Pointer to another t_table structure potentially offering a better 
	cost.
  Description:
    Updates the lower_cost structure if the cost in tmp is lower.
*/
void	update_lower_cost_if_better(t_table *lower_cost, t_table *tmp)
{
	if (lower_cost->cost > tmp->cost)
	{
		lower_cost->number = tmp->number;
		lower_cost->best_friend = tmp->best_friend;
		lower_cost->moves_put_nbr_top = tmp->moves_put_nbr_top;
		lower_cost->moves_put_bf_top = tmp->moves_put_bf_top;
		lower_cost->cost = tmp->cost;
	}
}

/*
  Parameters:
    tmp: Pointer to a t_table structure to update.
    top_stack_a, top_stack_b: Pointers to the heads of two linked lists.
  Description:
    Updates the tmp structure with calculations for moves and cost.
    Calculates the number of moves to place a number and its best friend 
	at the top of respective stacks.
    Updates the total cost based on these moves.
*/
void	asign_tmp(t_table *tmp, t_list **top_stack_a, t_list **top_stack_b)
{
	t_list	**end_stack_a;
	t_list	**end_stack_b;

	end_stack_a = top_stack_a;
	end_stack_b = top_stack_b;
	while ((*end_stack_a)->next != NULL)
		end_stack_a = &((*end_stack_a)->next);
	while ((*end_stack_b)->next != NULL)
		end_stack_b = &((*end_stack_b)->next);
	tmp->moves_put_nbr_top = calculate_moves(top_stack_b, end_stack_b,
			tmp->number);
	tmp->moves_put_bf_top = calculate_moves(top_stack_a, end_stack_a,
			tmp->best_friend);
	tmp->cost = tmp->moves_put_nbr_top + tmp->moves_put_bf_top;
}

/*
  Parameters:
    top_stack_a, end_stack_a: Pointers to the head and tail of the first 
	linked list.
    top_stack_b, end_stack_b: Pointers to the head and tail of the second 
	linked list.
  Return value:
    Pointer to a t_table structure initialized with the lowest cost found.
  Description:
    Searches for the lowest cost configuration by iterating through the 
	second stack.
    Initializes a t_table structure with initial lower cost values.
    For each element in the second stack, calculates potential costs and 
	updates the lower cost if better.
    Returns the t_table structure with the lowest cost found.
*/
t_table	*find_lower_cost(t_list **top_stack_a, t_list **end_stack_a,
		t_list **top_stack_b, t_list **end_stack_b)
{
	t_table	*lower_cost;
	t_table	*tmp;
	t_list	*tmp_a;
	t_list	*tmp_b;

	lower_cost = initialize_lower_cost(top_stack_a, end_stack_a, top_stack_b,
			end_stack_b);
	if (!lower_cost)
		return (NULL);
	tmp_a = *top_stack_a;
	tmp_b = *top_stack_b;
	tmp_b = tmp_b->next;
	while (tmp_b)
	{
		tmp = malloc(sizeof(t_table));
		if (!tmp)
			return (NULL);
		tmp->number = tmp_b->rank;
		tmp->best_friend = calculate_best_friend(&tmp_a, tmp->number);
		asign_tmp(tmp, top_stack_a, top_stack_b);
		update_lower_cost_if_better(lower_cost, tmp);
		tmp_b = tmp_b->next;
		free(tmp);
	}
	return (lower_cost);
}
