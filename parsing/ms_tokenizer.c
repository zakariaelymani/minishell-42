/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:02:39 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/14 13:56:39 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_local.h"

static t_type	get_tok_type(char *pos)
{
	if (*pos == '<')
	{
		if (*(pos + 1) && *(pos + 1) == *pos)
			type = HEREDOC;
		else
			type = INPUT;
	}
	else if (*pos == '>')
		if (*(pos + 1) && *(pos + 1) == *pos)
			type = APPEND;
		else
			type = OUTPUT;
	else
		type = PIPE;
	return (type);
}

char	*get_word(const char *pos)
{
	char	*result;
	int		i;

	i = 0;
	while (pos[i] && pos[i] != ' ')
		i++;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, pos, i);
	return (result);
}

int	add_op_token(t_token *tokenlist, char *pos)
{
	t_tok	token;
	char	*content;
	t_type	type;

	type = get_tok_type(pos);
	if (type == APPEND || type == HEREDOC)
		content = ft_substr(pos, 0, 2);
	else
		content = ft_substr(pos, 0, 1);
	token = ft_newtoken(type, content);
	ft_lstadd_back(tokenlist, token);
	return (0);
}

t_token *ms_tokenizer(char *line)
{
	t_token	*tokenlist;
	int		i;
	char	*cont;

	i = -1;
	while (line[++i])
	{
		if (ft_isalpha(line[i]))
		{
			cont = get_word(&line[i]);
			ms_lstadd_back(tokenlist, ms_newtoken(WORD, cont));
		}
		else if (ft_strchr("<>|", line[i]))
			add_operation_token(tokenlist, &line[i]);
		else if (ft_strchr("\'\"", line[i]))
		{
			cont = extract(&line[i]);
			ms_lstadd_back(tokenlist, ms_newtoken(WORD, cont));
		}
		else
			continue ;
	}
	return (tokenlist);
}
