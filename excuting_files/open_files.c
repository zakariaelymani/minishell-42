/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:21:54 by zel-yama          #+#    #+#             */
<<<<<<<< HEAD:excuting_files.c/open_files.c
/*   Updated: 2025/05/17 10:22:49 by zel-yama         ###   ########.fr       */
========
/*   Updated: 2025/05/14 12:54:47 by zel-yama         ###   ########.fr       */
>>>>>>>> merged:excuting_files/open_files.c
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

<<<<<<<< HEAD:excuting_files.c/open_files.c
void close_fds(t_cmds *tmp)
{
	t_cmds *cmd;
	t_redir_s *redirs;

	cmd = tmp;
	while (cmd)	
	{
		redirs = cmd->redirction;
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
	
========
void	pipe_cammand(t_cmds *tmp)
{
	int		pid[2];

	if (tmp->next)
	{
		if(pipe(pid) == -1)
			perror("pipe");
>>>>>>>> merged:excuting_files/open_files.c
		tmp->output = pid[1];
		tmp->next->input = pid[0];
	}
}
void read_heredoc(t_cmds **cmd, t_env **env)
{
	t_redir *rids;
	t_cmds		*tmp;
	
	tmp = (*cmd);
	while (tmp)
	{
		rids = tmp->redirection;
		while (1)
		{
			if (!rids)
				break ;
			if (rids->type == HEREDOC)
				rids->fd = here_document(rids->file_name, rids->fd, env);
			rids = rids->next;
		}
		tmp = tmp->next;
	}
	
}

int open_files(t_cmds **cmds, t_env **env)
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
		if (return_val == 1)
		{
			(*env)->exit_sta = 1;
			return (1);
		}	
		redir = redir->next;
	}
	return (0);
}
