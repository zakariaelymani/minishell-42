/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:33:51 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/21 16:46:21 by zel-yama         ###   ########.fr       */
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
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "executing_files/execute_header.h"
#include "parsing.h"

//he will check if ziro that will  we in parent  but in child it is somthing ot other

extern int g_global_status;

void	excute_command_line(t_cmds **cmd, t_env **env);
char	*mini_get_line(void);
#endif
