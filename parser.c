#include "ft_ls.h"

t_files		*basic(char *path)
{
	t_helpers	curr;
	t_files		*base;

	base = NULL;
	curr.mydir = opendir(path);
	while ((curr.mydirent = readdir(curr.mydir)))
	{
		if ((curr.mydirent)->d_name[0] != '.')
			base = dynamic_file(path, (curr.mydirent)->d_name, base);
	}
	closedir(curr.mydir);
	return (base);
}

t_files		*hidden(char *path)
{
	t_helpers	curr;
	t_files		*aye;

	aye = NULL;
	curr.mydir = opendir(path);
	while ((curr.mydirent = readdir(curr.mydir)))
			aye = dynamic_file(path, (curr.mydirent)->d_name, aye);
	closedir(curr.mydir);
	return (aye);
}

t_files		*dot_or_not(char *flags, char *path)
{
	t_files		*files;

	files = NULL;
	if (ft_strchr(flags, 'a'))
		files = hidden(path);
	else
		files = basic(path);
	return (files);
}

char	*get_flags(int ac, char **flags_or_files)
{
	char	*flags;
	int		i;
	int		j;
	int		f;

	flags = ft_strnew(1);
	i = 0;
	f = 0;
	while (++i < ac)
	{
		if (flags_or_files[i][0] == '-')
		{
			j = 1;
			while (flags_or_files[i][j] != '\0')
			{
				if(check_flags(flags_or_files[i][j]))
				{
					free(flags);
					return (0);
				}
				else
					flags[f++] = flags_or_files[i][j++];
			}
		}
	}
	flags[f] = '\0';
	if (flags[0] == '\0')
	{
		free(flags);
		return (NULL);
	}
	return (flags);
}

t_files		*get_files(int ac, char **flags_or_files)
{
	t_files	*files;
	t_files *valid;
	int		i;

	files = NULL;
	valid = NULL;
	i = 1;
	while (i < ac)
	{
		if (flags_or_files[i][0] != '-')
			files = dynamic_file(".", flags_or_files[i], files);
		i++;
	}
	valid = check_files(".", files);

	if (valid != NULL)
		return (valid);
	return (NULL);
}