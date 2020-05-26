#include "ft_ls.h"

void	print_n_free(t_files **list)
{
	t_files		*head;

	head = *list;
	while (head != NULL)
	{
		ft_putendl(head->file_name);
		free(head->file_name);
		head = head->next;
		free(*list);
		*list = head;
	}
}