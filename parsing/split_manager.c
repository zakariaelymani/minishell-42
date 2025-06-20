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

// static void	inject_split(char *s)
// {
// 	while (*++s)
// 		if (*s == '\x1D')
// 			*s = '\x1F';
// }

void split_keyvalue(char *eq)
{
	int both;
	char *p1;
	char *p2;

	p1 = eq;
	p2 = p1;
	both = 0;
	while (*p1 && *p1 != '\x1F')
		if (*--p1 == '\x1D')
			both++;
	while (*p2 && *p2!= '\x1F')
		if (*++p2== '\x1D')
			both++;
	if (both > 1)
	{
		while (*p1 && *p1 != '=')
		{
			if (*p1 == '\x1D')
				*p1 = '\x1F';
			p1++;
		}
		while (*p2 && *p2 != '=')
		{
			if (*p2 == '\x1D')
				*p2 = '\x1F';
			p2--;
		}
	}
	else
		while (*++eq && *eq != '\x1F')
			if (*eq == '\x1D')
				*eq = ' ';
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
		}
		// inject_split(s);
	}
	else
	{
		*close = '\x1F';
		// inject_split(s);
	}
}
