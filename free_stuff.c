#include "ft_ls.h"

void	free_list(t_files *list)
{
	t_files		*head;

	head = list;
	while (head != NULL)
	{
		free(head->file_name);
		free(head->dir_path);
		head = head->next;
		free(list);
		list = head;
	}
}