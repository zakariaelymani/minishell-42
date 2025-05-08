/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:25:17 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/08 18:17:47 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//we will do this in child not in parent so 
void excute_command(t_cmds *cmd, t_env **env)
{
	char *path;
	char **env_to_excute;
	
	
	path = find_path_to_cmd(env, cmd->cmds[0]);
	if (!path)//clear and return here and exit in what in env exit status in first node and you should close fd; you should just exit; !! maybe here will be no command like this | > file.txt | no comand
		exit((*env)->exit_sta);
	env_to_excute = convert_strcut_array(*env);
	dub_for_cmds(&cmd, env);
	execve(path,cmd->cmds, env_to_excute);
	perror("minishell");
	exit(127);
	//here you should ` clear and / and you should run 
	
}

//check is builtins if that call and exit this in child

void wait_child(t_cmds *tmp, t_env **env)
{
	int 		status;
	t_cmds 		*cmd;
	t_redir_s 	*redir;

	cmd = tmp;
	redir = cmd->redirction;
	while (redir)
	{
		if (redir->fd > -1)
			close(redir->fd);
		redir = redir->next;
	}
	if (cmd->input > -1)
		close(cmd->input);
	if (cmd->output > -1)
		close (cmd->output);
	while (cmd)
	{
		waitpid(-1, &status, 0);
		cmd = cmd->next;
	}
	(*env)->exit_sta = WEXITSTATUS(status);
	
}

void fork_and_excute(t_cmds **cmd, t_env **env)
{
	int i;
	int x;
	t_cmds *tmp;

	tmp = (*cmd);
	while (tmp)
	{
		tmp->pid = fork();
		if (tmp->pid == 0)
		{
			i = check_is_builtins(*cmd);
			if (i != -1 && i  != -2)
				excute_builtins_inchild(cmd, env, i);
			else if (i == -2)
				exit(open_files(cmd, env));
			else
				excute_command(tmp, env);
		}
		else
			wait_child(tmp, env);
		tmp = tmp->next;
	}
}

void	excute_command_line(t_cmds **cmd, t_env **env)
{
	int i;
	int cmdsize;

	read_heredoc(cmd, env);
	cmdsize = t_cmdsize(*cmd);
	if (cmdsize == 1)
	{
		i = check_is_builtins(*cmd);
		if (i != -1 && i != -2)
		{
			excute_builtins_inparent(cmd, env, i);
			return ;
		}
		if (i == -2)
		{
			(*env)->exit_sta = open_files(cmd, env);
			return ;
		}
	}
	pipe_cammand(cmd, cmdsize);
	fork_and_excute(cmd, env);
}
