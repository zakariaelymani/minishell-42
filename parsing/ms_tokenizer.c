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

static t_type get_tok_type(char *pos) {
  t_type type;

  if (*pos == '<') {
    if (*(pos + 1) && *(pos + 1) == *pos)
      type = HEREDOC;
    else
      type = INPUT;
  } else if (*pos == '>')
    if (*(pos + 1) && *(pos + 1) == *pos)
      type = APPEND;
    else
      type = OUTPUT;
  else
    type = PIPE;
  return (type);
}

static t_token *get_wtoken(char *line, int *i)
{
	char *content;
	t_token *new;
	char	qpair;

	content = get_word(line + *i);
	if (!content)
		return (NULL);
	new = ms_toknew(content, WORD);
	if (!new)
		return (free(content), NULL);
	while (line[*i] && !ft_strchr("<>| ", line[*i]))
	{
		if ((line[*i] == '\'' || line[*i] == '\"'))
		{
			qpair = line[(*i)++];
			while (line[*i] && line[*i] != qpair)
				(*i)++;
		}
		(*i)++;
	}
	return (new);
}

static t_token *get_optoken(char *line, int *i) 
{
  t_token *token;
  char *content;
  t_type type;

  type = get_tok_type(line + *i);
  if (type == APPEND || type == HEREDOC)
    content = ft_substr(line + *i, 0, 2);
  else
    content = ft_substr(line + *i, 0, 1);
  token = ms_toknew(content, type);
  if (!content || !token)
    exit(1);
  if (type == APPEND || type == HEREDOC)
    *i += 2;
  else
    (*i)++;
  return (token);
}

t_token *ms_tokenizer(char *line)
{
  t_token *tokenlist;
  int i;

  tokenlist = NULL;
  i = 0;
  while (1) {
    if (!line[i])
      break;
    while (ft_isspace(line[i]))
      i++;
    if (line[i] && !ft_strchr("<>| ", line[i]))
			if (!ms_tokappend(&tokenlist, get_wtoken(line, &i)))
				return (ms_tokclear(&tokenlist, free), NULL);
    if (line[i] && ft_strchr("<>", line[i]))
			if (!ms_tokappend(&tokenlist, get_optoken(line, &i)))
				return (ms_tokclear(&tokenlist, free), NULL);
    if (line[i] && line[i] == '|')
			if (!ms_tokappend(&tokenlist, get_optoken(line, &i)))
				return (ms_tokclear(&tokenlist, free), NULL);
  }
  return (tokenlist);
}
