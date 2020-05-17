/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:11:04 by yu-lin            #+#    #+#             */
/*   Updated: 2019/09/09 13:11:31 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **arraypush(char **array, char *str)
{
	char    **new;
	size_t  i;

	i = 0;
	if (array == NULL)
	{
		new = (char**)malloc(sizeof(char*) * 2);
		new[0] = ft_strdup(str);
		new[1] = NULL;
	}
	else
	{
		new = (char**)malloc(sizeof(char*) * (arraylen(array) + 2));
		while (array[i])
		{
			new[i] = ft_strdup(array[i]);
			i++;
		}
		new[i] = ft_strdup(str);
		new[++i] = NULL;
		free2d(array);
	}
	return (new);
}

size_t      arraylen(char **array)
{
	size_t len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

void    free2d(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
