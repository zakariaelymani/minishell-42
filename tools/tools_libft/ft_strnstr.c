/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:22:50 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:47:31 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (needle[0] == '\0')
		return ((char *)hay);
	needle_len = ft_strlen(needle);
	i = 0;
	while (hay[i] != '\0' && i < len)
	{
		if (hay[i] == needle[0] && i + needle_len <= len)
			if (ft_strncmp(needle, &hay[i], needle_len) == 0)
				return ((char *)&hay[i]);
		i++;
	}
	return (NULL);
}
