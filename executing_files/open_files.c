/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:21:54 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/10 16:46:09 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_header.h"

int	open_redir(t_redir **tmp)
{
	char	*s;

	s = (*tmp)->file_name;
	if ((*tmp)->type == HEREDOC)
		return (-1);
	if (counterwords(s, '\x1D') != 1)
		return (ft_putstr_fd("Syntax Error: Ambiguous redirect\n", 2), -2);
	else
	{
		while (*s)
		{
			if (*s == '\x1D')
				*s = ' ';
			s++;
		}
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

void	close_fds(t_cmds *tmp)
{
	t_cmds	*cmd;
	t_redir	*redirs;

	cmd = tmp;
	while (cmd)
	{
		redirs = cmd->redirection;
		while (redirs)
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
	int	pid[2];

	if ((*tmp)->next)
	{
		if (pipe(pid) == -1)
		{
			perror("pipe");
			return ;
		}
		(*tmp)->output = pid[1];
		(*tmp)->next->input = pid[0];
	}
}

int	read_heredoc(t_cmds **cmd, t_env **env)
{
	t_redir		*rids;
	t_cmds		*tmp;
	int			fd;

	tmp = (*cmd);
	fd = dup(STDIN_FILENO);
	while (tmp)
	{
		rids = tmp->redirection;
		while (rids)
		{
			if (rids->type == HEREDOC)
			{
				rids->fd = here_document(rids->file_name, rids->fd, env);
				if (rids->fd == -1)
					return (close(fd), close_fds(*cmd), 1);
				if (rids->fd == -2)
					return (dup2(fd, STDIN_FILENO),
						close(fd), close_fds(*cmd), 1);
			}
			rids = rids->next;
		}
		tmp = tmp->next;
	}
	return (close(fd), 0);
}

int	open_files(t_cmds **cmds, t_env **env)
{
	t_redir		*redir;
	t_cmds		*tmp;
	int			return_val;

	tmp = (*cmds);
	redir = tmp->redirection;
	if (!redir)
		return (-1);
	while (redir)
	{
		return_val = open_redir(&redir);
		if (return_val == 1 || return_val == -2)
		{
			(*env)->exit_sta = 1;
			if (return_val == 1)
				perror("minishell");
			return (1);
		}
		redir = redir->next;
	}
	return (0);
}
