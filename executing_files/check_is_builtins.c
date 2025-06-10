/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkaro <abenkaro@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:28:55 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/10 16:46:44 by abenkaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_header.h"

int	check_is_builtins(t_cmds *cmd)
{
	if (!*cmd->cmds || !cmd->cmds)
		return (-2);
	else if (compare(cmd->cmds[0], "echo") == 0)
		return (1);
	else if (compare(cmd->cmds[0], "export") == 0)
		return (2);
	else if (compare(cmd->cmds[0], "unset") == 0)
		return (3);
	else if (compare(cmd->cmds[0], "env") == 0)
		return (4);
	else if (compare(cmd->cmds[0], "pwd") == 0)
		return (5);
	else if (compare(cmd->cmds[0], "exit") == 0)
		return (6);
	else if (compare(cmd->cmds[0], "cd") == 0)
		return (7);
	return (-1);
}

void	execute_builtins(t_cmds **cmd, t_env **env, int stat)
{
	if (stat == 1)
		(*env)->exit_sta = my_echo((*cmd)->cmds, env);
	else if (stat == 2)
		(*env)->exit_sta = export(env, (*cmd)->cmds);
	else if (stat == 3)
		(*env)->exit_sta = unset(env, (*cmd)->cmds);
	else if (stat == 4)
		(*env)->exit_sta = env_cmd(*env);
	else if (stat == 5)
		(*env)->exit_sta = my_pwd(env);
	else if (stat == 6)
	{
		close_fds(*cmd);
		(*env)->exit_sta = ft_exit((*cmd)->cmds, 0, env, cmd);
	}	
	else if (stat == 7)
		(*env)->exit_sta = change_dir((*cmd)->cmds, env);
}

void	close_and_exit(int status, t_cmds **cmd)
{
	close_fds(*cmd);
	exit(status);
}

void	execute_builtins_inchild(t_cmds **cmd, t_env **env,
		int stat, t_cmds *tmp)
{
	dub_for_cmds(cmd, env, tmp);
	if (stat == 1)
		close_and_exit(my_echo((*cmd)->cmds, env), cmd);
	else if (stat == 2)
		close_and_exit(export(env, (*cmd)->cmds), cmd);
	else if (stat == 3)
		close_and_exit((unset(env, (*cmd)->cmds)), cmd);
	else if (stat == 4)
		close_and_exit((env_cmd(*env)), cmd);
	else if (stat == 5)
		close_and_exit(my_pwd(env), cmd);
	else if (stat == 6)
		ft_exit((*cmd)->cmds, 0, env, cmd);
	else if (stat == 7)
		close_and_exit(change_dir((*cmd)->cmds, env), cmd);
}
