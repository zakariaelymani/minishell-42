/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_input_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:32:01 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/07 19:16:20 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void find_output_input(t_cmds *cmd, int input, int output)
{
	t_redir_s *redirs;

	redirs = cmd->redirction;
	if (!redirs)
		return ;
	while (redirs)
	{
		if (redirs->type == OUTPUT || redirs->type == APPEND)
			output = redirs->fd;
		if (redirs->type == INPUT || redirs->type == HER_DOC)
			input = redirs->fd;
		redirs = redirs->next;
	}
	if (input > -1)
	{
		if (cmd->input > -1)
			close(cmd->input);
		cmd->input = input;
	}
	if(output > -1)
	{
		if (cmd->output > -1)
		 close(cmd->output);
		cmd->output = output;
	}
}
//take comand and fill input and out to dup out put and input all this all about chose which cmand fd will take output and which will take input ;
//take command and chose which fd will take out and if not will return ;
void dup_input_output(t_cmds **cmd)
{
	int input;
	int output;
	t_redir_s *redir;

	input = -1;
	output = -1;
	find_output_input(*cmd, input, output);
	if ((*cmd)->input > -1)
		input = dup2((*cmd)->input, STDIN_FILENO);
	if ((*cmd)->output > -1)
		output =  dup2((*cmd)->output, STDOUT_FILENO);
	(close((*cmd)->input), close((*cmd)->output));
	redir = (*cmd)->redirction;
	if (!redir)
		return ;
	while (redir)
	{
		if (redir->fd > -1)
			close(redir->fd);
		redir = redir->next;
	}
 }
