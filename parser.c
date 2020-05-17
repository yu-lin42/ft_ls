#include "ft_ls.h"

t_files		*no_flags(char *path)
{
	t_helpers	current;
	t_files		*basic;

	basic = NULL;
	current.mydir = opendir(path);
	while ((current.mydirent = readdir(current.mydir)))
	{
		if ((current.mydirent)->d_name[0] != '.')
			basic = dynamic_file((current.mydirent)->d_name, basic);
	}
	sort_files(basic);
	closedir(current.mydir);
	return (basic);
}

char	*get_flags(int ac, char **flags_or_files)
{
	char	*flags;
	int		i;
	int		j;
	int		f;

	flags = (char *)malloc(sizeof(char)*1);
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
					return (0);
				else
					flags[f++] = flags_or_files[i][j++];
			}
		}
	}
	flags[f] = '\0';
	if (flags[0] == '\0')
		return (NULL);
	return (flags);
}

t_files		*get_files(int ac, char **flags_or_files)
{
	t_files	*files;
	int		i;

	files = NULL;
	i = 1;
	while (i < ac)
	{
		if (flags_or_files[i][0] != '-')
			files = dynamic_file(flags_or_files[i], files);
		i++;
	}
	if (files != NULL)
	{
		sort_files(files);
		return (files);
	}
	return (NULL);
}