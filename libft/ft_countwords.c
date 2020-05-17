/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:44:09 by yu-lin            #+#    #+#             */
/*   Updated: 2019/06/20 16:10:37 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *str, char c)
{
	int	i;
	int	nbrwords;

	i = 0;
	nbrwords = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] == '\0')
			return (nbrwords++);
		nbrwords++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (nbrwords);
}
