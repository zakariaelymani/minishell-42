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

static void	inject_split(char *s)
{
	while (*++s)
		if (*s == '\x1D')
			*s = '\x1F';
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
			while (*++close != '\x1F')
				if (*close == '\x1D')
					*close = ' ';
		}
		inject_split(s);
	}
	else
	{
		*close = '\x1F';
		inject_split(s);
	}
}
