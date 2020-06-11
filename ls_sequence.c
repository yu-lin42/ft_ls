#include "ft_ls.h"

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
	dir = NULL;
	while (list != NULL)
	{
		if (is_dir(list->dir_path))
			dir = dynamic_file(path, list->file_name, dir);
		files = dynamic_file(path, list->file_name, files);
		list = list->next;
	}
	sort_display(files, flags);
	if (dir != NULL)
		sort_sequence(dir, flags);
	while (dir != NULL)
	{
		if (dir->file_name[0] == '.')
			dir = dir->next;
		else
		{
			ft_putchar('\n');
			ft_putstr(dir->file_name);
			ft_putendl(": ");
			files = dot_or_not(flags, dir->dir_path);
			recursive(flags, files, dir->dir_path);
			dir = dir->next;
		}
	}
	free_list(files);
	free_list(dir);
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
		list = list->next;
	}
	if (files == NULL && dir->next == NULL)
	{
		files = basic(dir->dir_path);
		sort_files(files);
		print_list(files);
	}
	else
	{
		if (files != NULL && dir == NULL)
		{
			sort_files(files);
			print_list(files);
		}
		if (files != NULL && dir != NULL)
		{
			sort_files(files);
			print_list(files);
			ft_putchar('\n');
		}
		if (dir != NULL)
		{
			while (dir != NULL)
			{
				ft_putstr(dir->dir_path);
				ft_putendl(":");
				files = basic(dir->dir_path);
				sort_files(files);
				print_list(files);
				if (dir->next != NULL)
					ft_putchar('\n');
				dir = dir->next;
			}
		}
	}
	free_list(files);
	free_list(dir);
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