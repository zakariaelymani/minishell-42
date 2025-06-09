/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/08 20:37:33 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_global_status;

static t_cmds *process_input(char *line, t_env *env)
{
	t_token *tokens;
	t_cmds *cmd;

	tokens = ms_tokenizer(line);
	if (!tokens)
		return (NULL);
	if (!syntax_checker(tokens, env))
		return (NULL);
	if (!ms_expander(tokens, env))
		return (NULL);
	cmd = cmd_parser(tokens);
	return (cmd);
}

int main(int argc, char *argv[], char *env[])
{
	t_env *env_new;
	t_cmds *cmd;
	struct termios term;
	char *line;
	int last_status;

	env_new = get_env(argc, argv, env);
	tcgetattr(STDIN_FILENO, &term);
	while (1)
	{
		signals(1);
		g_global_status = 1;
		line = readline("minishell$ ");
		if (g_global_status == 130)
			env_new->exit_sta = 130;
		g_global_status = 2;
		if (!line)
			(write(2, "exit\n", 6), rl_clear_history(), clear_env(&env_new, &last_status), exit(last_status));
		if (!isatty(STDIN_FILENO))
			return 1;
		if (!*line)
			continue ;
		add_history(line);
		cmd = process_input(line, env_new);
		if (!cmd)
			continue;
		execute_command_line(&cmd, &env_new);
		clear_commands(&cmd);
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}
}
