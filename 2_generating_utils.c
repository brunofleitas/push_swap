/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-generating_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:21:50 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/15 15:20:05 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  Parameters:
    s: A pointer to a null-terminated character string whose length is to be 
	determined.
  Return value:
    The length of the string, excluding the null terminator.
  Description:
    This function iterates through each character in the input string until it 
	encounters the null terminator ('\0'), incrementing a counter for each 
	character. The counter represents the length of the string, which is then 
	returned. This function is commonly used to determine the size of a string 
	before performing operations that require knowledge of the string's length.
*/
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

/*
  Parameters:
    str: A pointer to a null-terminated character string to be checked.
  Return value:
    1: Indicates that a character other than a digit, space, '+' or '-' was 
	found in the string.
    0: Indicates that no such character was found in the string.
  Description:
    This function iterates through each character in the input string. For 
	each character, it checks if the character is a digit, a space, or one of 
	the allowed signs ('+' or '-'). If the character does not meet these 
	criteria, it indicates an incorrect format, and the function returns 1. 
	If no such character is found throughout the entire string, the function 
	returns 0, indicating that the string contains only allowed characters.
*/
int	check_for_letters(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'
				|| str[i] == ' '))
			return (1);
		i++;
	}
	return (0);
}

/*
  Parameters:
    c: The character to be tested.
  Return value:
    1: Indicates that the character is a digit (0-9).
    0: Indicates that the character is not a digit.
  Description:
    This function checks if the ASCII value of the character `c` falls within 
	the range of ASCII values for the digits 0 through 9 (48 to 57 inclusive). 
	If the character is a digit, the function returns 1; otherwise, it returns 
	0. This function is useful for validating input strings or performing 
	arithmetic operations on individual characters.
*/
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*
  Parameters:
    str: A pointer to a null-terminated character string to be checked.
  Return value:
    1: Indicates that a space was found between consecutive digits in the 
	string.
    0: Indicates that no such space was found in the string.
  Description:
    This function iterates through each character in the input string. For 
	each character, it checks if the current character is a digit and if the 
	next character is not a digit or a space. If both conditions are met, it 
	means there is a space between consecutive digits, indicating an incorrect 
	format, and the function returns 1. If no such condition is met throughout 
	the entire string, the function returns 0, indicating that the string does 
	not contain spaces between consecutive digits.
*/
int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_isdigit(str[i]) && str[i + 1] != '\0')
			&& (!ft_isdigit(str[i + 1]) && str[i + 1] != ' '))
			return (1);
		i++;
	}
	return (0);
}
