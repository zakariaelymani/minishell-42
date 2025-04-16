/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:33:51 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/16 10:36:56 by zel-yama         ###   ########.fr       */
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



void    env_cmd(t_env *env);
void    export(t_env **env, char *input);
void    ft_exit(int status);
void	change_dir(char *new_path, t_env **env);
void    my_echo(char *op, char *string);
void	unset(t_env **env, char *vars);
t_env   *creat_env(char **env);
void    minishell_cmd(t_env **env);
void    my_pwd();

#endif