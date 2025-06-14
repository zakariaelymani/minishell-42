/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/09 15:09:09 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global_status;

void	sanitize_input(char *line)
{
	while (*line)
	{
		if (ft_strchr("\x1F\x1D\x1E", *line))
			*line = '\x1C';
		line++;
	}
}

static t_cmds	*process_input(char *line, t_env *env)
{
	t_token	*tokens;
	t_cmds	*cmd;

	sanitize_input(line);
	tokens = ms_tokenizer(line);
	free(line);
	if (!tokens)
	{
		env->exit_sta = 2;
		return (NULL);
	}
	if (!syntax_checker(tokens) || !ms_expander(tokens, env))
	{
		env->exit_sta = 2;
		ms_tokclear(&tokens, free);
		return (NULL);
	}
	cmd = cmd_parser(tokens);
	return (cmd);
}

void	clear_and_exit(t_env **env)
{
	int	last_status;

	rl_clear_history();
	clear_env(env, &last_status);
	exit(last_status);
}

char	*read_input(t_env **env)
{
	char	*line;

	g_global_status = 1;
	line = readline("minishell$ ");
	if (g_global_status == 4)
		(*env)->exit_sta = 130;
	g_global_status = 2;
	if (!line)
	{
		write(2, "exit\n", 6);
		clear_and_exit(env);
	}
	return (line);
}

int	main(int argc, char *argv[], char *env[])
{
	t_env			*env_new;
	t_cmds			*cmd;
	struct termios	term;
	char			*line;

	env_new = get_env(argc, argv, env);
	tcgetattr(STDIN_FILENO, &term);
	while (1)
	{
		signals(1);
		line = read_input(&env_new);
		if (!isatty(STDIN_FILENO))
			break ;
		if (!*line)
			continue ;
		add_history(line);
		cmd = process_input(line, env_new);
		if (!cmd)
			continue ;
		execute_command_line(&cmd, &env_new);
		clear_commands(&cmd);
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}
	free_vars(line, NULL, NULL, NULL);
	clear_and_exit(&env_new);
}
