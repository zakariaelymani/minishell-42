/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:02:39 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/16 00:50:53 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// static char	*extract_quoted(const char *pos)
// {
// 	size_t	i;
// 	char	*result;
//
// 	pos += 1;
// 	i = 0;
// 	while (pos[i] && pos[i] != ' ')
// 		i++;
// 	if (pos[i] && pos[i] == ' ' && pos[i - 1] != *pos)
// 		return (NULL);
// 	result = malloc(i);
// 	if (!result)
// 		return (NULL);
// 	ft_strlcpy(result, pos, i);
// 	result[i++] = '\x1F';
// 	result[i] = '\0';
// 	return (result);
// }

static t_type	get_tok_type(char *pos)
{
	t_type	type;

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

static char	*get_word(const char *pos)
{
	char	*result;
	size_t	i;

	i = 0;
	while (pos[i] && !ft_strchr("<>| ", pos[i]))
		i++;
	result = malloc(i + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, pos, i + 1);
	result[i] = '\x1F';
	result[i + 1] = '\0';
	return (result);
}


static t_token *get_optoken(char *line, int *i)
{
	t_token	*token;
	char	*content;
	t_type	type;
	
	type = get_tok_type(line + *i);
	if (type == APPEND || type == HEREDOC)
		content = ft_substr(line + *i, 0, 2);
	else
		content = ft_substr(line + *i, 0, 1);
	token = ms_toknew(content, type);
	if (!content || !token)
		exit(1);
	if (type & (APPEND || HEREDOC))
		*i += 2;
	else
		(*i)++;
	return (token);
}

t_token	*get_wtoken(char *line, int *i)
{
	char	*content;
	t_token	*new;

	content = get_word(line + *i);
	new = ms_toknew(content, WORD);
	if (!content || !new)
		exit(1);
	while (line[*i] && !ft_strchr("<>|\'\" ", line[*i]))
		(*i)++;
	return (new);
}

t_token *ms_tokenizer(char *line)
{
	t_token	*tokenlist;
	int		i;

	tokenlist = NULL;
	i = 0;
	while (1)
	{
		if (!line[i])
			break ;
		if (line[i] && !ft_strchr("|<>\'\" ", line[i]))
			ms_tokappend(&tokenlist, get_wtoken(line, &i));
		if (line[i] && ft_strchr("<>", line[i]))
			ms_tokappend(&tokenlist, get_optoken(line, &i));
		if (line[i] && line[i] == '|')
			ms_tokappend(&tokenlist, get_optoken(line, &i));
		if (isspace(line[i]))
			i++;
	}
	return (tokenlist);
}
