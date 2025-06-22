/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:33:51 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/11 14:37:41 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "tools/tools.h"
# include <readline/readline.h>
# include <readline/history.h>
# include "struct.h"
# include "builtins/builtins.h"
# include <signal.h>
# include <sys/wait.h>
# include "executing_files/execute_header.h"
# include "parsing.h"
# include <sys/ioctl.h> 

extern int	g_global_status;
void	clear_and_exit(t_env **env);
#endif
