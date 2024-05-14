/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:21:40 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/14 14:29:17 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int check_for_letters(char *str)
{
    int i;

    i = 0;
	if (str[0] == '\0')
		return (1);
    while (str[i] != '\0')
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' ||
			str[i] == '+' ||str[i] == ' '))
            return (1);
        i++;
    }
    return(0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int check_spaces(char *str)
{
    int i;

	i = 0;
    while (str[i] != '\0') {
        if ((ft_isdigit(str[i]) && str[i + 1] != '\0') && (!ft_isdigit(str[i + 1]) && str[i + 1] != ' '))
            return (1);
        i++;
    }
    return (0);
}


int	ft_atoi_str(const char *nptr, int *i)
{
	int	sign;
	long	result;

	result = 0;
	sign = 1;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (nptr[*i] != 0 && (nptr[*i] >= '0' && nptr[*i] <= '9'))
	{
		result = (nptr[*i] - '0') + (result * 10);
		(*i)++;
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483648)
		return (0);
	else 
		return (int)result;
}

int	create_structure_str(char *argv,
	t_list **top_of_stack, t_list **end_of_stack)
{
	int		nbr;
	int 	i;

	if (check_spaces(argv) || check_for_letters(argv))
		return (WRONG_INPUT);
	i = 0;
	while (i != ft_strlen(argv))
	{
		while (argv[i] != 0 && ((argv[i] == ' ')
			|| (argv[i] >= 9 && argv[i] <= 13)))
		i++;
		if (argv[i] == '0' && argv[i + 1] == ' ')
		{
			nbr = 0;
			i++;
		}
		else
		{
			nbr = ft_atoi_str(argv, &i);
			if (nbr == 0)
				return (WRONG_INPUT);
		}
		if (!search_nbr_list(nbr, *top_of_stack))
		{
			if (!*top_of_stack)
				*top_of_stack = add_node_end(nbr, end_of_stack);
			else 
				*end_of_stack = add_node_end(nbr, end_of_stack);
		}
		else 
			return (WRONG_INPUT);
	}
	return (ALL_GOOD);
}
