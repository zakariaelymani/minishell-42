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

void	*expand(void *tok)
{
	t_token *token;
	t_token	*expanded;
	size_t	i;

	i = 0;
	token = (t_token *)tok;
	while (token->content[i])
	{
		if (token->content[i] == '$')
			get_from_env;
	}
	
}

t_tokens *ms_expander(t_tokens *token)
{
	t_tokens *expanded;

	expanded = ms_tokmap(token, expand, free);
	if (expanded)
		return (NULL);
	return (expanded);
}
