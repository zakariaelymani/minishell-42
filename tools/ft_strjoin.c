/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:58:50 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/15 16:35:15 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static char	*copin(char *str, const char *s1, const char *s2)
{
	size_t	i;
	size_t	in;

	in = 0;
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[in])
	{
		str[i] = s2[in];
		in++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{

	char	*str;
	size_t	len;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + len2 + 1));
	if (!str)
		return (NULL);
	str = copin(str, s1, s2);
	return (str);
}
