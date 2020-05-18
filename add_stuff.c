/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:20:16 by yu-lin            #+#    #+#             */
/*   Updated: 2020/05/18 22:13:16 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_all(char *path, char *flags, t_files *files, t_files *dir_path)
{
	t_helpers	current;
	// t_files		*files;
	// t_files		*dir_path;
	// t_files		*tmp;

	files = NULL;
	dir_path = NULL;
	current.mydir = opendir(path);
	current.tmp = ft_strjoin(path, "/");
	current.buf = ft_strdup(current.tmp);
	free(current.tmp);
	while ((current.mydirent = readdir(current.mydir)))
	{
		if (!ft_strchr(flags, 'a') && current.mydirent->d_name[0] == '.')
			continue;
		if ((current.mydirent)->d_type == DT_DIR)
			dir_path = direct_path(current.buf, ((current.mydirent)->d_name));
		current.tmp = ft_strjoin(current.buf, (current.mydirent)->d_name);
		files = dynamic_file(current.tmp, files);
		free(current.tmp);
	}
	closedir(current.mydir);
}

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
	curr.tmp = ft_strjoin(path, file_name);
	dir_path = dynamic_file(curr.tmp, dir_path);
	free(curr.tmp);
	return (dir_path);
}