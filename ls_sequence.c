#include "ft_ls.h"

void	just_flags(char *flags)
{
	t_files *files;

	files = NULL;
	if (ft_strchr(flags, 'R'))
	{
		if (ft_strchr(flags, 'a'))
			files = hidden(".");
		else
			files = basic(".");
		recursive(flags, files, ".");
	}
	else
	{
		if (ft_strchr(flags, 'a'))
			files = hidden(".");
		else
			files = basic(".");
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
	sort_sequence(files, flags);
	if (ft_strchr(flags, 'l'))
	{
		total_blocks(files);
		list_them(files);
	}
	else
		print_n_free(&files);
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
			if (ft_strchr(flags, 'a'))
				files = hidden(dir->dir_path);
			else
				files = basic(dir->dir_path);
			recursive(flags, files, dir->dir_path);
			free(dir->dir_path);
			free_list(files);
			dir = dir->next;
		}
	}
	free_list(dir);
}


void	non_recursive(char *flags, t_files *list)
{
	sort_sequence(list, flags);
	if (ft_strchr(flags, 'l'))
	{
		total_blocks(list);
		list_them(list);
	}
	else
		print_n_free(&list);
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
		print_n_free(&files);
	}
	else
	{
		if (files != NULL && dir == NULL)
		{
			sort_files(files);
			print_n_free(&files);
		}
		if (files != NULL && dir != NULL)
		{
			sort_files(files);
			print_n_free(&files);
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
				print_n_free(&files);
				if (dir->next != NULL)
					ft_putchar('\n');
				free(dir->dir_path);
				dir = dir->next;
			}
		}
	}
	free_list(dir);
}

void	list_them(t_files *list)
{
	// total_blocks(list);
	while (list != NULL)
	{
		show_permissions(list);
		show_stats(list);
		ft_putchar(' ');
		ft_putendl(list->file_name);
		free(list->file_name);
		list = list->next;
	}
}