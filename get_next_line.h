/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:52:41 by bfleitas          #+#    #+#             */
/*   Updated: 2024/05/17 00:22:37 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/*STRUCTURE*/
typedef struct slist
{
	char			*buffer;
	struct slist	*next;
}	t_lst;

/*PRINCIPAL FUNCTION*/
char				*get_next_line(int fd);

/*BUILD STRUCTURE*/
void				build_list(t_lst **list, int fd);
void				add_new_node(t_lst **list, char *buf, int fd);

/*VALIDATION*/
int					has_newline(t_lst *list);

/*RETURN VALUE*/
char				*get_line(t_lst *list);

/*UTILS*/
void				duplicate_string(t_lst *list, char **str);
int					length_until_newline(t_lst *list);

/*CLEANING MEMORY*/
void				refine_list(t_lst **list);
void				release_memory(t_lst **list, t_lst *node_to_clean,
						char *buffer);

#endif
