/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:52:00 by yu-lin            #+#    #+#             */
/*   Updated: 2020/06/01 21:29:47 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_files		*check_files(char *path, t_files *files)
{
	struct stat		buf;
    t_files			*valid;
	t_files			*tmp;

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
			valid = dynamic_file(path, files->file_name, valid);
		free(files->file_name);
		free(files->dir_path);
		tmp = files;
		files = files->next;
		free(tmp);
	}
    return (valid);
}

int		is_dir(char *path)
{
	t_helpers	check;
	
	if ((check.mydir = opendir(path)) != NULL)
	{
		while ((check.mydirent = readdir(check.mydir)))
		{
			if ((check.mydirent)->d_type == DT_DIR)
			{
				closedir(check.mydir);
				return (1);
			}
		}
		closedir(check.mydir);	
	}
	return (0);
}