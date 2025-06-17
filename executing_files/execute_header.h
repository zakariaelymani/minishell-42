/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:05:27 by zel-yama          #+#    #+#             */
/*   Updated: 2025/06/08 10:59:57 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_HEADER_H
# define EXECUTE_HEADER_H
# include "../struct.h"
# include "../builtins/builtins.h"
# include "../tools/tools.h"
# include <sys/types.h>
# include <signal.h>

void	dup_input_output(t_cmds **cmd, t_cmds *tmp);
int		check_is_builtins(t_cmds *cmd);
int		pipe_cammand(t_cmds **tmp);
int		open_files(t_cmds **cmds, t_env **env);
void	execute_builtins(t_cmds **cmd, t_env **env, int stat);
int		read_heredoc(t_cmds **cmd, t_env **env);
void	execute_command_line(t_cmds **cmd, t_env **env);
void	execute_builtins_inchild(t_cmds **cmd,
			t_env **env, int stat, t_cmds *tmp);
int		execute_builtins_inparent(t_cmds **cmd, t_env **env, int stat);
void	dub_for_cmds(t_cmds **cmd, t_env **env, t_cmds *tmp);
void	close_fds(t_cmds *tmp);
void	close_and_exit(int status, t_cmds **cmd);

#endif