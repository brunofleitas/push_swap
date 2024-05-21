/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:45:05 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/21 15:06:49 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define WRONG_INPUT 1
# define ALL_GOOD 0
# define DUPLICATED 1

typedef struct s_list
{
	int				number;
	int				rank;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_table
{
	int				number;
	int				best_friend;
	int				moves_put_nbr_top;
	int				moves_put_bf_top;
	int				cost;
}					t_table;

/* ************************************************************************** */
/* 1_MAIN.C                                                                   */
/* ************************************************************************** */

void				case_argv_more_2(int argc, char **argv);
void				case_argv_2(char **argv);
void				ft_lstclear(t_list **lst);

/* ************************************************************************** */
/* 2_GENERATE_LIST.C                                                          */
/* ************************************************************************** */

int					create_structure(int argc, char **argv,
						t_list **top_of_stack, t_list **end_of_stack);
int					process_input_and_stack(char **argv, int i,
						t_list **top_of_stack, t_list **end_of_stack);
t_list				*add_node_end(int nbr, t_list **end_of_stack);
int					search_nbr_list(int nbr, t_list *top_of_stack);
int					ft_atoi(const char *nptr);

/* ************************************************************************** */
/* 2_COMPUTE_STRING.C                                                         */
/* ************************************************************************** */

int					create_structure_str(char *argv, t_list **top_of_stack,
						t_list **end_of_stack);
int					process_input_stack_str(char *argv, int *i,
						t_list **top_of_stack, t_list **end_of_stack);
int					ft_atoi_str(const char *nptr, int *i);

/* ************************************************************************** */
/* 2_GENERATING_UTILS.C                                                       */
/* ************************************************************************** */

int					check_spaces(char *str);
int					ft_isdigit(int c);
int					check_for_letters(char *str);
int					ft_strlen(const char *s);

/* ************************************************************************** */
/* 3_RANKING.C                                                                */
/* ************************************************************************** */

void				ranking_structure(t_list **top_of_stack);
void				assign_min_rank(t_list **top_of_stack, int rank);
int					all_ranks_filled(t_list *top_of_stack);

/* ************************************************************************** */
/* 4_PUSH_OPERATIONS.C                                                        */
/* ************************************************************************** */

void				run_pa(t_list **top_of_stack_a, t_list **end_of_stack_a,
						t_list **top_of_stack_b, t_list **end_of_stack_b);
void				pa(t_list **top_of_stack_a, t_list **end_of_stack_a,
						t_list **top_of_stack_b, t_list **end_of_stack_b);
void				run_pb(t_list **top_of_stack_a, t_list **end_of_stack_a,
						t_list **top_of_stack_b, t_list **end_of_stack_b);
void				pb(t_list **top_of_stack_a, t_list **end_of_stack_a,
						t_list **top_of_stack_b, t_list **end_of_stack_b);

/* ************************************************************************** */
/* 4_REVERSE_ROTATE_OPERATIONS.C                                              */
/* ************************************************************************** */

void				rra(t_list **top_of_stack_a, t_list **end_of_stack_a);
void				run_rra(t_list **top_of_stack_a, t_list **end_of_stack_a);
void				rrb(t_list **top_of_stack_b, t_list **end_of_stack_b);
void				run_rrb(t_list **top_of_stack_b, t_list **end_of_stack_b);
void				rrr(t_list **top_of_stack_a, t_list **end_of_stack_a,
						t_list **top_of_stack_b, t_list **end_of_stack_b);

/* ************************************************************************** */
/* 4_ROTATE_OPERATIONS.C                                                      */
/* ************************************************************************** */

void				ra(t_list **top_of_stack_a, t_list **end_of_stack_a);
void				run_ra(t_list **top_of_stack_a, t_list **end_of_stack_a);
void				rb(t_list **top_of_stack_b, t_list **end_of_stack_b);
void				run_rb(t_list **top_of_stack_b, t_list **end_of_stack_b);
void				rr(t_list **top_of_stack_a, t_list **end_of_stack_a,
						t_list **top_of_stack_b, t_list **end_of_stack_b);

/* ************************************************************************** */
/* 4_SWAP_OPERATIONS.C                                                        */
/* ************************************************************************** */

void				sa(t_list **top_of_stack_a);
void				run_sa(t_list **top_of_stack_a);
void				sb(t_list **top_of_stack_b);
void				run_sb(t_list **top_of_stack_b);
void				ss(t_list **top_of_stack_a, t_list **top_of_stack_b);

/* ************************************************************************** */
/* 4_OPERATIONS_EXTRA.C                                                       */
/* ************************************************************************** */

void				run_rrr(t_list **top_of_stack_a, t_list **end_of_stack_a,
						t_list **top_of_stack_b, t_list **end_of_stack_b);
void				run_rr(t_list **top_of_stack_a, t_list **end_of_stack_a,
						t_list **top_of_stack_b, t_list **end_of_stack_b);
void				run_ss(t_list **top_of_stack_a, t_list **top_of_stack_b);

/* ************************************************************************** */
/* 5_ALGORITHM_UTILS.C                                                        */
/* ************************************************************************** */

int					calculate_moves(t_list **top_of_stack,
						t_list **end_of_stack, int number);
int					moves_to_extreme(int top, t_list **border_of_stack,
						int number);
int					calculate_best_friend(t_list **top_of_stack, int number);
int					smaller_number(t_list **top_of_stack);

/* ************************************************************************** */
/* 5_ALGORITHM.C                                                              */
/* ************************************************************************** */

void				main_algorithm(t_list **top_stack_a, t_list **end_stack_a,
						t_list **top_stack_b, t_list **end_stack_b);

/* ************************************************************************** */
/* 5_CALCULATE_AVERAGE.C                                                      */
/* ************************************************************************** */

int					average(t_list *top_of_stack_a);
int					sum_lst(t_list *lst);
int					ft_lstsize(t_list *lst);

/* ************************************************************************** */
/* 5_FIND_LOWER_COST.C                                                        */
/* ************************************************************************** */

t_table				*find_lower_cost(t_list **top_stack_a, t_list **end_stack_a,
						t_list **top_stack_b, t_list **end_stack_b);
void				asign_tmp(t_table *tmp, t_list **top_stack_a,
						t_list **top_stack_b);
void				update_lower_cost_if_better(t_table *lower_cost,
						t_table *tmp);
t_table				*initialize_lower_cost(t_list **top_stack_a,
						t_list **end_stack_a, t_list **top_stack_b,
						t_list **end_stack_b);

/* ************************************************************************** */
/* 5_MAIN_ALGORITHM_UTILS.C                                                   */
/* ************************************************************************** */

void				apply_a_moves(t_list **top_stack_a, t_list **end_stack_a,
						t_table *lower_cost);
void				apply_b_moves(t_list **top_stack_b, t_list **end_stack_b,
						t_table *lower_cost);
void				final_rotation(t_list **top_stack_a, t_list **end_stack_a);
int					check_if_is_it_sorted(t_list **top_stack_a);
int					moves_to_nbr(t_list **top_stack_b, int number);

/* ************************************************************************** */
/* 5_SORTING_THREE_AND_FIVE.C                                                 */
/* ************************************************************************** */

void				sort_five_stack(t_list **top_stack_a, t_list **end_stack_a,
						t_list **top_stack_b, t_list **end_stack_b);
void				pb_max(t_list **top_stack_a, t_list **end_stack_a,
						t_list **top_stack_b, t_list **end_stack_b);
int					search_max_value(t_list **top_stack_a);
void				move_above_average(t_list **top_stack_a,
						t_list **end_stack_a, t_list **top_stack_b,
						t_list **end_stack_b);
void				sort_three_stack(t_list **top_stack_a,
						t_list **end_stack_a);

/* ************************************************************************** */
/* 6_CHECKER.C                                                                */
/* ************************************************************************** */

void				case_argv_more_2_checker(int argc, char **argv);
void				case_argv_2_checker(char **argv);
void				checker_algorithm(t_list **top_stack_a,
						t_list **end_stack_a, t_list **top_stack_b);
void				run_operation(char *op, t_list **top_stack_a,
						t_list **end_stack_a, t_list **top_stack_b);

/* ************************************************************************** */
/* 6_CHECKER_UTILS.C                                                          */
/* ************************************************************************** */

void				run_rot_op(char *op, t_list **top_stack_a,
						t_list **end_stack_a, t_list **top_stack_b);
void				run_rev_rot_op(char *op, t_list **top_stack_a,
						t_list **end_stack_a, t_list **top_stack_b);
void				run_push_op(char *op, t_list **top_stack_a,
						t_list **end_stack_a, t_list **top_stack_b);
void				run_swap_op(char *op, t_list **top_stack_a,
						t_list **top_stack_b);
void				ft_listclear(t_list **lst);

#endif
