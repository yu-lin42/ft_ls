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
	t_files		*tmp;

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
	if (files != NULL)
		sort_sequence(files, flags);
	if (ft_strchr(flags, 'l'))
		list_them(files);
	else
		print_list(&files);
	while (dir_path != NULL)
	{
		ft_putchar('\n');
		ft_putstr(dir_path->file_name);
		ft_putstr(":\n");
		recursive(dir_path->file_name, flags);
		free(dir_path->file_name);
		tmp = dir_path;
		dir_path = dir_path->next;
		free(tmp);
	}
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
	if (files != NULL)
		sort_sequence(files, flags);
	if (ft_strchr(flags, 'l'))
		list_them(files);
	else
		print_list(&files);
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