/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:45:05 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/14 11:22:34 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WRONG_INPUT 1
# define WRONG_MALLOC NULL
# define ALL_GOOD 0
# define DUPLICATED 1

typedef struct s_list
{
	int             number;
	int				rank;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_table
{
	int             number;
	int				best_friend;
	int				moves_put_nbr_top;
	int				moves_put_bf_top;
	int				cost;
}	t_table;

/*OPERATIONS*/
void	sa(t_list **top_of_stack_a);
void	sb(t_list **top_of_stack_b);
void	ss(t_list **top_of_stack_a, t_list **top_of_stack_b);
void	pa(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b);
void	pb(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b);
void	ra(t_list **top_of_stack_a, t_list **end_of_stack_a);
void	rb(t_list **top_of_stack_b, t_list **end_of_stack_b);
void	rr(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b);
void	rra(t_list **top_of_stack_a, t_list **end_of_stack_a);
void	rrb(t_list **top_of_stack_b, t_list **end_of_stack_b);
void	rrr(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b);

/*BUILD STRUCTURE*/
int		ft_strlen(const char *s);
int		check_for_letters(char *str);
int		ft_atoi_str(const char *nptr, int *i);
int		ft_atoi(const char *nptr);
t_list	*add_node_end(int nbr, t_list **end_of_stack);
int		create_structure(int argc, char **argv,
		t_list **top_of_stack, t_list **end_of_stack);
int		create_structure_str(char *argv,
		t_list **top_of_stack, t_list **end_of_stack);
int		search_nbr_list(int nbr, t_list *top_of_stack);

/*RANKING*/
void    ranking_structure(t_list **top_of_stack);
int     all_ranks_filled(t_list *top_of_stack);

/*ALGORITHM UTILS*/
int		ft_lstsize(t_list *lst);
int		sum_lst(t_list *lst);
int		average(t_list *top_of_stack_a);
int		smaller_number(t_list **top_of_stack);
int		calculate_best_friend(t_list **top_of_stack, int number);
int		moves_to_extreme(int top, t_list **border_of_stack, int number);
int		calculate_moves(t_list **top_of_stack, t_list **end_of_stack,
		int number);

/*ALGORITHM*/
void	move_above_average(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b);
void	sort_three_stack(t_list **top_of_stack_a, t_list **end_of_stack_a);
int     search_max_value(t_list **top_of_stack_a);
void    pb_max(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b);
void	sort_five_stack(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b);
t_table	*find_lower_cost(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b);
int     moves_to_nbr(t_list **top_of_stack_b, int number);
void    main_algorithm(t_list **top_of_stack_a, t_list **end_of_stack_a,
		t_list **top_of_stack_b, t_list **end_of_stack_b);



int	ft_isdigit(int c);
int check_spaces(char *str);

#endif