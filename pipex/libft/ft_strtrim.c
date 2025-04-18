/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:09:07 by zel-yama          #+#    #+#             */
/*   Updated: 2024/11/07 12:03:33 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	searhisin(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static const char	*strshr(const char *s1, const char *set)
{
	while (s1)
	{
		if (searhisin(s1[0], set) == 1)
			s1++;
		else
			break ;
	}
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	s1 = strshr(s1, set);
	size = ft_strlen(s1);
	while (size > 0 && searhisin(s1[size - 1], set))
	{
		size--;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (size + 1));
	return (str);
}
