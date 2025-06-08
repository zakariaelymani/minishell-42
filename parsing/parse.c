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

#include "parsing.h"

static int	add_cmd(t_cmds **chain, char **cmdstr, t_cmds *cmd)
{
	cmd->cmds = ft_split(*cmdstr, '\x1F');
	if (!cmd->cmds)
		return (1);
	free(*cmdstr);
	*cmdstr = NULL;
	ms_cmdappend(chain, cmd);
	return (0);
}

static int	add_redir(t_token **tokens, t_redir **cmdredir)
{
	t_redir	*redir;
	char	*str;

	redir = new_redir((*tokens)->type);
	if ((*tokens)->type == HEREDOC)
	{
		str = (*tokens)->next->content;
		if (!ft_strrchr(str, '\x1E'))
			redir->fd = -2;
	}
	*tokens = (*tokens)->next;
	redir->file_name = ft_substr((*tokens)->content, 0,
			ft_strlen((*tokens)->content) - 1);
	ms_redappend(cmdredir, redir);
	return (0);
}

static int	build_cmd(t_token **tokens, char **cmdstr, t_redir **cmdredir)
{
	char	*temp;

	if (*tokens && (*tokens)->type == WORD)
	{
		temp = ft_strjoin(*cmdstr, (*tokens)->content);
		free(*cmdstr);
		*cmdstr = temp;
	}
	else if (*tokens && ((*tokens)->type & (OUTPUT | INPUT | APPEND | HEREDOC)))
		add_redir(tokens, cmdredir);
	*tokens = (*tokens)->next;
	return (0);
}

t_cmds	*cmd_parser(t_token *tokens)
{
	t_cmds	*cmd_chain;
	char	*cmdstr;
	t_cmds	*cmd;
	t_token	*head;

	cmd_chain = NULL;
	head = tokens;
	cmdstr = ft_strdup("\x1F");
	while (tokens)
	{
		cmd = ms_cmdnew();
		while (tokens && tokens->type != PIPE)
			build_cmd(&tokens, &cmdstr, &cmd->redirection);
		add_cmd(&cmd_chain, &cmdstr, cmd);
		if (tokens && tokens->type == PIPE)
			tokens = tokens->next;
	}
	ms_tokclear(&head, free);
	return (cmd_chain);
}
