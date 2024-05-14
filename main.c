/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:51 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/14 14:44:11 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
#include "operations.c"
#include "generate_list.c"
#include "ranking.c"
#include "compute_string.c"
#include "algorithm_utils.c"
#include "algorithm.c"
*/

/*
int	main(int argc, char	**argv)//(void)//
{
    int argc = 6;
    char **argv = (char **)malloc(argc * sizeof(char *));
    if (argv == NULL)
        return 1;
    argv[0] = "program";
    argv[1] = "3";
    argv[2] = "2";
    argv[3] = "0";
    argv[4] = "1";
    argv[5] = "5";
	int		error;
	t_list	*top_of_stack_a;
	t_list	*end_of_stack_a;
    t_list  *printa;
    t_list  *printb;
	t_list	*top_of_stack_b;
	t_list	*end_of_stack_b;

	top_of_stack_a = NULL;
	end_of_stack_a = NULL;
	top_of_stack_b = NULL;
	end_of_stack_b = NULL;
	if (argc == 2)
	{
		create_structure_str(argv[1], &top_of_stack_a, &end_of_stack_a); //error =
		ranking_structure(&top_of_stack_a);
		main_algorithm(&top_of_stack_a, &end_of_stack_a, &top_of_stack_b, &end_of_stack_b);
		if (error)
			write (1, "Error\n", 6);
		else 
		{
			printa = top_of_stack_a;
			printb = top_of_stack_b;
     	    while (printa)
    	    {
    	        printf ("%i\n", printa->number);
				printf ("%i\n", printa->rank);
				printf("\n");
    	        printa = printa->next;
    	    }
			printf("\n");
    	    while (printb)
    	    {
    	        printf ("%i\n", printb->number);
				0printf ("%i\n", printa->rank);
				printf("\n");
    	        printb = printb->next;
    	    }
    	}
	}
	if (argc > 2)
	{
		create_structure(argc, argv, &top_of_stack_a, &end_of_stack_a); //error =
		ranking_structure(&top_of_stack_a);
		main_algorithm(&top_of_stack_a, &end_of_stack_a, &top_of_stack_b, &end_of_stack_b);
		if (error)
			write (1, "Error\n", 6);
		else
		{
			printa = top_of_stack_a;
			printb = top_of_stack_b;
     	    while (printa)
    	    {
    	        printf ("%i\n", printa->number);
				printf ("%i\n", printa->rank);
				printf("\n");
    	        printa = printa->next;
    	    }
			printf("\n");
    	    while (printb)
    	    {
    	        printf ("%i\n", printb->number);
				printf ("%i\n", printa->rank);
				printf("\n");
    	        printb = printb->next;
    	    }
    	}
	}
	return (1);
}*/

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (lst && *lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	main(int argc, char	**argv)
{
//	int argc = 2;
//	char *argv[] = {"program", "2147483645 2147483646 2147483647"};
	int		error;
	t_list	*top_stack_a;
	t_list	*end_stack_a;
	t_list	*top_stack_b;
	t_list	*end_stack_b;
//	t_list  *printa;
//  t_list  *printb;

	top_stack_a = NULL;
	end_stack_a = NULL;
	top_stack_b = NULL;
	end_stack_b = NULL;
	if (argc == 2)
	{
		error = create_structure_str(argv[1], &top_stack_a, &end_stack_a);
		if (error)
		{
			write (2, "Error\n", 6);
			exit (1);
		}	
		else
		{
			ranking_structure(&top_stack_a);
			main_algorithm(&top_stack_a, &end_stack_a, &top_stack_b, &end_stack_b);
			/*
			printa = top_stack_a;
			printb = top_stack_b;
     	    while (printa)
    	    {
    	        printf ("%i\n", printa->number);
				printf ("%i\n", printa->rank);
				printf("\n");
    	        printa = printa->next;
    	    }
			printf("\n");
    	    while (printb)
    	    {
    	        printf ("%i\n", printb->number);
				printf ("%i\n", printa->rank);
				printf("\n");
    	        printb = printb->next;
    	    }*/
		}
		ft_lstclear(&top_stack_a);
	}
	if (argc > 2)
	{
		error = create_structure(argc, argv, &top_stack_a, &end_stack_a);
		if (error)
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		else
		{
			ranking_structure(&top_stack_a);
			main_algorithm(&top_stack_a, &end_stack_a, &top_stack_b, &end_stack_b);
			/*
			printa = top_stack_a;
			printb = top_stack_b;
     	    while (printa)
    	    {
    	        printf ("%i\n", printa->number);
				printf ("%i\n", printa->rank);
				printf("\n");
    	        printa = printa->next;
    	    }
			printf("\n");
    	    while (printb)
    	    {
    	        printf ("%i\n", printb->number);
				printf ("%i\n", printa->rank);
				printf("\n");
    	        printb = printb->next;
    	    }*/
			
		}
		ft_lstclear(&top_stack_a);
	}
	return (1);
}
