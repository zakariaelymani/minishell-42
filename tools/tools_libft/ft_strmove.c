/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:02:00 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/20 20:02:32 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tools.h"

void	ft_strmove(char *str)
{
	size_t	movesize;
	char	*p;

	if (!str)
		return ;
	p = str;
	movesize = 0;
	while (*p && *p == '\x1D')
		p++;
	movesize = p - str;
	if (movesize > 0)
	{
		while (*p && *p != '\x1D')
			*str++ = *p++;
		*str = '\0';
	}
}
