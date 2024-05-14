/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:33:59 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/14 14:27:55 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **top_of_stack_a)
{
    t_list *next;
    int temp;

    if (*top_of_stack_a)
    {
        next = (*top_of_stack_a)->next;
        if (next)
        {
            temp = (*top_of_stack_a)->number;
            (*top_of_stack_a)->number = next->number;
            next->number = temp;
            temp = (*top_of_stack_a)->rank;
            (*top_of_stack_a)->rank = next->rank;
            next->rank = temp;
        }
    }
    write(1, "sa\n", 3);
}

void sb(t_list **top_of_stack_b)
{
    t_list *next;
    int temp;

    if (*top_of_stack_b)
    {
        next = (*top_of_stack_b)->next;
        if (next)
        {
            temp = (*top_of_stack_b)->number;
            (*top_of_stack_b)->number = next->number;
            next->number = temp;
            temp = (*top_of_stack_b)->rank;
            (*top_of_stack_b)->rank = next->rank;
            next->rank = temp;
        }
    }
    write(1, "sb\n", 3);
}

void ss(t_list **top_of_stack_a, t_list **top_of_stack_b)
{
    sa(&(*top_of_stack_a));
    sb(&(*top_of_stack_b));
    write(1, "ss\n", 3);
}

void pa(t_list **top_of_stack_a, t_list **end_of_stack_a,
        t_list **top_of_stack_b, t_list **end_of_stack_b)
{
    t_list *element_to_move;

    if (*top_of_stack_b)
    {
        element_to_move = *top_of_stack_b;
        *top_of_stack_b = element_to_move->next;
        if (*top_of_stack_b != NULL)
            (*top_of_stack_b)->prev = NULL;
        else 
            *end_of_stack_b = NULL;
        element_to_move->prev = NULL;
        element_to_move->next = *top_of_stack_a;
        if (*top_of_stack_a != NULL)
            (*top_of_stack_a)->prev = element_to_move;
        else 
            *end_of_stack_a = element_to_move;
        *top_of_stack_a = element_to_move;
    }
    write(1, "pa\n", 3);
}

void pb(t_list **top_of_stack_a, t_list **end_of_stack_a,
        t_list **top_of_stack_b, t_list **end_of_stack_b)
{
    t_list *element_to_move;

    if (*top_of_stack_a)
    {
        element_to_move = *top_of_stack_a;
        *top_of_stack_a = element_to_move->next;
        if (*top_of_stack_a != NULL)
            (*top_of_stack_a)->prev = NULL;
        else 
            *end_of_stack_a = NULL;
        element_to_move->prev = NULL;
        element_to_move->next = *top_of_stack_b;
        if (*top_of_stack_b != NULL)
            (*top_of_stack_b)->prev = element_to_move;
        else 
            *end_of_stack_b = element_to_move;
        *top_of_stack_b = element_to_move;
    }
    write(1, "pb\n", 3);
}

void ra(t_list **top_of_stack_a, t_list **end_of_stack_a)
{
    t_list  *first_element;

    if (*top_of_stack_a)
    {
        first_element = *top_of_stack_a;
        *top_of_stack_a = first_element->next;
        if (*top_of_stack_a)
            (*top_of_stack_a)->prev = NULL;
        else 
            *end_of_stack_a = NULL;
        (*end_of_stack_a)->next = first_element;
        first_element->prev = *end_of_stack_a;
        first_element->next = NULL;
        (*end_of_stack_a)->next = first_element;
        *end_of_stack_a = first_element;
    }
    write(1, "ra\n", 3);
}

void rb(t_list **top_of_stack_b, t_list **end_of_stack_b)
{
    t_list  *first_element;

    if (*top_of_stack_b)
    {
        first_element = *top_of_stack_b;
        *top_of_stack_b = first_element->next;
        if (*top_of_stack_b)
            (*top_of_stack_b)->prev = NULL;
        else 
            *end_of_stack_b = NULL;
        (*end_of_stack_b)->next = first_element;
        first_element->prev = *end_of_stack_b;
        first_element->next = NULL;
        (*end_of_stack_b)->next = first_element;
        *end_of_stack_b = first_element;
    }
    write(1, "rb\n", 3);
}

void rr(t_list **top_of_stack_a, t_list **end_of_stack_a,
        t_list **top_of_stack_b, t_list **end_of_stack_b)
{
    ra(&(*top_of_stack_a), &(*end_of_stack_a));
    rb(&(*top_of_stack_b), &(*end_of_stack_b));
    write(1, "rr\n", 3);
}

void rra(t_list **top_of_stack_a, t_list **end_of_stack_a)
{
    t_list  *last_element;

    if (*top_of_stack_a)
    {
        last_element = *end_of_stack_a;
        *end_of_stack_a = last_element->prev;
        if (*end_of_stack_a)
            (*end_of_stack_a)->next = NULL;
        else 
            *top_of_stack_a = NULL;
        (*top_of_stack_a)->prev = last_element;
        last_element->next = *top_of_stack_a;
        last_element->prev = NULL;
        *top_of_stack_a = last_element;
    }
    write(1, "rra\n", 4);
}

void rrb(t_list **top_of_stack_b, t_list **end_of_stack_b)
{
    t_list  *last_element;

    if (*top_of_stack_b)
    {
        last_element = *end_of_stack_b;
        *end_of_stack_b = last_element->prev;
        if (*end_of_stack_b)
            (*end_of_stack_b)->next = NULL;
        else 
            *top_of_stack_b = NULL;
        (*top_of_stack_b)->prev = last_element;
        last_element->next = *top_of_stack_b;
        last_element->prev = NULL;
        *top_of_stack_b = last_element;
    }
    write(1, "rrb\n", 4);
}

void rrr(t_list **top_of_stack_a, t_list **end_of_stack_a,
        t_list **top_of_stack_b, t_list **end_of_stack_b)
{
    rra(&(*top_of_stack_a), &(*end_of_stack_a));
    rrb(&(*top_of_stack_b), &(*end_of_stack_b));
    write(1, "rrr\n", 4);
}
