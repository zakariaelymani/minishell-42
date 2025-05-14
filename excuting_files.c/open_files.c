/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:21:54 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/13 12:42:49 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_redir(t_redir_s **tmp)
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
//cat > c | ls | rev | grep a 
void	pipe_cammand(t_cmds *tmp)
{
	int		return_val;
	int		pid[2];

	if (tmp->next)
	{
		return_val = pipe(pid);
		if (return_val == -1)
		{
			perror("pipe");
			exit(1);
		}
		
		tmp->output = pid[1];
		tmp->next->input = pid[0];
	}
}
void read_heredoc(t_cmds **cmd, t_env **env)
{
	t_redir_s *rids;
	t_cmds		*tmp;
	
	tmp = (*cmd);
	while (tmp)
	{
		rids = tmp->redirction;
		while (1)
		{
			if (!rids)
				break ;
			if (rids->type == HER_DOC)
				rids->fd = here_document(rids->file_name, rids->fd, env);
			rids = rids->next;
		}
		tmp = tmp->next;
	}
	
}

int open_files(t_cmds **cmds, t_env **env)
{
    t_redir_s	*redir;
    t_cmds		*tmp;
	int			return_val;
    
	tmp = (*cmds);
	redir = tmp->redirction;
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
