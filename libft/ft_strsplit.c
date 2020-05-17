/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:26:05 by yu-lin            #+#    #+#             */
/*   Updated: 2019/06/22 01:23:04 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		nb;
	int		count;

	i = 0;
	count = 0;
	if (!(s) || !(arr = (char**)ft_memalloc(sizeof(char *) *
					(ft_countwords(s, c) + 1))))
		return (NULL);
	nb = 0;
	while (i < ft_countwords(s, c))
	{
		count += nb;
		while (s[count] == c)
			count++;
		nb = ft_wordlen(s + count, c);
		arr[i] = ft_strsub(s, count, nb);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
