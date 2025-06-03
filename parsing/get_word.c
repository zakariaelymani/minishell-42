/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:34:38 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/25 19:34:40 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char *get_word(char *pos)
{
	char	*result;
	size_t	i;
	char	mark;

	i = 0;
	while (pos[i] && !ft_strchr("<>| ", pos[i]))
	{
		if ((pos[i] == '\'' || pos[i] == '\"'))
		{
			mark = pos[i++];
			while (pos[i] && pos[i] != mark)
				i++;
			if (pos[i] == '\0')
			{
				ft_putstr_fd("Syntax Error : Unmatched quote\n", 2);
				return (NULL);
			}
		}
		i++;
	}
	result = malloc(i + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (*pos && !ft_strchr("<>| ", *pos))
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
	result[i] = '\x1F';
	result[i + 1] = '\0';
	return (result);
}
