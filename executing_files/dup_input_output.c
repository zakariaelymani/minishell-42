/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_input_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:32:01 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/24 16:16:28 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_header.h"

void find_output_input(t_cmds *cmd, int input, int output)
{
	t_redir *redirs;

	redirs = cmd->redirection;
	if (!redirs)
		return ;
	while (redirs)
	{
		if (redirs->type == OUTPUT || redirs->type == APPEND)
			output = redirs->fd;
		if (redirs->type == INPUT || redirs->type == HEREDOC)
			input = redirs->fd;
		redirs = redirs->next;
	}
	if (input > -2)
	{
		if (cmd->input > -1)
			close(cmd->input);
		cmd->input = input;
	}
	if(output > -2)
	{
		if (cmd->output > -1)
		 close(cmd->output);
		cmd->output = output;
	}
}

void dup_input_output(t_cmds **cmd, t_cmds *tmp)
{
	int input;
	int output;

	input = -2;
	output = -2;
	find_output_input(*cmd, input, output);
	if ((*cmd)->input > -1)
		input = dup2((*cmd)->input, STDIN_FILENO);
	if ((*cmd)->output > -1)
	{
		output =  dup2((*cmd)->output, STDOUT_FILENO);
	}
	if (input == -1 || output == -1)
			perror("minishell4");
	close_fds(tmp);
 }
