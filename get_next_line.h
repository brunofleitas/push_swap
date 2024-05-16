/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:52:41 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/16 15:42:15 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

/*STRUCTURE*/
typedef struct slist
{
	char			*buffer;
	struct slist	*next;
}	tlist;

/*PRINCIPAL FUNCTION*/
char	*get_next_line(int fd);

/*BUILD STRUCTURE*/
void	build_list(tlist **list, int fd);
void	add_new_node(tlist **list, char *buf, int fd);

/*VALIDATION*/
int		has_newline(tlist *list);

/*RETURN VALUE*/
char	*get_line(tlist *list);

/*UTILS*/
void	duplicate_string(tlist *list, char **str);
int		length_until_newline(tlist *list);

/*CLEANING MEMORY*/
void	refine_list(tlist **list);
void	release_memory(tlist **list, tlist *node_to_clean, char *buffer);

#endif
