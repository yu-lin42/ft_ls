#include "ft_ls.h"

void	ls_structure(char *flags)
{
	if (ft_strchr(flags, 'R'))
	{
		//Only works with -R and -Rr
		recursive(".", flags);
		//ft_putendl("Recursive found");
	}
	else
	{
		no_recursive(".", flags);
		//ft_putendl("No recursive found");
	}
}

void	recursive(char *path, char *flags)
{
	t_helpers current;
	t_files *files;
	t_files *dir_path;

	files = NULL;
	dir_path = NULL;
	current.mydir = opendir(path);
	while ((current.mydirent = readdir(current.mydir)))
	{
		if (!ft_strchr(flags, 'a') && current.mydirent->d_name[0] == '.')
			continue;
		if ((current.mydirent)->d_type == DT_DIR)
		{
			current.tmp = ft_strjoin(path, "/");
			current.tmp = ft_strjoin(current.tmp, ((current.mydirent)->d_name));
			dir_path = dynamic_file(current.tmp, dir_path);
			free(current.tmp);
		}
		files = dynamic_file((current.mydirent)->d_name, files);
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
		dir_path = dir_path->next;
	}
	free(dir_path->file_name);
}

void	no_recursive(char *path, char *flags)
{
	t_helpers current;
	t_files *files;

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
	t_helpers curr;
	struct stat info;
	struct passwd *usr;
	struct group *grp;

	while (list != NULL)
	{
		lstat(list->file_name, &info);
		show_modes(list);
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
		ft_putchar(' ');
		ft_putendl(list->file_name);
		free(curr.buf);
		free(curr.tmp);
		list = list->next;
	}
}

void	show_modes(t_files *list)
{
	struct stat info;
	char chmod[12];

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