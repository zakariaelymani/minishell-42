/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:21:54 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/02 12:55:53 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_redir(t_redir_s **tmp, t_env **env)
{
	if ((*tmp)->type == OUTPUT)
		(*tmp)->fd = ft_open((*tmp)->file_name, OUTPUT);
	else if (tmp->type == INPUT)
		(*tmp)->fd = ft_open((*tmp)->file_name, INPUT);
	else if ((*tmp)->type == APPEND)
		(*tmp)->fd = ft_open((*tmp)->file_name, APPEND);
	if ((*tmp)->fd == -1)
	{
		perror("minishell");
		return (1);
	}
	return (-1);
}
//cat > c | ls | rev | grep a 
void	pipe_cammand(t_cmds **cmd)
{
	t_cmds	*tmp;
	int		return_val;
	int		pid[2];

	tmp = (*cmd);
	if (!tmp->next)
		return ;
	while (tmp->next)
	{
		return_val = pipe(pid);
		if (return_val == -1)
		{
			perror("pipe");
			exit(1);
		}
		tmp->output = pid[1];
		tmp->next->input = pid[0];
		tmp = tmp->next;
	}
}
//echo >> ii >> ii > l < ij 
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
	    return_val = open_redir(&redir, env);
		if (return_val == 1)
		{
			(*env)->exit_sta = 1;
			return (1);
		}
			
		redir = redir->next;
	}
	return (-2);
}
