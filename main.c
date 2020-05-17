#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_files *ls;
	t_files *files;
	t_files *val_files;
	char *flags;

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
			// ft_putendl("Just files");
			val_files = check_files(files);
			sort_files(val_files);
			print_list(&val_files);
		}
		else{
			// check_files(files); //Not working with opendir()
			ft_putendl("Flags and files");
		}
		free(flags);
	}
	// sleep(40);
	return (0);
}