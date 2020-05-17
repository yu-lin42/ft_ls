/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-lin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:59:37 by yu-lin            #+#    #+#             */
/*   Updated: 2019/06/22 01:19:40 by yu-lin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char			*new;
	unsigned long	end;
	unsigned long	start;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	start = 0;
	while (s[start] != '\0' && (s[start] == ' ' || s[start] == '\n'
				|| s[start] == '\t'))
		start++;
	while (start < end && (s[end - 1] == ' ' || s[end - 1] == '\n'
				|| s[end - 1] == '\t'))
		end--;
	new = ft_strsub(s, start, (end - start));
	return ((char *)new);
}
