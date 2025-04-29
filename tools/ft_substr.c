/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:51:02 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/28 11:46:17 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	hgm;
	char	*sr;

	if (!s)
		return (0);
	hgm = ft_strlen(s);
	if (start >= hgm)
	{
		sr = (char *)malloc(1);
		if (!sr)
			return (NULL);
		sr[0] = '\0';
		return (sr);
	}
	if (len > hgm - start)
		len = hgm - start;
	sr = (char *)malloc(sizeof(char) * (len + 1));
	if (!sr)
		return (NULL);
	ft_strlcpy(sr, s + start, len + 1);
	return (sr);
}
