#include "ft_ls.h"

void	multi(char *flags, t_files *files)
{
	t_files		*valid;
	
	valid = check_files(files);
	if (valid != NULL)
		sort_sequence(valid, flags);
	if (ft_strchr(flags, 'l'))
		list_them(valid);
	else
		print_list(&valid);
}

void	repeat(t_files *dir_path, char *flags)
{
	t_files	*tmp;
	
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