/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:10:34 by abenkaro          #+#    #+#             */
/*   Updated: 2025/05/14 18:34:08 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_local.h"

t_redir	*new_redir(t_type type)
{
	t_redir	*result;
	result = (t_redir *)malloc(sizeof(t_redir));
	if (!result)
		return (NULL);
	result->file_name = NULL;
	result->type = type;
	result->fd = -1;
	return (result);
}

int	add_cmd(t_cmds **chain, char **cmdstr, t_redir **redir)
{
	t_cmds	*cmd;

	cmd = ms_newcmd();
	if (!cmd)
		return (1);
	cmd->cmds = ft_split(*cmdstr, ' ');
	if (!cmd->cmds)
		return (1);
	cmd->redirection = *redir;
	free(*cmdstr);
	*cmdstr = NULL;
	ms_appendcmd(chain, cmd);
	*redir = NULL;
	return (0);
}

t_cmds	*cmd_parser(t_token *tokens)
{
	t_cmds	*cmd_chain;
	t_redir	*redir;
	char	*cmdstr;

	cmd_chain = NULL;
	cmdstr = "";
	while (tokens)
	{
		if (tokens->type == WORD)
			cmdstr = ft_strjoin(cmdstr, tokens->content);
		if (tokens->type & (OUTPUT | INPUT | APPEND | HEREDOC))
		{
			redir = new_redir(tokens->type);
			tokens = tokens->next;
			redir->file_name = ft_substr(tokens->content, 0, ft_strlen(tokens->content) - 1);
		}
		tokens = tokens->next;
		if (!tokens || tokens->type == PIPE)
			add_cmd(&cmd_chain, &cmdstr, &redir);
	}
	return (cmd_chain);
}
