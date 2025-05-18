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


static char	*extract_quoted(const char *pos)
{
	size_t	i;
	char	*result;

	pos += 1;
	i = 0;
	while (pos[i] && pos[i] != ' ')
		i++;
	if (pos[i] && pos[i] == ' ' && pos[i - 1] != *pos)
		return (NULL);
	result = malloc(i);
	if (!result)
		return (NULL);
	ft_strlcpy(result, pos, i);
	result[i++] = '\x1F';
	result[i] = '\0';
	return (result);
}

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


static int	add_op_token(t_token **tokenlist, char *pos)
{
	t_token	*token;
	char	*content;
	t_type	type;

	type = get_tok_type(pos);
	if (type == APPEND || type == HEREDOC)
		content = ft_substr(pos, 0, 2);
	else
		content = ft_substr(pos, 0, 1);
	token = ms_toknew(content, type);
	ms_tokappend(tokenlist, token);
	return (0);
}

t_token *ms_tokenizer(char *line)
{
	t_token	*tokenlist;
	int		i;
	char	*cont;

	i = -1;
	tokenlist = NULL;
	while (line[++i])
	{
		if (!ft_strchr("|<>\'\" ", line[i]))
		{
			cont = get_word(&line[i]);
			ms_tokappend(&tokenlist, ms_toknew(cont, WORD));
			while (line[i] && !ft_strchr("<>|\'\" ", line[i]))
				i++;
			i--;
		}
		else if (ft_strchr("<>|", line[i]))
		{
			add_op_token(&tokenlist, &line[i]);
			while (line[i] && ft_strchr("<>|", line[i]))
				i++;
			i--;
		}
		else if (ft_strchr("\'\"", line[i]))
		{
			cont = extract_quoted(&line[i++]);
			ms_tokappend(&tokenlist, ms_toknew(cont, WORD));
			while (line[i] && !ft_strchr("\'\" ", line[i]))
				i++;
		}
		if (!line[i])
			break ;
	}
	return (tokenlist);
}
