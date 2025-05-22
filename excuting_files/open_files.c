/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:21:54 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/22 14:56:32 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excute_header.h"

int	open_redir(t_redir **tmp)
{
	if ((*tmp)->type == OUTPUT)
		(*tmp)->fd = ft_open((*tmp)->file_name, OUTPUT);
	else if ((*tmp)->type == INPUT)
		(*tmp)->fd = ft_open((*tmp)->file_name, INPUT);
	else if ((*tmp)->type == APPEND)
		(*tmp)->fd = ft_open((*tmp)->file_name, APPEND);
	if ((*tmp)->fd == -1)
	{
		perror("minishell-->");
		return (1);
	}
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

void	pipe_cammand(t_cmds *tmp)
{
	int		pid[2];

	if (tmp->next)
	{
		if(pipe(pid) == -1)
			perror("pipe");
		tmp->output = pid[1];
		tmp->next->input = pid[0];
	}
}

int fork_and_readheredoc(t_env **env, t_redir *redir)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("minishell: fork");
		return (1);
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
		redir->fd = here_document(redir->file_name, redir->fd, env);
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		(*env)->exit_sta = WEXITSTATUS(status);
		if (WIFEXITED(status) && (*env)->exit_sta != 0)
			return (1);
	}
	return (0);
}


void read_heredoc(t_cmds **cmd, t_env **env)
{
	t_redir *rids;
	t_cmds		*tmp;
	
	tmp = (*cmd);
	while (tmp)
	{
		rids = tmp->redirection;
		while (rids)
		{
			if (rids->type == HEREDOC)
				if (fork_and_readheredoc(env, rids) == 1)
					return ;
			rids = rids->next;
		}
		tmp = tmp->next;
	}
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
