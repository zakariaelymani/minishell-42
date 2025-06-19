/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:43:59 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/14 16:44:01 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	unquoted_size(char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str == '\"')
		{
			while (*str && *++str != '\"')
				len++;
			str += 1;
		}
		else if (*str == '\'')
		{
			while (*++str != '\'')
				len++;
			str += 1;
		}
		else
		{
			str += 1;
			len++;
		}
	}
	return (len);
}

static void	copy_unquoted(char *dest, char *str)
{
	while (*str)
	{
		if (*str == '\"')
		{
			while (*str && *++str != '\"')
					*dest++ = *str;
			str += 1;
		}
		else if (*str == '\'')
		{
			while (*++str != '\'')
				*dest++ = *str;
			str += 1;
		}
		else
			*dest++ = *str++;
	}
	*dest = *str;
}

void finalize(char *str)
{
	int sq;
	int dq;

	dq = '"' * -1;
	sq = '\'' * -1;
	while (*str)
	{
		if (*str == sq || *str == dq)
			*str *= -1;
		str++;
	}
}

int	remove_quotes(char **str)
{
	size_t	len;
	char	*unquoted;

	len = 0;
	if (ft_strchr(*str, '"') || ft_strchr(*str, '\''))
	{
		if (!ft_strncmp(*str, "\"\"", 3)
			|| !ft_strncmp(*str, "''", 3))
		{
			free(*str);
			*str = ft_strdup("");
			return (0);
		}
		len = unquoted_size(*str);
		unquoted = ft_malloc(len + 1);
		if (!unquoted)
			return (-1);
		copy_unquoted(unquoted, *str);
		free(*str);
		*str = unquoted;
	}
	finalize(*str);
	return (0);
}

int	heredoc_quotes(char **str)
{
	size_t	len;
	char	*unquoted;

	len = 0;
	if (ft_strchr(*str, '"') || ft_strchr(*str, '\''))
	{
		if (!ft_strncmp(*str, "\"\"", 3)
			|| !ft_strncmp(*str, "''", 3))
		{
			free(*str);
			*str = ft_strdup("");
			return (0);
		}
		len = unquoted_size(*str);
		unquoted = ft_malloc(len + 1);
		if (!unquoted)
			return (-1);
		copy_unquoted(unquoted, *str);
		free(*str);
		*str = unquoted;
		*ft_strrchr(*str, '\x1F') = '\x1E';
	}
	return (0);
}
