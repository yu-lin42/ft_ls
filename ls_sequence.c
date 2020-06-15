#include "ft_ls.h"
#include <stdio.h>

void	just_flags(char *flags)
{
	t_files *files;

	files = NULL;
	if (ft_strchr(flags, 'R'))
	{
		files = dot_or_not(flags, ".");
		recursive(flags, files, ".");
	}
	else
	{
		files = dot_or_not(flags, ".");
		non_recursive(flags, files);
	}
}

void	recursive(char *flags, t_files *list, char *path)
{
	t_files		*files;
	t_files		*dir;

	files = NULL;
	dir = directory(path);
	sort_display(list, flags);
	while (dir != NULL)
	{
		if (dir->file_name[0] != '.')
		{
			ft_putchar('\n');
			ft_putstr(dir->file_name);
			ft_putendl(": ");
			files = dot_or_not(flags, dir->dir_path);
			recursive(flags, files, dir->dir_path);
		}
		free(dir->file_name);
		free(dir->dir_path);
		free(dir);
		dir = dir->next;
	}
	free_list(dir);
	free_list(files);
}


void	non_recursive(char *flags, t_files *list)
{
	sort_display(list, flags);
	free_list(list);
}

void	just_files(t_files *list)
{
	t_files		*files;
	t_files		*dir;

	files = NULL;
	dir = NULL;
	while (list != NULL)
	{
		if (is_dir(list->dir_path))
			dir = dynamic_file(".", list->file_name, dir);
		else
			files = dynamic_file(".", list->file_name, files);
		free(list->file_name);
		free(list->dir_path);
		free(list);
		list = list->next;
	}
	if (files != NULL && dir == NULL) //just files
		sort_display(files, NULL);
	else if (files == NULL && dir->next == NULL) //just 1 directory, no files
	{
		files = basic(dir->dir_path);
		sort_display(files, NULL);
		free_list(dir);
	}
	else if (dir != NULL) //files and more than 1 directory
	{
		if (files != NULL)
		{
			sort_display(files, NULL);
			ft_putchar('\n');
		}
		sort_files(dir);
		while (dir != NULL)
		{
			ft_putstr(dir->file_name);
			ft_putendl(":");
			files = basic(dir->dir_path);
			sort_display(files, NULL);
			if (dir->next != NULL)
				ft_putchar('\n');
			free(dir->file_name);
			free(dir->dir_path);
			free(dir);
			dir = dir->next;
		}
		free_list(dir);
	}
	free_list(files);
}

void	list_them(t_files *list)
{
	t_files *head;

	head = list;
	while (head != NULL)
	{
		show_permissions(head);
		show_stats(head);
		ft_putchar(' ');
		ft_putendl(head->file_name);
		head = head->next;
		list = head;
	}
}