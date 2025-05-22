/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/22 14:42:29 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int globle_var; 

// void print_parsed_cmds(t_cmds *cmds) {
// 	int n = 1;
// 	while (cmds) {
// 		printf("Command %d:\n", n++);
// 		for (int i = 0; cmds->cmds && cmds->cmds[i]; i++) {
// 			printf("  Arg[%d]: %s\n", i, cmds->cmds[i]);
// 		}
// 		for (t_redir *r = cmds->redirction; r; r = r->next) {
// 			printf("  Redir: type=%d, file=%s\n", r->type, r->file_name);
// 		}
// 		cmds = cmds->next;
// 	}
// }

void handler(int i)
{
	if (i == SIGINT && globle_var == 1)
	{
		rl_on_new_line();
		ft_putstr_fd("\n",1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
void handler_child(int sig)
{
	if (SIGINT == sig)
	{
		write(1, "\n", 1);
		exit(130);
	}
	else if (SIGQUIT == sig)
	{
		write(1, "Quit (core dumped)\n",20);
		exit(131);
	}
}

void signales(int flag)
{
	if (flag == 1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
	}
	else if (flag == 2)
	{
		signal(SIGINT, handler_child);
		signal(SIGQUIT, handler_child);
	}
}

int main(int argc, char *argv[], char *env[])
{
	t_env	*env_new;
	t_cmds   *cmd;
	struct termios term;
   	char	*line;
   
	env_new = get_env(argc, argv, env);
	tcgetattr(STDIN_FILENO, &term);
	while (1)
	{
	   	signales(1);
		globle_var = 1;
		line = readline("minishel$ ");
		globle_var = 0;
		 if (!line)
			(write(2, "exit\n", 6), rl_clear_history(), clear_env(&env_new), exit(env_new->exit_sta));
		if (!*line)
			continue;
		add_history(line);
		cmd = parsing_line(line);
		excute_command_line(&cmd, &env_new);
		clear_commands(&cmd);
		signales(2);
		tcsetattr( STDIN_FILENO, TCSANOW, &term);
	}
}

