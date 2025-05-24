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

typedef enum e_qtype{
	DOUBLE = 1,
	SINGLE = 2,
}

void	*expand(void *tok)
{
	t_token *token;
	t_token	*expanded;
	size_t	i;
	int		mode;
	char	*pos;

	i = 0;
	mode = DOUBLE;
	pos = token->content;
	token = (t_token *)tok;
	while (*pos)
	{
		if (*pos == '\'')
			mode = (mode % 2) + 1;
		if (*pos == '$' && mode == DOUBLE)
			get_content_size(&i, env);
		i++;
		pos++;
	}
	expanded->content = malloc(i + 1);
	if (!pos)
		exit(1);
	while (i)
	{
		if (*token->content == '$')
		{
			skip();
			copy_from_env();
		}
		else
			*expanded->content++ == *token->content++;
		i--;
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
