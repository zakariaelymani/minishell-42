/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:33:51 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/02 12:47:43 by zel-yama         ###   ########.fr       */
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


void    dup_input_output(t_cmds **cmd);//dup you dup in child and or parent acording to stats 
int		check_is_builtins(t_cmds *cmd);
void	pipe_cammand(t_cmds **cmd);
int		open_files(t_cmds **cmds, t_env **env);

#endif