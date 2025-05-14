/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/14 11:06:59 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libc.h>
void print_parsed_cmds(t_cmds *cmds) {
    int n = 1;
    while (cmds) {
        printf("Command %d:\n", n++);
        for (int i = 0; cmds->cmds && cmds->cmds[i]; i++) {
            printf("  Arg[%d]: %s\n", i, cmds->cmds[i]);
        }
        for (t_redir_s *r = cmds->redirction; r; r = r->next) {
            printf("  Redir: type=%d, file=%s\n", r->type, r->file_name);
        }
        cmds = cmds->next;
    }
}
void handler_c(int i)
{
    (void)i;
    rl_on_new_line();
  rl_replace_line("", 0);
    ft_putstr_fd("\n",1);
    rl_redisplay();
}
void sig_quit(int t)
{
    (void)t;
    rl_on_new_line();
    rl_redisplay();
}

int main(int argc, char *argv[], char *env[])
{
    t_env	*env_new;
    t_cmds   *cmd;
	struct termios term;
	
   char	*line;
  
    (void)argv;
    (void)argc;
    
	if (!env || !*env)
		env_new = hard_code_env();
    else
        env_new = creat_env(env);
    tcgetattr(STDIN_FILENO, &term);
    while (1)
    {
       // signal(SIGINT,handler_c);
      //  signal(SIGQUIT, sig_quit);
        line = readline("minishell$ ");
         if (!line)
            (write(2, "exit", 5), exit(0));
        if (!*line)
            continue;
        add_history(line);
        cmd = parsing_line(line);
       excute_command_line(&cmd, &env_new);
       free(line);
	   tcsetattr( STDIN_FILENO, TCSANOW, &term);
    }
}

