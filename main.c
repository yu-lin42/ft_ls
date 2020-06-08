/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:51:26 by yu-lin            #+#    #+#             */
/*   Updated: 2020/06/01 23:35:17 by yu-lin           ###   ########.fr       */
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
			just_flags(flags);
		else if (files != NULL && flags == NULL)
			just_files(files);
		else if (files != NULL && flags != NULL)
			flags_n_files(flags, files);
		free(flags);
	}
	// sleep(40);
	return (0);
}