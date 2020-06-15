#include "ft_ls.h"

void	free_list(t_files *list)
{
	while (list != NULL)
	{
		free(list->file_name);
		free(list->dir_path);
		free(list);
		list = list->next;
	}
}