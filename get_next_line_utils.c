/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:27:34 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 00:23:55 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 Parameters: 
      list: A pointer to the list of nodes containing the data to be checked
      for a newline character.
 Return value:
      Returns 1 if a newline character is found in any of the nodes' buffers,
      otherwise returns 0.
 Description:
      This function checks if any of the nodes in the list contain a newline 
      character in their buffer.
      It iterates through each node in the list, and for each node, it iterates
      through the characters in the node's buffer. If a newline character '\n'
      is found, the function immediately returns 1, indicating that a newline
      character has been found. If the end of the list is reached without 
      finding a newline character, the function returns 0, indicating that no
      newline character was found.
*/
int	has_newline(t_lst *list)
{
	t_lst	*current_node;
	char	*buffer_ptr;

	current_node = list;
	if (current_node == NULL)
		return (0);
	while (current_node != NULL)
	{
		buffer_ptr = current_node->buffer;
		while (*buffer_ptr)
		{
			if (*buffer_ptr == '\n')
				return (1);
			buffer_ptr++;
		}
		current_node = current_node->next;
	}
	return (0);
}

/*
 Parameters: 
      list: A pointer to the list of nodes containing the data to be duplicated
      into the string.
      str: A pointer to a pointer to the string where the data will be 
      duplicated.
 Description:
      This function duplicates the data from the list of nodes into the string
      pointed to by 'str'.
      It iterates through each node in the list, and for each node, it iterates
      through the characters in the node's buffer. Each character is copied
      from the node's buffer to the string. If a newline character '\n' is
      encountered, it is copied to the string, and the function immediately
      returns, indicating that the duplication process has been completed up
      to and including the newline character.
      The string is null-terminated after the last character copied. If the end
      of the list is reached without encountering a newline character, the
      function continues to copy characters until the end of the list is
      reached, and then null-terminates the string.
*/
void	duplicate_string(t_lst *list, char **str)
{
	t_lst	*current_node;
	char	*buffer_ptr;
	int		i;
	int		j;

	current_node = list;
	i = 0;
	while (current_node != NULL)
	{
		j = 0;
		buffer_ptr = current_node->buffer;
		while (buffer_ptr[j] != '\0')
		{
			if (buffer_ptr[j] == '\n')
			{
				(*str)[i] = '\n';
				(*str)[i + 1] = '\0';
				return ;
			}
			(*str)[i++] = buffer_ptr[j++];
		}
		current_node = current_node->next;
	}
	(*str)[i] = '\0';
}

/*
 Parameters: 
      list: A pointer to the list of nodes containing the data to be measured.
 Return value:
      Returns the length of the data up to and including the first newline
      character found.
      Returns 0 if the list is empty or if no newline character is found.
 Description:
      This function calculates the length of the data in the list up to and
      including the first
      newline character. It iterates through each node in the list, and for 
      each node, it iterates through the characters in the node's buffer. 
      The function increments a length counter for each character until a
      newline character '\n' is encountered. At this point, the function
      returns the current length plus one (to include the newline character
      in the count). If the end of the list is reached without finding a
      newline character, the function returns the total length of the data
      processed so far.
*/
int	length_until_newline(t_lst *list)
{
	t_lst	*current_node;
	int		length;
	char	*buffer_ptr;

	current_node = list;
	if (!current_node)
		return (0);
	length = 0;
	while (current_node)
	{
		buffer_ptr = current_node->buffer;
		while (*buffer_ptr != '\0')
		{
			if (*buffer_ptr == '\n')
				return (length + 1);
			buffer_ptr++;
			length++;
		}
		current_node = current_node->next;
	}
	return (length);
}

/*
 Parameters: 
      list: A pointer to the list of nodes to be released.
      node_to_clean: A pointer to the node that needs to be cleaned up.
      buffer: A pointer to the buffer that needs to be freed.
 Return value:
      None.
 Description:
      This function releases the memory allocated for the nodes in the list 
      and the buffer.
      It iterates through each node in the list, freeing the memory allocated
      for each node's buffer and the node itself. After freeing all nodes in
      the list, it checks if the buffer associated with 'node_to_clean' is not
      empty. If it is not empty, it assigns 'node_to_clean' as the new head of
      the list. Otherwise, it frees the memory allocated for 'buffer' and
      'node_to_clean'. This function ensures that all dynamically allocated 
      memory is properly released to prevent memory leaks.
*/
void	release_memory(t_lst **list, t_lst *node_to_clean, char *buffer)
{
	t_lst	*current_node;
	t_lst	*next_node;

	if (list == NULL || node_to_clean == NULL)
		return ;
	current_node = *list;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node->buffer);
		free(current_node);
		current_node = next_node;
	}
	*list = NULL;
	if (node_to_clean->buffer[0] != '\0')
		*list = node_to_clean;
	else
	{
		free(buffer);
		free(node_to_clean);
	}
}
