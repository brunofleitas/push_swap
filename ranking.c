/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:09:28 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/14 14:30:15 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     all_ranks_filled(t_list *top_of_stack)
{
    t_list  *iter;

    iter = top_of_stack;
    while (iter)
    {
        if (iter->rank == 0)
            return (0);
        iter = iter->next;
    }
    return(1);
}

void    ranking_structure(t_list **top_of_stack)
{
    t_list  *current;
    t_list  *min;
    int     min_nbr;
    int     rank;

    if (*top_of_stack)
    {
        rank = 1;
        while (!all_ranks_filled(*top_of_stack))
        {
            min = NULL;
            min_nbr = 2147483647;
            current = *top_of_stack;
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
            rank++;
        }
    }
}
