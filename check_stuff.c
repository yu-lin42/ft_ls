#include "ft_ls.h"

int		check_flags(char flag)
{
    if (ft_strchr(FLAGS, flag) == NULL)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(flag);
		ft_putchar(10);
		ft_putendl("usage: ft_ls [-Ralrt] [file ..]");
		return (1);
	}
    return (0);
}

t_files		*check_files(t_files *files)
{
	struct stat		buf;
    t_files			*valid;

    valid = NULL;
	while (files != NULL)
	{
		if (stat(files->file_name,&buf))
		{
			ft_putstr(files->file_name);
			ft_putchar(' ');
			ft_putendl("ft_ls: No such file or directory");
		}
		else
			valid = dynamic_file(files->file_name, valid);
		free(files->file_name);
		files = files->next;
	}
    return (valid);
}