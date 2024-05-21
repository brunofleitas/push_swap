/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_operations_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:58:50 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/21 15:08:39 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_rrr(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b)
{
	rra(&(*top_of_stack_a), &(*end_of_stack_a));
	rrb(&(*top_of_stack_b), &(*end_of_stack_b));
	write(1, "rrr\n", 4);
}

void	run_rr(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b)
{
	ra(&(*top_of_stack_a), &(*end_of_stack_a));
	rb(&(*top_of_stack_b), &(*end_of_stack_b));
	write(1, "rr\n", 3);
}

void	run_ss(t_list **top_of_stack_a, t_list **top_of_stack_b)
{
	sa(&(*top_of_stack_a));
	sb(&(*top_of_stack_b));
	write(1, "ss\n", 3);
}
