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
		files = dot_or_not(flags, dir->dir_path);
		sort_display(files, flags);
	}
	else
	{
		if (files != NULL && dir == NULL)
			sort_display(files, flags);
		if (files != NULL && dir != NULL)
		{
			sort_display(files, flags);
			ft_putchar('\n');
		}
		if (dir != NULL)
		{
			while (dir != NULL)
			{
				ft_putstr(dir->dir_path);
				ft_putendl(":");
				files = dot_or_not(flags, dir->dir_path);
				sort_display(files, flags);
				if (dir->next != NULL)
					ft_putchar('\n');
				dir = dir->next;
			}	
		}
	}
	free_list(files);
	free_list(dir);
}