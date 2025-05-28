/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:05:27 by zel-yama          #+#    #+#             */
/*   Updated: 2025/05/28 10:45:51 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EXECUTE_HEADER_H
#define EXECUTE_HEADER_H

#include "../struct.h"
#include "../builtins/builtins.h"
#include "../tools/tools.h"

void    dup_input_output(t_cmds **cmd, t_cmds *tmp);//dup you dup in child and or parent acording to stats 
int		check_is_builtins(t_cmds *cmd);
void	pipe_cammand(t_cmds *tmp);
int		open_files(t_cmds **cmds, t_env **env);
void    excute_builtins(t_cmds **cmd, t_env **env, int stat);
int     read_heredoc(t_cmds **cmd, t_env **env);

void	excute_command_line(t_cmds **cmd, t_env **env);
void    excute_builtins_inchild(t_cmds **cmd, t_env **env, int stat, t_cmds *tmp);
int		excute_builtins_inparent(t_cmds **cmd, t_env **env, int stat);
void    dub_for_cmds(t_cmds **cmd, t_env **env, t_cmds *tmp);
void    close_fds(t_cmds *tmp);


#endif