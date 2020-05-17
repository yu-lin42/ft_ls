#include "ft_ls.h"

void	print_list(t_files **stuff)
{
	t_files		*list;

	list = *stuff;
	while (list != NULL)
	{
		ft_putendl(list->file_name);
		free(list->file_name);
		list = list->next;
		free(*stuff);
		*stuff = list;
	}
}

void	show_files(t_files *files)
{
	t_files		*valid;

	valid = check_files(files);
	sort_files(valid);
	print_list(&valid);
}