/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:23:10 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/14 14:27:34 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_above_average(t_list **top_stack_a, t_list **end_stack_a,
        t_list **top_stack_b, t_list **end_stack_b)
{
    t_list *tmp;

    while (ft_lstsize(*top_stack_a) > 5)
    {
        tmp = *top_stack_a;
        if (tmp->rank > average(*top_stack_a))
            pb(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
        else 
            ra(top_stack_a, end_stack_a);
    }
}

void	sort_three_stack(t_list **top_stack_a, t_list **end_stack_a)
{
    if (((*top_stack_a)->rank == 1) && ((*top_stack_a)->next->rank == 3))
    {
        sa(top_stack_a);
        ra(top_stack_a, end_stack_a);
    } 
    else if ((*top_stack_a)->rank == 2)
    {
        if ((*top_stack_a)->next->rank == 1)
            sa(top_stack_a);
        else 
            rra(top_stack_a, end_stack_a);
    }
    else if ((*top_stack_a)->rank == 3)
    {
        if ((*top_stack_a)->next->rank == 1)
            ra(top_stack_a, end_stack_a);
        else 
        {
            sa(top_stack_a);
            rra(top_stack_a, end_stack_a);
        }
    }
}

int     search_max_value(t_list **top_stack_a)
{
    int max;
    t_list *tmp;

    tmp = *top_stack_a;
    max = (tmp)->rank;
    while (tmp)
    {
        if ((tmp)->rank > max)
            max = (tmp)->rank;
        (tmp) = (tmp)->next;
    }
    return(max);
}

void    pb_max(t_list **top_stack_a, t_list **end_stack_a,
        t_list **top_stack_b, t_list **end_stack_b)
{
    if (ft_lstsize(*top_stack_a) > 3)
    {
        if (moves_to_extreme(1, top_stack_a, search_max_value(top_stack_a)) <= moves_to_extreme(0, end_stack_a, search_max_value(top_stack_a)))
        {
            while (moves_to_extreme(1, top_stack_a, search_max_value(top_stack_a)) && (*top_stack_a)->rank != search_max_value(top_stack_a))
                ra(top_stack_a, end_stack_a);
            pb(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
        }
        else
        {
            while (moves_to_extreme(0, end_stack_a, search_max_value(top_stack_a)) && (*top_stack_a)->rank != search_max_value(top_stack_a))
                rra(top_stack_a, end_stack_a);
            pb(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
        }
    }
}

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
        ra(top_stack_a, end_stack_a);
    }
    if (*top_stack_b)
    {    
        pa(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
        ra(top_stack_a, end_stack_a);
    }
}

t_table *find_lower_cost(t_list **top_stack_a, t_list **end_stack_a, t_list **top_stack_b, t_list **end_stack_b)
{
    t_table *lower_cost = malloc(sizeof(t_table));
    t_table *tmp = malloc(sizeof(t_table));
    t_list  *tmp_a;
    t_list  *tmp_b;

    tmp_a = *top_stack_a;
    tmp_b = *top_stack_b;
    lower_cost->number = tmp_b->rank;
    lower_cost->best_friend = calculate_best_friend(&tmp_a, lower_cost->number);
    lower_cost->moves_put_nbr_top = calculate_moves(top_stack_b, end_stack_b, lower_cost->number);
    lower_cost->moves_put_bf_top = calculate_moves(top_stack_a, end_stack_a, lower_cost->best_friend);
    lower_cost->cost = lower_cost->moves_put_nbr_top + lower_cost->moves_put_bf_top;
    tmp_b = tmp_b->next;
    while (tmp_b)
    {
        tmp->number = tmp_b->rank;
        tmp->best_friend = calculate_best_friend(&tmp_a, tmp->number);
        tmp->moves_put_nbr_top = calculate_moves(top_stack_b, end_stack_b, tmp->number);
        tmp->moves_put_bf_top = calculate_moves(top_stack_a, end_stack_a, tmp->best_friend);
        tmp->cost = tmp->moves_put_nbr_top + tmp->moves_put_bf_top;
        if (lower_cost->cost > tmp->cost)
        {
            lower_cost->number = tmp->number;
            lower_cost->best_friend = tmp->best_friend;
            lower_cost->moves_put_nbr_top = tmp->moves_put_nbr_top;
            lower_cost->moves_put_bf_top = tmp->moves_put_bf_top;
            lower_cost->cost = tmp->cost;
        }
        tmp_b = tmp_b->next;
    }
    free(tmp);
    return (lower_cost);
}

int     moves_to_nbr(t_list **top_stack_b, int number)
{
    int moves;
    t_list *tmp;

    moves = 0;
    tmp = *top_stack_b;
    while (tmp->rank != number)
    {
        moves++;
        tmp = tmp->next;
    }
    return (moves);
}

int check_if_is_it_sorted(t_list **top_stack_a)
{
    int rank;
    t_list *tmp;
    
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

void    main_algorithm(t_list **top_stack_a, t_list **end_stack_a, t_list **top_stack_b, t_list **end_stack_b)
{
    t_table *lower_cost;

    if (check_if_is_it_sorted(top_stack_a))
        return ;
    move_above_average(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
    sort_five_stack(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
    while (*top_stack_b)
    {
        lower_cost = find_lower_cost(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
        if (moves_to_nbr(top_stack_b, lower_cost->number) == lower_cost->moves_put_nbr_top)
        {
            while (moves_to_extreme(1, top_stack_b, lower_cost->number))
                rb(top_stack_b, end_stack_b);
        }
        else
        {         
            while (moves_to_extreme(0, end_stack_b, lower_cost->number) && (*top_stack_b)->rank != lower_cost->number)
                rrb(top_stack_b, end_stack_b);
        }
        if (moves_to_nbr(top_stack_a, lower_cost->best_friend) == lower_cost->moves_put_bf_top)
            while (moves_to_extreme(1, top_stack_a, lower_cost->best_friend))
                ra(top_stack_a, end_stack_a);
        else
        {
            while (moves_to_extreme(0, end_stack_a, lower_cost->best_friend) && (*top_stack_a)->rank != lower_cost->best_friend)
                rra(top_stack_a, end_stack_a);
        }
        pa(top_stack_a, end_stack_a, top_stack_b, end_stack_b);
        free (lower_cost);
    }
    if (ft_lstsize(*top_stack_a) > 5)
    {
        if ((*top_stack_a)->next->rank != 1)
        {
           if (moves_to_extreme(1, top_stack_a, search_max_value(top_stack_a)) <= moves_to_extreme(0, end_stack_a, search_max_value(top_stack_a)))
              while (moves_to_extreme(1, top_stack_a, search_max_value(top_stack_a)))
                ra(top_stack_a, end_stack_a);
            else
                while (((*top_stack_a)->next->rank != 1) && moves_to_extreme(0, end_stack_a, search_max_value(top_stack_a)))
                    rra(top_stack_a, end_stack_a);
        }
        ra(top_stack_a, end_stack_a);
    }
}
