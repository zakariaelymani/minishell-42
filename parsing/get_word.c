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

char *get_word(const char *pos)
{
	char *result;
	size_t i;
	int		q;

	i = 0;
	q = 0;
	if (*pos == '\'' || *pos == '\"')
	{
		q++;
		while (pos[++i] && pos[i] != *pos)
			;
	}
	else
		while (pos[i] && !ft_strchr("<>| ", pos[i]))
			i++;
	result = malloc(i + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, pos + q, i + 1 - q);
	result[i] = '\x1F';
	result[i + 1] = '\0';
	return (result);
}
