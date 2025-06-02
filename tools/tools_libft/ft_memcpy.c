/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:42:29 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/24 16:05:00 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*str;
	const char	*sc;

	sc = src;
	str = dst;
	i = 0;
	if (!sc && !str)
		return (NULL);
	while (i < n)
	{
		str[i] = sc[i];
		i++;
	}
	return ((void *)str);
}
