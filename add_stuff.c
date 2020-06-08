/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:20:16 by yu-lin            #+#    #+#             */
/*   Updated: 2020/05/27 02:43:45 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files		*new_file(const char *name, char *path)
{
	t_files		*new;
	char		*tmp;
	char		*file_path;

	tmp = ft_strjoin(path, "/");
	file_path = ft_strjoin(tmp, name);
	free(tmp);
	new = (t_files *)malloc(sizeof(t_files));
	new->file_name = ft_strdup(name);
	if (*name == '/')
		new->dir_path = ft_strdup("/");
	else
		new->dir_path = ft_strdup(file_path);
	free(file_path);
	new->next = NULL;
	return (new);
}

void	add_file(const char *name, char *path, t_files *files)
{
	t_files		*teleport;
	char		*tmp;
	char		*file_path;

	teleport = files;
	tmp = ft_strjoin(path, "/");
	file_path = ft_strjoin(tmp, name);
	free(tmp);
	while (teleport->next != NULL)
		teleport = teleport->next;
	teleport->next = (t_files *)malloc(sizeof(t_files));
	teleport->next->file_name = ft_strdup(name);
	if (*name == '/')
		teleport->next->dir_path = ft_strdup(name);
	else
		teleport->next->dir_path = ft_strdup(file_path);
	free(file_path);
	teleport->next->next = NULL;
}

t_files		*dynamic_file(char *path, char *name, t_files *head)
{
	t_files		*teleport;

	teleport = head;
	if (head == NULL)
	{
		head = new_file(name, path);
		teleport = head;
	}
	else
	{
		add_file(name, path, teleport);
		head = teleport;
	}
	return (head);
}

// void	add_dir_path(char *path, char *file_name, t_files *list)
// {
// 	t_helpers	curr;
// 	t_files		*teleport;
	
// 	teleport = list;
// 	curr.tmp = ft_strjoin(path, file_name);
// 	teleport->dir_path = ft_strdup(curr.tmp);
// 	free(curr.tmp);
// }

// void	sort_display(t_files *files, char *flags)
// {
// 	if (files != NULL)
// 		sort_sequence(files, flags);
// 	if (ft_strchr(flags, 'l'))
// 		list_them(files);
// 	else
// 		print_list(&files);
// }