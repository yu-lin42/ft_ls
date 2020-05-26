/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:51:26 by yu-lin            #+#    #+#             */
/*   Updated: 2020/05/27 00:02:12 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_files	*ls;
	t_files	*files;
	char	*flags;

	if (ac == 1)
	{
		ls = basic(".");
		sort_files(ls);
		print_n_free(&ls);
	}
	else
	{
		flags = get_flags(ac, av);
		files = get_files(ac, av);
		if (flags != NULL && files == NULL)
			// ft_putendl("Just flags");
			just_flags(flags);
		else if (files != NULL && flags == NULL)
		{
			just_files(files);
			//print_n_free(&files);
		}
		else
			ft_putendl("Flags with files/directories");
		free(flags);
	}
	// sleep(40);
	return (0);
}