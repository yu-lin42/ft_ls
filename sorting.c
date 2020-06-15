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

void swap(t_files *first, t_files *second)
{
	t_files *tmp;
	tmp = first;
	first = second;
	second = tmp;
}

void	sort_files(t_files *list)
{
	t_files	*head;
	char	*store_name;
	char	*store_path;

	head = list;
	while (list->next)
	{
		if (list->file_name == NULL)
			list = list->next;
		if (ft_strcmp(list->file_name, list->next->file_name) > 0)
		{
			store_name = list->file_name;
			list->file_name = list->next->file_name;
			list->next->file_name = store_name;
			store_path = list->dir_path;
			list->dir_path= list->next->dir_path;
			list->next->dir_path = store_path;
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
	char		*store_name;
	char		*store_path;
	t_files		*tmp;
	struct stat	info1;
	struct stat	info2;

	tmp = list;
	while (list->next)
	{
		lstat(list->dir_path, &info1);
		lstat(list->next->dir_path, &info2);
		if (info2.st_mtime < info1.st_mtime)
		{
			store_name = list->file_name;
			list->file_name = list->next->file_name;
			list->next->file_name = store_name;
			store_path = list->dir_path;
			list->dir_path= list->next->dir_path;
			list->next->dir_path = store_path;
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
	char	*store_name;
	char	*store_path;
	t_files	*tmp;
	
	tmp = list;
	while (list->next)
	{
		if ((strcmp(list->next->file_name, list->file_name)) > 0)
		{
			store_name = list->file_name;
			list->file_name = list->next->file_name;
			list->next->file_name = store_name;
			store_path = list->dir_path;
			list->dir_path= list->next->dir_path;
			list->next->dir_path = store_path;
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
	char		*store_name;
	char		*store_path;
	t_files		*tmp;
	struct stat	info1;
	struct stat	info2;

	tmp = list;
	while (list->next)
		{
			lstat(list->dir_path, &info1);
			lstat(list->next->dir_path, &info2);
			if (info1.st_mtime < info2.st_mtime)
			{
				store_name = list->file_name;
				list->file_name = list->next->file_name;
				list->next->file_name = store_name;
				store_path = list->dir_path;
				list->dir_path= list->next->dir_path;
				list->next->dir_path = store_path;
				list = tmp;
			}
			else
				list = list->next;
		}
	list->next = NULL;
	list = tmp;
}