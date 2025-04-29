/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-yama <zel-yama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:23:46 by zel-yama          #+#    #+#             */
/*   Updated: 2025/04/26 19:23:49 by zel-yama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

#include "../struct.h"
#include "../tools/tools.h"

void	env_cmd(t_env *env);
int		ft_exit(char *arguments[]);
void	export(t_env **env, char *input);
t_env	*creat_env(char **env);
void	change_dir(char **new_path, t_env **env);
void    my_echo(char *op, char *string, t_env **env);
void	my_pwd(t_env **env);
void	unset(t_env **env, char *vars);
int		check_name(char *splited);
void	export_without(t_env *env);

#endif