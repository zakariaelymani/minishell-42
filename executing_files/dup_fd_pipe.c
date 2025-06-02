/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/29 15:13:19 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_header.h"

void dub_for_cmds(t_cmds **cmd, t_env **env, t_cmds *tmp)
{
	int fd;

	fd = open_files(cmd, env);
	if (fd == 1)
		(perror("mininshll"), exit(1));
	dup_input_output(cmd, tmp);
}
int		execute_builtins_inparent(t_cmds **cmd, t_env **env, int stat)
{
	int input;
	int	output;
	int ret_val;
	
	
	ret_val = open_files(cmd, env);
	if (ret_val == 1 || ret_val == -1)
	{
		if (ret_val == -1)
			execute_builtins(cmd, env, stat);
		return (1);
	}
	else if (ret_val == 0)
	{
		input = dup(STDIN_FILENO);
		output = dup(STDOUT_FILENO);
		if (input == -1 || output == -1)
			perror("minishell3");
		dup_input_output(cmd, *cmd);
	}
	execute_builtins(cmd, env, stat);
	if (ret_val == 0)
	{
		if (dup2(input, STDIN_FILENO) == -1)
			perror("minishell1");
		if (dup2(output, STDOUT_FILENO) == -1)
			perror("minishell2");
		close(input);
		close(output);
	}
	return (0);
}
