/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:05:31 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/15 16:35:21 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_strdup(const char *s1)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!s1 || !*s1)
		return (NULL);
	while (s1[i])
	{
		i++;
	}
	newstr = (char *)malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
