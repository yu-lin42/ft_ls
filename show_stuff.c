#include "ft_ls.h"

void	print_n_free(t_files **list)
{
	t_files		*head;

	head = *list;
	while (head != NULL)
	{
		ft_putendl(head->file_name);
		free(head->file_name);
		free(head->dir_path);
		head = head->next;
		free(*list);
		*list = head;
	}
}

void	show_permissions(t_files *list)
{
	struct stat		info;
	char			chmod[12];

	lstat(list->dir_path, &info);
	chmod[0] = (S_ISDIR(info.st_mode)) ? 'd' : '-';
	chmod[1] = (S_IRUSR & info.st_mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & info.st_mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & info.st_mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & info.st_mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & info.st_mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & info.st_mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & info.st_mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & info.st_mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & info.st_mode) ? 'x' : '-';
	chmod[10] = ' ';//no stickybits
	chmod[11] = '\0';
	ft_putstr(chmod);
	ft_putchar(' ');
}

void	show_stats(t_files *list)
{
	t_helpers		curr;
	struct stat		info;
	struct passwd	*usr;
	struct group	*grp;

	lstat(list->dir_path, &info);
	ft_putnbr(info.st_nlink);
	ft_putchar(' ');
	usr = getpwuid(info.st_uid);
	ft_putendt(usr->pw_name);
	grp = getgrgid(info.st_gid);
	ft_putendt(grp->gr_name);
	ft_putnbr(info.st_size);
	ft_putchar('\t');
	curr.buf = ctime(&(info.st_mtime)) + 4;
	curr.tmp = ft_strsub(curr.buf, 0, 12);
	ft_putstr(curr.tmp);
	free(curr.tmp);
}

void	total_blocks(t_files *list)
{
	struct stat	info;
	int	total;
	t_files	*tmp;

	tmp = list;
	total = 0;
	while (tmp != NULL)
	{
		lstat(tmp->dir_path, &info);
		total += info.st_blocks; 
		tmp = tmp->next;
	}
	ft_putstr("total: ");
	ft_putnbr(total);
	ft_putchar('\n');
	free_list(tmp);
}