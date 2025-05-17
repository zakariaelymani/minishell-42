/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:25:17 by zel-yama          #+#    #+#             */
<<<<<<<< HEAD:excuting_files.c/excute.c
/*   Updated: 2025/05/17 11:44:23 by zel-yama         ###   ########.fr       */
========
/*   Updated: 2025/05/16 19:25:15 by zel-yama         ###   ########.fr       */
>>>>>>>> merged:excuting_files/excute.c
/*                                                                            */
/* ************************************************************************** */

#include "excute_header.h"

<<<<<<<< HEAD:excuting_files.c/excute.c
void excute_command(t_cmds *cmd, t_env **env, t_cmds *tmp)
========
void excute_command(t_cmds *cmd, t_env **env)
>>>>>>>> merged:excuting_files/excute.c
{
	char *path;
	char **env_to_excute;
	
	path = find_path_to_cmd(env, cmd->cmds[0]);
	if (!path)
		exit((*env)->exit_sta);
	env_to_excute = convert_strcut_array(*env);
	dub_for_cmds(&cmd, env, tmp);
	execve(path,cmd->cmds, env_to_excute);
	perror("minishell5");
	exit(127);
}

void wait_child(t_cmds *tmp, t_env **env)
{
	
	t_cmds 		*cmd;
<<<<<<<< HEAD:excuting_files.c/excute.c
========
	t_redir 	*redir;
>>>>>>>> merged:excuting_files/excute.c
	int 		status;
	pid_t		last_pid;

	
	cmd = tmp; 
	while (cmd->next)
	{
		cmd = cmd->next;
	}
	last_pid = cmd->pid;
<<<<<<<< HEAD:excuting_files.c/excute.c
	close_fds(tmp);
	cmd = tmp;
	while (cmd)
	{
========
	cmd = tmp;
	while (cmd)
	{
		redir = cmd->redirection;
		while (redir)
		{
			if (redir->fd > -1)
				close(redir->fd);
			redir = redir->next;
		}
		if (cmd->next)
			if (cmd->next->input > -1)
				close(cmd->next->input);
		if (cmd->output > -1)
			close (cmd->output);
>>>>>>>> merged:excuting_files/excute.c
		if (cmd->pid == last_pid)
			waitpid(cmd->pid, &status, 0);
		else
			waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
	(*env)->exit_sta = WEXITSTATUS(status);
	return ;
}

void fork_and_excute(t_cmds **cmd, t_env **env)
{
	int i;
	t_cmds *tmp;
	
	tmp = (*cmd);
	while (tmp)
	{
		pipe_cammand(tmp);
		tmp->pid = fork();
		if (tmp->pid == 0)
		{
<<<<<<<< HEAD:excuting_files.c/excute.c
		
			 signales(2);
			i = check_is_builtins(tmp);
			if (i != -1 && i  != -2)
				excute_builtins_inchild(&tmp, env, i, *cmd);
========
			 signales(2);
			i = check_is_builtins(tmp);
			if (i != -1 && i  != -2)
				excute_builtins_inchild(&tmp, env, i);
>>>>>>>> merged:excuting_files/excute.c
			else if (i == -2)
				exit(open_files(&tmp, env));
			else
				excute_command(tmp, env, *cmd);
		}
		if (tmp->pid == -1)
			perror("minishell");
		tmp = tmp->next;
	}
	wait_child(*cmd, env);
	return ;
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
	fork_and_excute(cmd, env);
	return ;
}
