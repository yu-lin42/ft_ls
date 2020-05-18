/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:57:58 by yu-lin            #+#    #+#             */
/*   Updated: 2020/05/19 00:05:33 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_structure(char *flags)
{
	if (ft_strchr(flags, 'R'))
		recursive(".", flags);
	else
		no_recursive(".", flags);
}

void	recursive(char *path, char *flags)
{
	t_helpers	current;
	t_files		*files;
	t_files		*dir_path;

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
		current.tmp = ft_strjoin(current.buf, ((current.mydirent->d_name)));
		files = dynamic_file(current.tmp, files);
		free(current.tmp);
	}
	closedir(current.mydir);
	sort_display(files, flags);
	repeat(dir_path, flags);
}

void	no_recursive(char *path, char *flags)
{
	t_helpers	current;
	t_files		*files;

	files = NULL;
	current.mydir = opendir(path);
	while ((current.mydirent = readdir(current.mydir)))
	{
		if (!ft_strchr(flags, 'a') && current.mydirent->d_name[0] == '.')
			continue;
		files = dynamic_file((current.mydirent)->d_name, files);
	}
	closedir(current.mydir);
	sort_display(files, flags);
}

void	list_them(t_files *list)
{
	t_files			*tmp;

	while (list != NULL)
	{
		show_modes(list);
		show_stats(list);
		ft_putchar(' ');
		ft_putendl(list->file_name);
		free(list->file_name);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}