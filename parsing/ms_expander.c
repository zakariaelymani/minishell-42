/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:30:12 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/24 18:30:14 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	expand_size(t_token *tokens)
{
	size_t	len;
	int		expand;
	char	*str;

	len = 0;
	expand = 1;
	str = tokens->content;
	while (*str)
	{
		if (*str == '\'')
			expand =! expand;
		if (*str == '$' && expand)
		{
			len += varsize(&str, env);
			continue;
		}
		len++;
		str++;
	}
	return (len);
}
