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

t_cmds	*cmd_parser(t_token *tokens)
{
	t_cmds	*cmd_chain;
	s_redir	redir;
	char	*cmdstr;
	t_cmds	cmd;

	cmd_chain = NULL;
	while (token)
	{
		cmd = ms_newcmd();
		while (token && token->type != PIPE)
		{
			if (token->type == WORD)
				cmdstr = ft_strjoin(token->content);
			if (token->type && (OUTPUT | INPUT | APPEND | HEREDOC))
			{
				redir->type == token->type;
				token = token->next;
				redir->file_name == ft_substr(token->content, 0, ft_strlen(token->content) - 1);
				cmd->redir = redir;
			}
			token = token->next;
		}
		add_cmd(&cmd_chain, cmdstr, redir);
	}
	return (cmd_chain);
}
