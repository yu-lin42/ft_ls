#include "ft_ls.h"

void flags_n_files(char *flags, t_files *list)
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
		if (ft_strchr(flags, 'a'))
			files = hidden(dir->dir_path);
		else
			files = basic(dir->dir_path);
		sort_sequence(files, flags);
		print_n_free(&files);
	}
	else
	{
		sort_sequence(files, flags);
		print_n_free(&files);
		if (dir != NULL)
		{
			ft_putchar('\n');
			while (dir != NULL)
			{
				ft_putstr(dir->dir_path);
				ft_putendl(":");
				if (ft_strchr(flags, 'a'))
					files = hidden(dir->dir_path);
				else
					files = basic(dir->dir_path);
				sort_sequence(files, flags);
				print_n_free(&files);
				// free(dir->dir_path);
				dir = dir->next;
			}	
		}
	}
	// free_list(dir);
}