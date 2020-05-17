#include "ft_ls.h"

void	multi(char *flags, t_files *files)
{
	t_files		*valid;
	
	valid = check_files(files);
	if (valid != NULL)
		sort_sequence(valid, flags);
	if (ft_strchr(flags, 'l'))
		list_them(valid);
	else
		print_list(&valid);
}