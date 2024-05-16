/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 23:43:45 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/16 15:35:12 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 Parameters: 
      list: A pointer to the list of nodes to be refined.
 Description:
      This function refines the list by removing the processed part of the data
      up to and including the newline character from the last node in the list.
      It allocates a new buffer to hold the remaining data and a new node to
      replace the last node with the refined data. The function then releases
      the memory of the original last node and its buffer.
      The refined data starts from the character following the newline
      character in the last node's buffer. If memory allocation fails for the
      new buffer or node, the function returns without making any changes.
*/
void	refine_list(tlist **list)
{
	tlist	*last_node;
	tlist	*node_to_clean;
	int		i;
	int		buffer_index;
	char	*buffer;

	last_node = *list;
	while (last_node != NULL && last_node->next != NULL)
		last_node = last_node->next;
	buffer = malloc(BUFFER_SIZE + 1);
	node_to_clean = malloc(sizeof(tlist));
	if (buffer == NULL || node_to_clean == NULL)
		return ;
	i = 0;
	buffer_index = 0;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		++i;
	while (last_node->buffer[i] && last_node->buffer[++i])
		buffer[buffer_index++] = last_node->buffer[i];
	buffer[buffer_index] = '\0';
	node_to_clean->buffer = buffer;
	node_to_clean->next = NULL;
	release_memory(list, node_to_clean, buffer);
}

/*
 Parameters: 
      list: A pointer to the list of nodes containing the data to be processed.
 Return value:
      A pointer to the string containing the next line extracted from the list.
      Returns NULL if the list is empty or if memory allocation fails.
 Description:
      This function extracts the next line from the list of nodes. It 
      calculates the length of the line up to the next newline character using
      the 'length_until_newline' function. It then allocates memory for a new
      string to hold the line and duplicates the line from the list into this
      new string using the 'duplicate_string' function. The function returns
      the new string containing the line. If the list is empty or if memory
      allocation fails, the function returns NULL.
*/
char	*get_line(tlist *list)
{
	int		line_length;
	char	*next_line;

	line_length = 0;
	if (list == NULL)
		return (NULL);
	line_length = length_until_newline(list);
	next_line = malloc(line_length + 1);
	if (next_line == NULL)
		return (NULL);
	duplicate_string(list, &next_line);
	return (next_line);
}

/*
 Parameters: 
      list: A pointer to the list of nodes where the new node will be added.
      buffer: A pointer to the buffer containing the data to be stored in the
      new node.
      fd: An integer representing the file descriptor associated with the data.
 Description:
      This function adds a new node to the list at the specified file 
      descriptor index.
      It allocates memory for a new node, assigns the buffer to the new node's
      buffer field, and sets the new node's next pointer to NULL. If the list
      at the specified file descriptor index is empty, the new node becomes the
      head of the list. Otherwise, the function iterates through the list to
      find the last node and appends the new node to the end.
*/
void	add_new_node(tlist **list, char *buffer, int fd)
{
	tlist	*new_node;
	tlist	*current_node;

	current_node = list[fd];
	new_node = (tlist *)malloc(sizeof(tlist));
	if (new_node == NULL)
		return ;
	new_node->buffer = buffer;
	new_node->next = NULL;
	if (current_node == NULL)
		list[fd] = new_node;
	else
	{
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
}

/*
 Parameters: 
      list: A pointer to the list of nodes where the data will be stored.
      fd: An integer representing the file descriptor from which to read the 
      data.
 Description:
      This function builds a list of nodes by reading data from the file 
      descriptor 'fd'.
      It allocates a buffer of size 'BUFFER_SIZE + 1' and reads data from the
      file descriptor into this buffer. The function continues to read and add
      data to the list until a newline character is encountered or an error
      occurs during reading. Each node in the list contains a portion of the
      data read from the file descriptor. If an error occurs during memory
      allocation or reading, the function frees any allocated memory and return
*/
void	build_list(tlist **list, int fd)
{
	int		bytes_read;
	char	*buffer;

	if (list == NULL)
		return ;
	while (!has_newline(list[fd]))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		add_new_node(list, buffer, fd);
	}
}

/*
 Parameters: 
      fd: An integer representing the file descriptor from which to read the 
      next line.
 Return value:
      A pointer to the string containing the next line read from the file 
      descriptor.
      Returns NULL if an error occurs or if there is nothing more to read.
 Description:
      This function reads the next line from the file descriptor specified by 
      'fd'.
      It utilizes a static list to manage multiple file descriptors 
      simultaneously, ensuring that each call to 'get_next_line' returns the 
      next line from the corresponding file descriptor. The function reads 
      characters piece by piece into a buffer with a specified size, processing
      the buffer to extract and return the next line. If an error occurs during
      reading or if there is nothing more to read, the function returns NULL.
*/
char	*get_next_line(int fd)
{
	static tlist	*list[4096];
	char			*line;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	build_list(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	line = get_line(list[fd]);
	refine_list(&list[fd]);
	return (line);
}
