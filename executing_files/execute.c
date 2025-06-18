/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:25:17 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 14:14:23 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_header.h"

void	execute_command(t_cmds *cmd, t_env **env, t_cmds *tmp)
{
	char	*path;
	char	**env_to_excute;
	int		status;

	path = find_path_to_cmd(env, cmd->cmds[0], 0);
	if (!path)
	{
		dub_for_cmds(&cmd, env, tmp);
		close_fds(tmp);
		clear_commands(&tmp);
		clear_and_exit(env);
	}
	dub_for_cmds(&cmd, env, tmp);
	env_to_excute = convert_strcut_array((*env)->next);
	execve(path, cmd->cmds, env_to_excute);
	free_while(env_to_excute);
	clear_commands(&tmp);
	clear_env(env, &status);
	perror("minishell");
	exit(127);
}

void	wait_child(t_cmds *tmp, t_env **env)
{
	t_cmds		*cmd;
	int			status;
	pid_t		last_pid;

	cmd = tmp;
	while (cmd->next)
	{
		cmd = cmd->next;
	}
	last_pid = cmd->pid;
	close_fds(tmp);
	cmd = tmp;
	while (cmd)
	{
		if (cmd->pid == last_pid)
			waitpid(cmd->pid, &status, 0);
		else
			waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
	if (WIFSIGNALED(status) && handle_sigs_child(env, WTERMSIG(status)) == 1)
		return ;
	(*env)->exit_sta = WEXITSTATUS(status);
	return ;
}

int	remove_orphan(t_cmds *cmd, int return_val)
{
	t_cmds	*tmp;

	if (return_val != -1)
		return (0);
	tmp = cmd;
	perror("minishell: fork failed");
	close_fds(cmd);
	while (tmp->pid != -1)
	{
		kill(tmp->pid, SIGKILL);
		waitpid(tmp->pid, NULL, 0);
		tmp = tmp->next;
	}
	return (1);
}

void	fork_and_execute(t_cmds **cmd, t_env **env)
{
	int		i;
	t_cmds	*tmp;

	tmp = (*cmd);
	while (tmp)
	{
		if (pipe_cammand(&tmp) == -1)
			break ;
		tmp->pid = fork();
		if (tmp->pid == 0)
		{
			signals(2);
			i = check_is_builtins(tmp);
			if (i != -1 && i != -2)
				execute_builtins_inchild(&tmp, env, i, *cmd);
			else if (i == -2)
				exit(open_files(&tmp, env));
			else
				execute_command(tmp, env, *cmd);
		}
		else if (remove_orphan(*cmd, tmp->pid) == 1)
			return ;
		tmp = tmp->next;
	}
	wait_child(*cmd, env);
}

void	execute_command_line(t_cmds **cmd, t_env **env)
{
	int	i;
	int	cmdsize;

	if (read_heredoc(cmd, env) != 0)
		return ;
	cmdsize = t_cmdsize(*cmd);
	if (cmdsize == 1)
	{
		i = check_is_builtins(*cmd);
		if (i != -1 && i != -2)
		{
			execute_builtins_inparent(cmd, env, i);
			close_fds(*cmd);
			return ;
		}
		if (i == -2)
		{
			(*env)->exit_sta = open_files(cmd, env);
			close_fds(*cmd);
			return ;
		}
	}
	fork_and_execute(cmd, env);
	return ;
}
