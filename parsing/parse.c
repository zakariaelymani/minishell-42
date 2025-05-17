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

t_redir	*new_redir(t_type type)
{
	t_redir	*result;
	result = (t_redir *)malloc(sizeof(t_redir));
	if (!result)
		return (NULL);
	result->file_name = NULL;
	result->type = type;
	result->fd = -1;
	result->next = NULL;
	return (result);
}

t_redir *ms_redlast(t_redir *lst)
{
        if (!lst)
                return (NULL);
        while (lst->next)
                lst = lst->next;
        return (lst);
}

void    ms_redappend(t_redir **lst, t_redir *new)
{
        if (!lst || !new)
                return ;
        if (!*lst)
                *lst = new;
        else
                ms_redlast(*lst)->next = new;
}

int	add_cmd(t_cmds **chain, char **cmdstr, t_cmds *cmd)
{
	cmd->cmds = ft_split(*cmdstr, '\x1F');
	if (!cmd->cmds)
		return (1);
	free(*cmdstr);
	*cmdstr = NULL;
	ms_cmdappend(chain, cmd);
	return (0);
}

t_cmds	*cmd_parser(t_token *tokens)
{
	t_cmds	*cmd_chain;
	t_redir	*redir;
	char	*cmdstr;
	char	*temp;
	t_cmds	*cmd;

	cmd_chain = NULL;
	cmdstr = NULL;
	redir = NULL;
	while (tokens)
	{
		cmd = ms_cmdnew();
		while (tokens && tokens->type != PIPE)
		{
			if (tokens && tokens->type == WORD)
			{
				temp = ft_strjoin(cmdstr, tokens->content);
				free(cmdstr);
				cmdstr = temp;
			}
			else if (tokens && (tokens->type & (OUTPUT | INPUT | APPEND | HEREDOC)))
			{
				redir = new_redir(tokens->type);
				tokens = tokens->next;
				redir->file_name = ft_substr(tokens->content, 0, ft_strlen(tokens->content) - 1);
				ms_redappend(&cmd->redirection, redir);
			}
			tokens = tokens->next;
		}
		add_cmd(&cmd_chain, &cmdstr, cmd);
		if (tokens && tokens->type == PIPE)
			tokens = tokens->next;
	}
	return (cmd_chain);
}
