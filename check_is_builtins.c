/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:28:55 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/07 15:01:50 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int  check_is_builtins(t_cmds *cmd)
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

void excute_builtins(t_cmds **cmd, t_env **env, int stat)
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
		(*env)->exit_sta = ft_exit((*cmd)->cmds);
	else if (stat == 7)
		(*env)->exit_sta = change_dir((*cmd)->cmds, env);
	
}

void excute_builtins_inchild(t_cmds **cmd, t_env **env, int stat)
{
	dub_for_cmds(cmd, env);
	if (stat == 1)
		exit(my_echo((*cmd)->cmds, env));
	else if (stat == 2)
		exit(export(env, (*cmd)->cmds)); 
	else if (stat == 3)
		exit (unset(env, (*cmd)->cmds));
	else if (stat == 4)
		exit(env_cmd(*env));
	else if (stat == 5)
		exit(my_pwd(env));
	else if (stat == 6)
		exit (ft_exit((*cmd)->cmds));
	else if (stat == 7)
		exit (change_dir((*cmd)->cmds, env));
	
}
//this else in parent if we in bultins of in child if we in exute so what 
int		excute_builtins_inparent(t_cmds **cmd, t_env **env, int stat)
{
	int input;
	int	output;
	int ret_val;
	
	ret_val = open_files(cmd, env);
	if (ret_val == 1 || ret_val == -1)
	{
		if (ret_val == -1)
			excute_builtins(cmd, env, stat);
		return (1);
	}
	else if (ret_val == 0)
	{
		input = dup(STDIN_FILENO);
		output = dup(STDOUT_FILENO);
		dup_input_output(cmd);
	}
	excute_builtins(cmd, env, stat);
	if (ret_val == 0)
	{
		dup2(input, STDIN_FILENO);
		dup2(output, STDOUT_FILENO);
		close(input);
		close(output);
	}
	return (0);
}