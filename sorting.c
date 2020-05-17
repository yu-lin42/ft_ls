#include "ft_ls.h"

void	sort_sequence(t_files *files, char *flags)
{
	if (ft_strchr(flags, 'r') && (ft_strchr(flags, 't')))
			sort_in_reverse_time(files);
		else if (ft_strchr(flags, 'r'))
			sort_in_reverse(files);
		else if (ft_strchr(flags, 't'))
			sort_in_time(files);
		else
			sort_files(files);
}

void	sort_files(t_files *list)
{
	t_files	*head;
	char	*store;

	head = list;
	while (list->next)
	{
		if (list->file_name == NULL)
			list = list->next;
		if (ft_strcmp(list->file_name, list->next->file_name) > 0)
		{
			store = list->file_name;
			list->file_name = list->next->file_name;
			list->next->file_name = store;
			list = head;
		}
		else
			list = list->next;
	}
	list->next = NULL;
	list = head;
}

void	sort_in_reverse_time(t_files *list)
{
	char		*store;
	t_files		*tmp;
	struct stat	info1;
	struct stat	info2;

	tmp = list;
	while (list->next)
	{
		lstat(list->file_name, &info1);
		lstat(list->next->file_name, &info2);
		if (info2.st_mtime < info1.st_mtime)
		{
			store = list->file_name;
			list->file_name = list->next->file_name;
			list->next->file_name = store;
			list = tmp;
		}
		else
			list = list->next;
	}
	list->next = NULL;
	list = tmp;
}

void	sort_in_reverse(t_files *list)
{
	char	*store;
	t_files	*tmp;
	
	tmp = list;
	while (list->next)
	{
		if ((strcmp(list->next->file_name, list->file_name)) > 0)
		{
			store = list->file_name;
			list->file_name = list->next->file_name;
			list->next->file_name = store;
			list = tmp;
		}
		else
			list = list->next;
	}
	list->next = NULL;
	list = tmp;
}

void	sort_in_time(t_files *list)
{
	char		*store;
	t_files		*tmp;
	struct stat	info1;
	struct stat	info2;

	tmp = list;
	while (list->next)
		{
			lstat(list->file_name, &info1);
			lstat(list->next->file_name, &info2);
			if (info2.st_mtime > info1.st_mtime)
			{
				store = list->file_name;
				list->file_name = list->next->file_name;
				list->next->file_name = store;
				list = tmp;
			}
			else
				list = list->next;
		}
	list->next = NULL;
	list = tmp;
}