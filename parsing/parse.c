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
	t_cmds	*cmd;
	s_redir	*redir;
	char	**cmdstr;

	cmd_chain = NULL;
	redir = NULL;
	while (token)
	{
		if (token->type == WORD)
			cmdstr = get_cmd(&tokens);
		if (token->type && (OUTPUT | INPUT | APPEND | HEREDOC))
		{
			redir->type == token->type;
			token = token->next;
			redir->file_name == ft_strdup(token->content);
		}
		if (token->type == PIPE)
			add_cmd(&cmd_chain, cmd);
		token = token->next;
	}
	return (cmd_chain);
}
