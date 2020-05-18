/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:20:16 by yu-lin            #+#    #+#             */
/*   Updated: 2020/05/18 16:45:36 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files		*new_file(const char *name)
{
	t_files		*new;

	new = (t_files *)malloc(sizeof(t_files));
	new->file_name = ft_strdup(name);
	new->next = NULL;
	return (new);
}

void	add_file(const char *name, t_files *files)
{
	t_files		*teleport;

	teleport = files;
	while (teleport->next != NULL)
		teleport = teleport->next;
	teleport->next = (t_files *)malloc(sizeof(t_files));
	teleport->next->file_name = ft_strdup(name);
	teleport->next->next = NULL;
}

t_files		*dynamic_file(char *name, t_files *head)
{
	t_files		*teleport;

	teleport = head;
	if (head == NULL)
	{
		head = new_file(name);
		teleport = head;
	}
	else
	{
		add_file(name, teleport);
		head = teleport;
	}
	return (head);
}

t_files		*direct_path(char *path, char *file_name)
{
	t_helpers	curr;
	t_files		*dir_path;
	
	dir_path = NULL;
	curr.tmp = ft_strjoin(path, "/");
	curr.buf = ft_strdup(curr.tmp);
	free(curr.tmp);
	curr.tmp = ft_strjoin(curr.buf, file_name);
	free(curr.buf);
	dir_path = dynamic_file(curr.tmp, dir_path);
	free(curr.tmp);
	return (dir_path);
}