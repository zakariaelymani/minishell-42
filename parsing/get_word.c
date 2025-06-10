/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:34:38 by abenkaro          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:06 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static ssize_t	calculate_size(char *str)
{
	ssize_t	len;
	char	mark;

	len = 0;
	while (str[len] && !ft_strchr("<>|", str[len]) && !ft_isspace(str[len]))
	{
		if ((str[len] == '\'' || str[len] == '\"'))
		{
			mark = str[len++];
			while (str[len] && str[len] != mark)
				len++;
			if (str[len] == '\0')
			{
				ft_putstr_fd("Syntax Error: Unmatched quote\n", 2);
				return (-1);
			}
		}
		len++;
	}
	return (len);
}

char	*get_word(char *pos)
{
	char	*result;
	ssize_t	len;
	size_t	i;
	char	mark;

	len = calculate_size(pos);
	if (len < 0)
		return (NULL);
	result = ft_malloc(len + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (*pos && !ft_strchr("<>|", *pos) && !ft_isspace(*pos))
	{
		if (*pos == '\'' || *pos == '\"')
		{
			mark = *pos;
			result[i++] = *pos++;
			while (*pos && *pos != mark)
				result[i++] = *pos++;
		}
		result[i++] = *pos++;
	}
	ft_memmove(result + i, "\x1F\0", 2);
	return (result);
}
