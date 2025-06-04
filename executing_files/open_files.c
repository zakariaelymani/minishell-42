/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:21:54 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/28 18:26:40 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_header.h"

int	open_redir(t_redir **tmp)
{
	if (ft_strchr((*tmp)->file_name, '\x1F'))
	{
		printf("Syntax Error: Ambiguous redirect\n");
		return (1);
	}
	if ((*tmp)->type == OUTPUT)
		(*tmp)->fd = ft_open((*tmp)->file_name, OUTPUT);
	else if ((*tmp)->type == INPUT)
		(*tmp)->fd = ft_open((*tmp)->file_name, INPUT);
	else if ((*tmp)->type == APPEND)
		(*tmp)->fd = ft_open((*tmp)->file_name, APPEND);
	if ((*tmp)->fd == -1)
		return (1);
	return (-1);
}

void close_fds(t_cmds *tmp)
{
	t_cmds *cmd;
	t_redir *redirs;

	cmd = tmp;
	while (cmd)	
	{
		redirs = cmd->redirection;
		while(redirs)
		{
			if (redirs->fd > -1)
				close(redirs->fd);
			redirs = redirs->next;
		}
		if (cmd->input > -1)
			close (cmd->input);
		if (cmd->output > -1)
			close (cmd->output);
		cmd = cmd->next;
	}
}

void	pipe_cammand(t_cmds **tmp)
{
	int		pid[2];

	if ((*tmp)->next)
	{
		if(pipe(pid) == -1)
			perror("pipe");
		(*tmp)->output = pid[1];
		(*tmp)->next->input = pid[0];
	}
}


int read_heredoc(t_cmds **cmd, t_env **env)
{
	t_redir *rids;
	t_cmds		*tmp;
	int		stdin_dup;

	tmp = (*cmd);
	stdin_dup = dup(STDIN_FILENO);
	while (tmp)
	{
		rids = tmp->redirection;
		while (rids)
		{
			if (rids->type == HEREDOC)
			{
				rids->fd = here_document(rids->file_name, rids->fd, env);
				if (rids->fd == -1)
					return ((*env)->exit_sta = 1, 1);
				if (rids->fd == -2)
					return (dup2(stdin_dup, STDIN_FILENO), close(stdin_dup), (*env)->exit_sta = 130, 1);
			}				
			rids = rids->next;
		}
		tmp = tmp->next;
	}
	return ((*env)->exit_sta = 0, close(stdin_dup), 0);
}

int open_files(t_cmds **cmds, t_env **env)
{
    t_redir	*redir;
    t_cmds		*tmp;
	int			return_val;
    
	tmp = (*cmds);
	redir = tmp->redirection;
	if (!redir)
		return (-1);
	while (redir)
	{
	    return_val = open_redir(&redir);
		if (return_val == 1)
		{
			(*env)->exit_sta = 1;
			return (1);
		}
		redir = redir->next;
	}
	return (0);
}
