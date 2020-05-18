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

void	show_files(t_files *list)
{
	t_files		*valid;

	valid = check_files(list);
	sort_files(valid);
	print_list(&valid);
}

void	show_modes(t_files *list)
{
	struct stat	info;
	char		chmod[12];

	lstat(list->file_name, &info);
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
	chmod[10] = '-';
    chmod[11] = '\0';
	ft_putendt(chmod);
}

void	show_stats(t_files *list)
{
	t_helpers		curr;
	struct stat info;
	struct passwd	*usr;
	struct group	*grp;

	lstat(list->file_name, &info);
	ft_putnbr(info.st_nlink);
	ft_putchar('\t');
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