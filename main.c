/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:30:23 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/07 21:33:08 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int main(int argc, char *argv[], char *env[])
{
    t_env	*env_new;
    t_cmds   *cmd;
	
   char	*line;

    (void)argv;
	if (!env || !*env)
		env_new = hard_code_env();
    else
        env_new = creat_env(env);
    while (1)
    {
        line = readline("minishell$");
        add_history(line);
        cmd = parsing_line(line);
       excute_command_line(&cmd, &env_new);
    }
    
    
}

