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

#include "parsing_local_h"
#include "parsing.h"
#include "minishell.h"

int	add_cmd(t_cmds **chain, char *cmdstr, t_redir_s *redir)
{
	t_cmds	*cmd;

	cmd = ms_newcmd();
	if (!cmd)
		return (1);
	cmd->cmds = ft_split(cmdstr, ' ');
	if (!cmd->cmds)
		return (1);
	cmd->redirction = redir;
	ms_appendcmd(chain, cmd);
	return (0);
}

t_cmds	*cmd_parser(t_token *tokens)
{
	t_cmds	*cmd_chain;
	s_redir	*redir;
	char	*cmdstr;
	t_cmds	cmd;

	cmd_chain = NULL;
	while (token)
	{
		if (token->type == WORD)
			cmdstr = ft_strjoin(token->content);
		if (token->type && (OUTPUT | INPUT | APPEND | HEREDOC))
		{
			redir = ms_newredir();
			redir->type == token->type;
			token = token->next;
			redir->file_name == ft_substr(token->content, 0, ft_strlen(token->content) - 1);
		}
		token = token->next;
		if (token->type == pipe)
		{
			add_cmd(&cmd_chain, cmdstr, &redir);
			token = token->next;
		}
	}
	return (cmd_chain);
}
