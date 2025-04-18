/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:15:19 by zel-yama          #+#    #+#             */
/*   Updated: 2024/11/07 11:41:03 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_str(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == tofind[j] && i + j < len)
		{
			if (str[i + j] == '\0' && tofind[j] == '\0')
				return (((char *)str) + i);
			j++;
		}
		if (tofind[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *strin, const char *tofind, size_t len)
{
	if (!strin && !tofind)
		return (0);
	if (tofind[0] == '\0' || strin == tofind)
		return ((char *)strin);
	return (str_str(strin, tofind, len));
}
