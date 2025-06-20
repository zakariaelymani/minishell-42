/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:49:54 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/14 18:52:29 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void split_keyvalue(char *eq)
{
	char *p1;
	int  both;

	both = 0;
	p1 = eq;
	while (*p1 && *p1 != '\x1F')
		if (*--p1 == '\x1D' || *p1 == '\x1E')
			both++;
	if (both > 0)
	{
		while(*++p1 && *p1 != '\x1F')
			if (*p1 == '\x1D' || *p1 == '\x1E')
				*p1 = '\x1F';
	}
	else
	{
		while (*++eq && *eq != '\x1F')
			if (*eq == '\x1D')
				*eq = ' ';
			else if (*eq == '\x1E')
				*eq ='\t';
	}
}

void	split_manager(char *s)
{
	char	*close;

	close = ft_strchr(s + 1, '\x1F');
	if (!close)
		return ;
	*close = '\0';
	if (ft_strnstr(s, "export", ft_strlen(s)))
	{
		*close = '\x1F';
		while (1)
		{
			close = ft_strchr(close, '=');
			if (!close)
				break ;
			split_keyvalue(close);
			close++;
		}
	}
	else
		*close = '\x1F';
}
