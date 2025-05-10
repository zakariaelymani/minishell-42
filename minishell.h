/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:33:51 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/10 18:14:29 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tools/tools.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "struct.h"
#include "builtins/builtins.h"
#include <sched.h>
#include <string.h>
#include <termios.h>

#define OPEN_FATAL 1
#define OPEN_OK 0
#define OPEN_SKIP -1

void    dup_input_output(t_cmds **cmd);//dup you dup in child and or parent acording to stats 
int		check_is_builtins(t_cmds *cmd);
void	pipe_cammand(t_cmds *tmp);
int		open_files(t_cmds **cmds, t_env **env);
void    excute_builtins(t_cmds **cmd, t_env **env, int stat);
void    read_heredoc(t_cmds **cmd, t_env **env);
t_cmds  *parsing_line(char *line);
void	excute_command_line(t_cmds **cmd, t_env **env);
void    excute_builtins_inchild(t_cmds **cmd, t_env **env, int stat);
int		excute_builtins_inparent(t_cmds **cmd, t_env **env, int stat);
void    dub_for_cmds(t_cmds **cmd, t_env **env);
void    print_parsed_cmds(t_cmds *cmds);

#endif