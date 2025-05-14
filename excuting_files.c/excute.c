/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:25:17 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/14 13:11:19 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "excute_header.h"

void excute_command(t_cmds *cmd, t_env **env)
{
	char *path;
	char **env_to_excute;
	
	path = find_path_to_cmd(env, cmd->cmds[0]);
	if (!path)
		exit((*env)->exit_sta);
	env_to_excute = convert_strcut_array(*env);
	dub_for_cmds(&cmd, env);
	execve(path,cmd->cmds, env_to_excute);
	perror("minishell5");
	exit(127);
}

void wait_child(t_cmds *tmp, t_env **env)
{
	
	t_cmds 		*cmd;
	t_redir_s 	*redir;
	int 		status;

	cmd = tmp;
	while (cmd->next)
	{
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
	
		cmd = cmd->next;
	}
	waitpid(-1, &status, 0);
	(*env)->exit_sta = WEXITSTATUS(status);
	return ;
}

void turn_dif(int exit_s)
{
	write(2,"eee", 4);
	(void)exit_s;
	exit(2);
	rl_on_new_line();
    rl_replace_line("", 0);
    ft_putstr_fd("\n",1);
    rl_redisplay();
}

void turn_sig_quit(int i)
{
	write(2, "Quit:\n", 7);
	ft_putstr_fd("\n", 1);
	(void)i;
	exit(131);
	rl_on_new_line();
	rl_redisplay();
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
			signal(SIGINT, turn_dif);
			signal(SIGQUIT, turn_sig_quit);
			i = check_is_builtins(tmp);
			if (i != -1 && i  != -2)
				excute_builtins_inchild(&tmp, env, i);
			else if (i == -2)
				exit(open_files(&tmp, env));
			else
				excute_command(tmp, env);
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
