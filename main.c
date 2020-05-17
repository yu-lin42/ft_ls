#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_files	*ls;
	t_files	*files;
	char	*flags;

	if (ac == 1)
	{
		ls = no_flags(".");
		print_list(&ls);
	}
	else
	{
		flags = get_flags(ac, av);
		files = get_files(ac, av);
		if (flags != NULL && files == NULL)
		{
			ls_structure(flags);
		}
		else if (files != NULL && flags == NULL)
		{
			show_files(files);
		}
		else
		{
			multi(flags, files);
		}
		free(flags);
	}
	// sleep(40);
	return (0);
}