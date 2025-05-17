/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_input_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:32:01 by zel-yama          #+#    #+#             */
<<<<<<<< HEAD:excuting_files.c/dup_input_output.c
/*   Updated: 2025/05/17 10:56:27 by zel-yama         ###   ########.fr       */
========
/*   Updated: 2025/05/14 12:34:34 by zel-yama         ###   ########.fr       */
>>>>>>>> merged:excuting_files/dup_input_output.c
/*                                                                            */
/* ************************************************************************** */

#include "excute_header.h"

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

<<<<<<<< HEAD:excuting_files.c/dup_input_output.c
void dup_input_output(t_cmds **cmd, t_cmds *tmp)
{
	int input;
	int output;
========
void dup_input_output(t_cmds **cmd)
{
	int input;
	int output;
	t_redir *redir;
>>>>>>>> merged:excuting_files/dup_input_output.c

	input = -2;
	output = -2;
	find_output_input(*cmd, input, output);
	if ((*cmd)->input > -1)
		input = dup2((*cmd)->input, STDIN_FILENO);
	if ((*cmd)->output > -1)
<<<<<<<< HEAD:excuting_files.c/dup_input_output.c
========
		output =  dup2((*cmd)->output, STDOUT_FILENO);
	if (input == -1 || output == -1)
			perror("minishell4");
	(close((*cmd)->input), close((*cmd)->output));
	redir = (*cmd)->redirection;
	if (!redir)
		return ;
	while (redir)
>>>>>>>> merged:excuting_files/dup_input_output.c
	{
		output =  dup2((*cmd)->output, STDOUT_FILENO);
	}
	if (input == -1 || output == -1)
			perror("minishell4");
	close_fds(tmp);
 }
