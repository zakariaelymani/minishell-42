/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/02 12:31:43 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_global_status;

int main(int argc, char *argv[], char *env[])
{
	t_env *env_new;
	t_cmds	*cmd;
	struct	termios term;
	char	*line;
	int		last_status;
	t_token	*tokens;

	env_new = get_env(argc, argv, env);
	tcgetattr(STDIN_FILENO, &term);
	while (1)
	{
		signals(1);
		g_global_status = 1;
		line = readline("minishell$ ");
		g_global_status = 2;
		if (!line)
			(write(2, "exit\n", 6), rl_clear_history(), clear_env(&env_new, &last_status), exit(last_status));
		if (!*line)
			continue ;
		add_history(line);
		tokens = ms_tokenizer(line);
		if (!tokens)
			continue ;
		if(!syntax_checker(tokens))
			continue ;
		if (!ms_expander(tokens, env_new))
			continue ;
		cmd = cmd_parser(tokens);
		execute_command_line(&cmd, &env_new);
		clear_commands(&cmd);
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}
}
